#include <iostream>
#include <fstream>
#include "TROOT.h"
#include "TH1F.h"
#include "TFile.h"
#include "TH2F.h"
#include "DM_1DRatio.hh"
#include "DM_2DRatio.hh"
#include "DM_Base.hh"
#include "TCanvas.h"
#include "TStyle.h"
#include "TColor.h"
#include "TPad.h"
#include <vector>
#include "TGraph.h"
#include "TGraphAsymmErrors.h"
const int r2Bins = 5;
const float BaseDM::RSQ_BinArr[] = {0.5, 0.6, 0.725, 0.85,  2.50};
const float BaseDM::MR_BinArr[] = {200., 300., 400., 600.,  3500.};

//MR Categories
const int r2B[4] = {11, 6, 6, 4};
float c1B[] = {0.50, 0.55, 0.60, 0.65, 0.70, 0.75, 0.80, 0.85, 0.9, 0.95, 1.0, 1.2};
float c2B[] = {0.50, 0.575, 0.65, 0.75, 0.85, .950, 1.2};
float c3B[] = {0.50, 0.575, 0.65, 0.75, 0.85, .950, 1.2};
float c4B[] = {0.50, 0.60, 0.70, .950, 1.2};

const int r2B_tt[4] = {7, 4, 4, 4};
float c1B_tt[] = {0.50, 0.55, 0.60, 0.65, 0.70, 0.75, 0.80, 1.2};
float c2B_tt[] = {0.50, 0.575, 0.65, 0.75, 1.2};
float c3B_tt[] = {0.50, 0.575, 0.65, 0.75, 1.2};
float c4B_tt[] = {0.50, 0.575, 0.65, 0.75, 1.2};

std::vector<float*> v;
std::vector<float*> v_tt;

void set_plot_style(){
  const int NRGBs = 5;
  const int NCont = 255;
  
  double stops[NRGBs] = { 0.00, 0.25, 0.50, 0.75, 1.00 };
  double red[NRGBs]   = { 0.50, 0.70, 1.00, 1.00, 1.00 };
  double green[NRGBs] = { 0.50, 0.70, 1.00, 0.70, 0.50 };
  double blue[NRGBs]  = { 1.00, 1.00, 1.00, 0.70, 0.50 };
  TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
  gStyle->SetNumberContours(NCont);
}

int main(){
  gROOT->Reset();

  set_plot_style();
  TCanvas* cc = new TCanvas("cc", "cc", 640, 640);
  int ncat = 4;
  //Initialize arrays
  v.push_back(c1B);
  v.push_back(c2B);
  v.push_back(c3B);
  v.push_back(c4B);
  
  v_tt.push_back(c1B_tt);
  v_tt.push_back(c2B_tt);
  v_tt.push_back(c3B_tt);
  v_tt.push_back(c4B_tt);
  
  
  TH1F* nom[ncat];//one for category
  TFile* f1 = new TFile("~/Software/git/BkgPredictionDM/Pred_Files/MR_Cat_PredV2_Nominal.root");
  TString n1;
  for(int i = 0; i < ncat; i++){
    n1 = TString(Form("cat%d_1D_0mu_Box_Pred_sys",i+1));
    nom[i] = (TH1F*)f1->Get(n1);
  }
  
  
  TH1F* isr_up[4];
  //TFile* f2 = new TFile("~/Software/git/BkgPredictionDM/Pred_Files/MR_Cat_PredV2_JES_UP.root");
  //TFile* f2 = new TFile("~/Software/git/BkgPredictionDM/Pred_Files/MR_Cat_PredV2_ISR_UP.root");
  //TFile* f2 = new TFile("~/Software/git/BkgPredictionDM/Pred_Files/MR_Cat_PredV2_bTag_Up.root");
  TFile* f2 = new TFile("~/Software/git/BkgPredictionDM/Pred_Files/MR_Cat_PredV2_Mu_Up.root");
  
  for(int i = 0; i < ncat; i++){
    n1 = TString(Form("cat%d_1D_0mu_Box_Pred_sys",i+1));
    isr_up[i] = (TH1F*)f2->Get(n1);
  }

  TH1F* isr_down[4];
  //TFile* f3 = new TFile("~/Software/git/BkgPredictionDM/Pred_Files/MR_Cat_PredV2_JES_DOWN.root");
  //TFile* f3 = new TFile("~/Software/git/BkgPredictionDM/Pred_Files/MR_Cat_PredV2_ISR_DOWN.root");
  //TFile* f3 = new TFile("~/Software/git/BkgPredictionDM/Pred_Files/MR_Cat_PredV2_bTag_Down.root");
  TFile* f3 = new TFile("~/Software/git/BkgPredictionDM/Pred_Files/MR_Cat_PredV2_Mu_Down.root");
  for(int i = 0; i < ncat; i++){
    n1 = TString(Form("cat%d_1D_0mu_Box_Pred_sys",i+1));
    isr_down[i] = (TH1F*)f3->Get(n1);
  }
  //std::cout << "debug 1" << std::endl;
  
  TGraph* sys_tg[4];
  for(int i = 0; i < ncat; i++){
    sys_tg[i] = new TGraph(2*r2B[i]);
    for(int j = 0; j < nom[i]->GetNbinsX(); j++){
      sys_tg[i]->SetPoint(j,(*(v.at(i)+j) + *(v.at(i)+j+1))/2.0, isr_up[i]->GetBinContent(j+1));
      sys_tg[i]->SetPoint(r2B[i]+j,(*(v.at(i)+r2B[i]-j-1) + *(v.at(i)+r2B[i]-j))/2.0, nom[i]->GetBinContent(r2B[i]-j));
      
      std::cout << "bin1: " << (*(v.at(i)+j+1)+*(v.at(i)+j))/2.0 << " c1: " << isr_up[i]->GetBinContent(j+1) << " bin2: " << (*(v.at(i)+r2B[i]-j) + *(v.at(i)+r2B[i]-j-1))/2.0 << " c2: " <<  nom[i]->GetBinContent(r2B[i]-j) << std::endl;
    }
    std::cout << "=======================" << std::endl;
  }
  
  TGraphAsymmErrors* AsyE[4];

  std::vector<double*> sys_gr_x;
  std::vector<double*> sys_gr_y;
  std::vector<double*> sys_gr_exl;
  std::vector<double*> sys_gr_exh;
  std::vector<double*> sys_gr_eyl;
  std::vector<double*> sys_gr_eyh;
  
  double x[r2B[0]], x1[r2B[1]], x2[r2B[2]], x3[r2B[3]];
  double y[r2B[0]], y1[r2B[1]], y2[r2B[2]], y3[r2B[3]];
  double exl[r2B[0]], exl1[r2B[1]], exl2[r2B[2]], exl3[r2B[3]];
  double eyl[r2B[0]], eyl1[r2B[1]], eyl2[r2B[2]], eyl3[r2B[3]];
  double exh[r2B[0]], exh1[r2B[1]], exh2[r2B[2]], exh3[r2B[3]];
  double eyh[r2B[0]], eyh1[r2B[1]], eyh2[r2B[2]], eyh3[r2B[3]];
  std::cout << "===deb 0==" << std::endl;
  sys_gr_x.push_back(x);
  sys_gr_x.push_back(x1);
  sys_gr_x.push_back(x2);
  sys_gr_x.push_back(x3);
  
  sys_gr_y.push_back(y);
  sys_gr_y.push_back(y1);
  sys_gr_y.push_back(y2);
  sys_gr_y.push_back(y3);

  sys_gr_exl.push_back(exl);
  sys_gr_exl.push_back(exl1);
  sys_gr_exl.push_back(exl2);
  sys_gr_exl.push_back(exl3);

  sys_gr_eyl.push_back(eyl);
  sys_gr_eyl.push_back(eyl1);
  sys_gr_eyl.push_back(eyl2);
  sys_gr_eyl.push_back(eyl3);

  sys_gr_exh.push_back(exh);
  sys_gr_exh.push_back(exh1);
  sys_gr_exh.push_back(exh2);
  sys_gr_exh.push_back(exh3);
  
  sys_gr_eyh.push_back(eyh);
  sys_gr_eyh.push_back(eyh1);
  sys_gr_eyh.push_back(eyh2);
  sys_gr_eyh.push_back(eyh3);
  
  std::cout << "size: " << sys_gr_x.size() << std::endl;
  std::cout << "size: " << sys_gr_y.size() << std::endl;
  std::cout << "size: " << sys_gr_exl.size() << std::endl;
  std::cout << "size: " << sys_gr_exh.size() << std::endl;
  std::cout << "size: " << sys_gr_eyl.size() << std::endl;
  std::cout << "size: " << sys_gr_eyh.size() << std::endl;

  for(int l = 0; l < ncat; l++){
    for(int k = 0; k < r2B[l]; k++){
      std::cout << "i: " << k << std::endl;
      *(sys_gr_y.at(l)+k) = (isr_up[l]->GetBinContent(k+1) + isr_down[l]->GetBinContent(k+1))/2.0;
      *(sys_gr_x.at(l)+k) = (*(v.at(l)+k+1)+*(v.at(l)+k))/2.;
      *(sys_gr_exl.at(l)+k) = (*(v.at(l)+k+1)-*(v.at(l)+k))/2.;
      *(sys_gr_exh.at(l)+k) = (*(v.at(l)+k+1)-*(v.at(l)+k))/2.;
      *(sys_gr_eyh.at(l)+k) = 1.0*fabs((isr_up[l]->GetBinContent(k+1) - isr_down[l]->GetBinContent(k+1))/2.0);
      *(sys_gr_eyl.at(l)+k) = 1.0*fabs((isr_up[l]->GetBinContent(k+1) - isr_down[l]->GetBinContent(k+1))/2.0);
    }
    AsyE[l] = new TGraphAsymmErrors(r2B[l],sys_gr_x.at(l),sys_gr_y.at(l), sys_gr_exl.at(l), sys_gr_exh.at(l), sys_gr_eyl.at(l), sys_gr_eyh.at(l));
  }
  
  
  std::cout << "===deb 1==" << std::endl;
  
  
  //sys_tg[2]->SetFillStyle(3013);
  //sys_tg[2]->SetFillColor(kBlue-10);
  //sys_tg[2]->SetTitle("");
  //sys_tg[2]->Draw("af*");
  //cc->SetLogy();
  //nom[3]->Draw("same");
  //AsyE[0]->Draw("AB1");
  TString plotname;
  for(int l = 0; l < ncat; l++){
    plotname = TString(Form("SYS_Plots/cat%d_MuEff",l+1));
    BandMC_TGraph(AsyE[l] , nom[l], "MuEff Syst.", "Bkg Pred. Nominal", plotname, "RSQ", r2B[l], v.at(l),0);
  }
  AsyE[0]->SetFillColor(2);
  AsyE[0]->SetFillStyle(3001);
  AsyE[0]->Draw("a2same");
  nom[0]->Draw("same");
  //AsyE[0]->Draw("");
  
  //cc->SaveAs("SYS_Plots/TTTTEST.pdf");
  
  /*
    for(int i = 0; i < ncat; i++){
    //nom[i]->Draw();
    plotname = TString(Form("SYS_Plots/cat%d_Mu_down",i+1));
    RatioPlotsBandMC( isr_up[i], nom[i], "Bkg Pred. Mu down", "Bkg Pred. Nominal", plotname, "RSQ", r2B[i], v.at(i),0);
    //cc->SaveAs("SYS_Plots/"+plotname+".pdf");
    }
  */
  return 0;
}
