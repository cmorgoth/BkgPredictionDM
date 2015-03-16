/*
Plot Scales factor and W and Z prediction in all the categories
*/
//C++ INCLUDES
#include <iostream>
#include <fstream>
#include <vector>
//ROOT INCLUDES
#include "TROOT.h"
#include "TH1F.h"
#include "TFile.h"
#include "TH2F.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TColor.h"
#include "TPad.h"
#include "TStyle.h"
//LOCAL INCLUDES
#include "DM_1DRatio.hh"
#include "DM_2DRatio.hh"
#include "DM_Base.hh"


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
  
  const int ncat = 4;
  
  TFile* f = new TFile("PredFilesAN/MR_Cat_PredV2_NEW_kF_OriginalANA_TEST.root");
  //Getting Histograms
  TH1F* pred_z[ncat];
  TH1F* pred_z_from_2mu[ncat];
  TH1F* mc_z[ncat];
  
  TH1F* pred_w[ncat];
  TH1F* mc_w[ncat];
  
  TString h_name;
  for(int i = 0; i < ncat; i++){
    h_name = TString(Form("pred_Znunu_cat%d",i+1));
    pred_z[i] = (TH1F*)f->Get(h_name);
    h_name = TString(Form("pred_Znunu_from_2mu_cat%d",i+1));
    pred_z_from_2mu[i] = (TH1F*)f->Get(h_name);
    h_name = TString(Form("mc_Znunu_cat%d",i+1));
    mc_z[i] = (TH1F*)f->Get(h_name);
    
    h_name = TString(Form("pred_Wlnu_cat%d",i+1));
    pred_w[i] = (TH1F*)f->Get(h_name);
    h_name = TString(Form("mc_Wlnu_cat%d",i+1));
    mc_w[i] = (TH1F*)f->Get(h_name);   
  }//end getting histogram loops

  //Getting Scale Factors for Each Category
  TH1F* sf_1mu[ncat];
  TH1F* sf_2mu[ncat];
  TString sf_name;
  
  for(int i = 0; i < ncat; i++){
    sf_1mu[i] = new TH1F(*pred_w[i]);
    sf_1mu[i]->Divide(mc_w[i]);
    
    sf_2mu[i] = new TH1F(*pred_z_from_2mu[i]);
    sf_2mu[i]->Divide(mc_z[i]);
    
    sf_name = TString(Form("PlotsBkgPred/sf_1mu_cat%d",i+1));
    sf_1mu[i]->Draw();
    cc->SaveAs(sf_name+".pdf");
    cc->SaveAs(sf_name+".C");
    sf_name = TString(Form("PlotsBkgPred/sf_2mu_cat%d",i+1));
    sf_2mu[i]->Draw();
    cc->SaveAs(sf_name+".pdf");
    cc->SaveAs(sf_name+".C");
    sf_name = TString(Form("PlotsBkgPred/sfactors_cat%d",i+1));
    for(int j = 1; j <= sf_1mu[i]->GetNbinsX(); j++){
      sf_1mu[i]->SetBinError(j, 0.001*sf_1mu[i]->GetBinContent(j));
      sf_2mu[i]->SetBinError(j, 0.001*sf_2mu[i]->GetBinContent(j));
    }
    sf_1mu[i]->SetLineColor(kRed);
    sf_1mu[i]->SetTitle("");
    sf_1mu[i]->SetXTitle("R^{2}");
    sf_1mu[i]->SetYTitle("Scale Factor");
    sf_1mu[i]->GetYaxis()->SetTitleOffset(1.3);
    sf_1mu[i]->SetStats(0);
    sf_2mu[i]->SetStats(0);
    sf_2mu[i]->SetLineColor(kBlue);
    
    sf_1mu[i]->Draw();
    sf_1mu[i]->SetAxisRange(0.7, 1.3, "Y");
    sf_2mu[i]->Draw("same");

    TLegend* leg = new TLegend(0.75, 0.75, 0.89, 0.89);//(xmin, ymin, xmax, ymax)
    leg->AddEntry(sf_1mu[i], "W(lnu)/1#mu sf","lp");
    leg->AddEntry(sf_2mu[i], "Z(ll)/2#mu sf","lp");
    leg->SetTextSize(.022);
    leg->SetFillColor(0);
    leg->SetLineColor(0);
    leg->Draw();
    cc->SaveAs(sf_name+".pdf");
    cc->SaveAs(sf_name+".C");

    //Plot Z and W MC in the same canvas;
    mc_z[i]->SetLineColor(kBlue);
    mc_z[i]->SetLineWidth(2);
    mc_z[i]->SetTitle("");
    mc_z[i]->SetXTitle("R^{2}");
    mc_z[i]->SetStats(0); 
    mc_w[i]->SetLineColor(kRed);
    mc_w[i]->SetLineWidth(2);
    mc_w[i]->SetStats(0); 
    
    mc_z[i]->Draw();
    switch (i) 
      {
      case 0:
	mc_z[i]->SetAxisRange(0.0, 1000., "Y");
	break;
      case 1:
	mc_z[i]->SetAxisRange(0.0, 750., "Y");
	break;
      case 2:
	mc_z[i]->SetAxisRange(0.0, 400., "Y");
	break;
      case 3:
	mc_z[i]->SetAxisRange(0.0, 100., "Y");
	break;
      default:
	std::cout << "Undefined Category!";
      }
    mc_w[i]->Draw("same");
    
    delete leg;
    leg = new TLegend(0.7, 0.75, 0.89, 0.89);//(xmin, ymin, xmax, ymax)
    leg->AddEntry(mc_z[i], "MC Z(lnu)/0#mu","lp");
    leg->AddEntry(mc_w[i], "MC W(#nu#nu)/0#mu","lp");
    leg->SetTextSize(.022);
    leg->SetFillColor(0);
    leg->SetLineColor(0);
    leg->Draw();
    sf_name = TString(Form("PlotsBkgPred/ZandW_MC_cat%d",i+1));
    cc->SaveAs(sf_name+".pdf");
    cc->SaveAs(sf_name+".C");
    
  }
  
  //Getting histo to print bin by bin yields
  TH1F* data[4];
  TH1F* pred[4];
  //Creating Bin by Bin table of yields
  ofstream myfile;
  myfile.open ("TableFile/BinByBinYieldsTable.txt");
  for(int i = 0; i < ncat; i++){
    h_name = TString(Form("Data_cat%d_1D_0mu_Box",i+1));
    data[i] = (TH1F*)f->Get(h_name);
    h_name = TString(Form("cat%d_1D_0mu_Box_Pred_sys",i+1));
    pred[i] = (TH1F*)f->Get(h_name);
    if ( i == 0 )
      {
	myfile << "Observed & " << data[i]->GetBinContent(1) << " & " <<  data[i]->GetBinContent(2) << " & " <<
	  data[i]->GetBinContent(3) << " & " <<  data[i]->GetBinContent(4) << "\n";
	myfile << "Predicted" 
	       << " & " << pred[i]->GetBinContent(1) << "\\pm " << pred[i]->GetBinError(1) 
	       << " & " << pred[i]->GetBinContent(2) << "\\pm " << pred[i]->GetBinError(2) 
	       << " & " << pred[i]->GetBinContent(3) << "\\pm " << pred[i]->GetBinError(3) 
	       << " & " << pred[i]->GetBinContent(4) << "\\pm " << pred[i]->GetBinError(4) 
	       << "\n\n";
	
	
	myfile << "Observed & " << data[i]->GetBinContent(5) << " & " <<  data[i]->GetBinContent(6) << " & " <<
	  data[i]->GetBinContent(7) << " & " <<  data[i]->GetBinContent(8) << "\n";
	myfile << "Predicted" 
	       << " & " << pred[i]->GetBinContent(5) << "\\pm " << pred[i]->GetBinError(5)
	       << " & " << pred[i]->GetBinContent(6) << "\\pm " << pred[i]->GetBinError(6)
	       << " & " << pred[i]->GetBinContent(7) << "\\pm " << pred[i]->GetBinError(7) 
	       << " & " << pred[i]->GetBinContent(8) << "\\pm " << pred[i]->GetBinError(8)
	       << "\n\n";
	
	myfile << "Observed & " << data[i]->GetBinContent(9) << " & " <<  data[i]->GetBinContent(10) << " & " <<
	  data[i]->GetBinContent(11) << "\n";
	myfile << "Predicted"
	       << " & " << pred[i]->GetBinContent(9) << "\\pm " << pred[i]->GetBinError(9) 
	       << " & " << pred[i]->GetBinContent(10) << "\\pm " << pred[i]->GetBinError(10)
	       << " & " << pred[i]->GetBinContent(11) << "\\pm " << pred[i]->GetBinError(11)
	       << "\n\n";
      }//end Very Low Category
    else if ( i == 1 || i ==2 )
      {
	myfile << "===========\n\n";
	myfile << "Observed & " << data[i]->GetBinContent(1) << " & " <<  data[i]->GetBinContent(2) << " & " <<
	  data[i]->GetBinContent(3) << "\n";
	myfile << "Predicted" 
	       << " & " << pred[i]->GetBinContent(1) << "\\pm " << pred[i]->GetBinError(1) 
	       << " & " << pred[i]->GetBinContent(2) << "\\pm " << pred[i]->GetBinError(2) 
	       << " & " << pred[i]->GetBinContent(3) << "\\pm " << pred[i]->GetBinError(3) 
	       << "\n\n";
	
	
	myfile << "Observed & " << data[i]->GetBinContent(4) << " & " <<  data[i]->GetBinContent(5) << " & " <<
	  data[i]->GetBinContent(6) << "\n";
	myfile << "Predicted" 
	       << " & " << pred[i]->GetBinContent(4) << "\\pm " << pred[i]->GetBinError(4)
	       << " & " << pred[i]->GetBinContent(5) << "\\pm " << pred[i]->GetBinError(5)
	       << " & " << pred[i]->GetBinContent(6) << "\\pm " << pred[i]->GetBinError(6) 
	       << "\n\n";
	
      }//end Low  and High Category
    else if ( i == 3 )
      {
	myfile << "===========\n\n";
	myfile << "Observed & " << data[i]->GetBinContent(1) << " & " <<  data[i]->GetBinContent(2) << " & " <<
	  data[i]->GetBinContent(3) << " & " <<  data[i]->GetBinContent(4) << "\n";
	myfile << "Predicted" 
	       << " & " << pred[i]->GetBinContent(1) << "\\pm " << pred[i]->GetBinError(1) 
	       << " & " << pred[i]->GetBinContent(2) << "\\pm " << pred[i]->GetBinError(2) 
	       << " & " << pred[i]->GetBinContent(3) << "\\pm " << pred[i]->GetBinError(3) 
	       << " & " << pred[i]->GetBinContent(4) << "\\pm " << pred[i]->GetBinError(4) 
	       << "\n\n";
      }//end Very High Category
    
  }//end 0mu signal region table

  myfile.close();
  
  //Load b boxes histograms
  TFile* fb = new TFile("~/Software/git/BkgPred-Btag/test_CP_1TB_ptReweighting.root");
  TH1F* data_b = (TH1F*)fb->Get("data0mu");
  TH1F* pred_b = (TH1F*)fb->Get("Pred0mu_SYS");
  //Load bb boxes histograms
  TFile* fbb = new TFile("~/Software/git/BkgPred-Btag/test_CP_2TB_ptReweighting.root");
  TH1F* data_bb = (TH1F*)fbb->Get("data0mu");
  TH1F* pred_bb = (TH1F*)fbb->Get("Pred0mu_SYS");
  
  //b file
  myfile.open ("TableFile/BinByBinYieldsTable_1B.txt");
  myfile << "Observed & " << data_b->GetBinContent(1) << " & " <<  data_b->GetBinContent(2) << " & " <<
    data_b->GetBinContent(3) << " & " <<  data_b->GetBinContent(4) << "\n";
  myfile << "Predicted" 
	 << " & " << pred_b->GetBinContent(1) << "\\pm " << pred_b->GetBinError(1) 
	 << " & " << pred_b->GetBinContent(2) << "\\pm " << pred_b->GetBinError(2) 
	 << " & " << pred_b->GetBinContent(3) << "\\pm " << pred_b->GetBinError(3) 
	 << " & " << pred_b->GetBinContent(4) << "\\pm " << pred_b->GetBinError(4)
	 << "\n";
  myfile.close();
  
  //bb file
  myfile.open ("TableFile/BinByBinYieldsTable_2B.txt");
  myfile << "Observed & " << data_bb->GetBinContent(1) << " & " <<  data_bb->GetBinContent(2) << " & " <<
    data_bb->GetBinContent(3) << " & " <<  data_bb->GetBinContent(4) << "\n";
  myfile << "Predicted" 
	 << " & " << pred_bb->GetBinContent(1) << "\\pm " << pred_bb->GetBinError(1) 
	 << " & " << pred_bb->GetBinContent(2) << "\\pm " << pred_bb->GetBinError(2) 
	 << " & " << pred_bb->GetBinContent(3) << "\\pm " << pred_bb->GetBinError(3) 
	 << " & " << pred_bb->GetBinContent(4) << "\\pm " << pred_bb->GetBinError(4)
	 << "\n";
  myfile.close();
  

  return 0;
}
