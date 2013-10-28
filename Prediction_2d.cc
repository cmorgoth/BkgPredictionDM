#include <iostream>
#include <fstream>
#include "TFile.h"
#include "TH2F.h"
#include "TH1F.h"
#include "TROOT.h"
#include "TCanvas.h"
#include "TLatex.h"
#include "TRandom3.h"
#include "TMath.h"
#include "TColor.h"
#include "TStyle.h"

int main(){
  
  gROOT->Reset();
  TFile* f = new TFile("Pred_Files/BkgPred_FullData_BtagCorr.root");
  TH2F* Pred2D = (TH2F*)f->Get("BkgPred_2d");
  TH2F* Data2D = (TH2F*)f->Get("Data_2d");

  TCanvas* c = new TCanvas("c","c", 1240, 764);
  c->Divide(2);
  c->cd(1);
  Pred2D->SetStats(0);
  Pred2D->SetTitle("");
  Pred2D->SetMaximum(8.0*1e3);
  Pred2D->SetXTitle("M_{R}");
  Pred2D->SetYTitle("R^{2}");
  gPad->SetLogy();
  gPad->SetLogx();
  Pred2D->Draw("colz");
  
  float binV, binErr, Xpos, Ypos;
  TLatex* Lval;
  //TLatex* Lerr;
  char val[50];
  char err[50];
  binV = 666.;
  
  for(int i = 1; i <= Pred2D->GetNbinsX(); i++){
    for(int j = 1; j <= Pred2D->GetNbinsY(); j++){	
      binV =  Pred2D->GetBinContent(i,j);
      binErr = Pred2D->GetBinError(i,j);
      
      Xpos =  Pred2D->GetXaxis()->GetBinCenter(i);
      Ypos =  Pred2D->GetYaxis()->GetBinCenter(j);
      
      sprintf(val,"%.2f", binV);
      sprintf(err," \\pm %.2f", binErr);
      
      if( (binV != 0) || ( binErr != 0) ){
	Lval = new TLatex(Xpos-70,Ypos+0.01, "HELLO!!!" );
	Lval->SetTextSize(.025);
	Lval->DrawLatex(Xpos -50,Ypos+0.02, val );
	Lval->DrawLatex(Xpos -50 ,Ypos-0.043, err );
	
	delete Lval;
	
      }
    }
  }
  
  c->cd(2);
  gPad->SetLogy();
  gPad->SetLogx();
  Data2D->SetStats(0);
  Data2D->SetTitle("");
  Data2D->SetMaximum(8.0*1e3);
  Data2D->Draw("colztext");
  c->SaveAs("pred_text_DataMC_LO_Dphi_FullData_BtagCorr.pdf");
  c->SaveAs("pred_text_DataMC_LO_Dphi_FullData_BtagCorr.png");
 
  
  
  TH1F* h[16]; 
  double p_val[16], n_sigma[16];
  int ctr = 0;
  int n_toys = 1e8;
  for(int i = 1; i <= Pred2D->GetNbinsX(); i++){
    for(int j = 1; j <= Pred2D->GetNbinsY(); j++){	
      
      double mean =  Pred2D->GetBinContent(i,j);
      double sigma = Pred2D->GetBinError(i,j);
      
      double obs = Data2D->GetBinContent(i,j);
      
      h[(j-1)+(i-1)*4] = new TH1F("h","h", 1000, mean-1000, mean+1000);
      
      TRandom3 r1(0);
      TRandom3 r2(0);
      for(int t = 0; t < n_toys; t++){
	double Lambda = r1.Gaus(mean, sigma);
	double pois = r2.Poisson(Lambda);
	h[(j-1)+(i-1)*4]->Fill(pois);
      }
      
      int bin = h[(j-1)+(i-1)*4]->FindBin(obs);
      std::cout << "bin: " << bin << std::endl;
      double pval = h[(j-1)+(i-1)*4]->Integral(bin,1000);
      pval = (double)pval/n_toys;
      std::cout << "p-value: " << pval << " nSigma: " << sqrt(2)*TMath::ErfInverse(2*(0.5-pval)) << std::endl;
      n_sigma[(j-1)+(i-1)*4] = sqrt(2)*TMath::ErfInverse(2*(0.5-pval));
      p_val[(j-1)+(i-1)*4] = pval;
      ctr++;
    }
  }

  gPad->SetLogy(0);
  gPad->SetLogx(0);
  c->cd(1);
  h[0]->Draw();
  gPad->SetLogy(0);
  gPad->SetLogx(0);
  c->cd(2);
  h[1]->Draw();

  const float RSQ_BinArr[] = {0.5, 0.65, 0.8, 1.0, 2.50};                                                     
  const float MR_BinArr[] = {200., 400., 600., 800., 3500.};
  const int NRGBs = 7;
  const int NCont = 999;
  
  double stops[NRGBs] = { 0.00, 0.20, 0.35, 0.50, 0.65, 0.8, 1.00 };
  double red[NRGBs]   = { 0.00, 0.70, 0.90, 1.00, 1.00, 1.00, 1.00 };
  double green[NRGBs] = { 0.00, 0.70, 0.90, 1.00, 0.90, 0.70, 0.00 };
  double blue[NRGBs]  = { 1.00, 1.00, 1.00, 1.00, 0.90, 0.70, 0.00 };
  TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
  gStyle->SetNumberContours(NCont);

  TH2F* flag = new TH2F("flag", "flag", 4, MR_BinArr, 4, RSQ_BinArr);
  
  for(int i = 1; i <= 4; i++){
    for(int j = 1; j <= 4; j++){
      int bin = flag->GetBin(i,j);
      flag->SetBinContent(bin,n_sigma[(j-1)+(i-1)*4]);
    }
  }
  
  TCanvas* c1 = new TCanvas("c1","c1", 760, 760);
  gPad->SetLogy();
  gPad->SetLogx();
  flag->SetStats(0);
  flag->SetXTitle("M_{R}");
  flag->SetYTitle("R^{2}");
  flag->SetTitle("");
  flag->SetMaximum(5.0);
  flag->SetMinimum(-5.0);
  flag->Draw("colz");
  
  
  for(int i = 1; i <= flag->GetNbinsX(); i++){
    for(int j = 1; j <= flag->GetNbinsY(); j++){	
      binV =  flag->GetBinContent(i,j);
      binErr = flag->GetBinError(i,j);
      
      Xpos =  flag->GetXaxis()->GetBinCenter(i);
      Ypos =  flag->GetYaxis()->GetBinCenter(j);
      
      sprintf(val,"%.1f", binV);
      sprintf(err," \\pm %.2f", binErr);
      
      if( (binV != 0) || ( binErr != 0) ){
	Lval = new TLatex(Xpos+10,Ypos, "HELLO!!!" );
	Lval->SetTextSize(.025);
	Lval->DrawLatex(Xpos -50,Ypos+0.02, val );
	delete Lval;
	
      }
    }
  }
  
  c1->SaveAs("french_flag_DM_LO_Dphi_FullData_BtagCorr.pdf");
  c1->SaveAs("french_flag_DM_LO_Dphi_FullData_BtagCorr.pdf");
  
  return 0;
  
}
