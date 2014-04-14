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




const int r2Bins = 5;
const float BaseDM::RSQ_BinArr[] = {0.5, 0.6, 0.725, 0.85,  2.50};
const float BaseDM::MR_BinArr[] = {200., 300., 400., 600.,  3500.};

//MR Categories
const int r2B[4] = {11, 6, 6, 4};
float c1B[] = {0.50, 0.55, 0.60, 0.65, 0.70, 0.75, 0.80, 0.85, 0.9, 0.95, 1.0, 1.2};
float c2B[] = {0.50, 0.575, 0.65, 0.75, 0.85, .950, 1.2};
float c3B[] = {0.50, 0.575, 0.65, 0.75, 0.85, .950, 1.2};
float c4B[] = {0.50, 0.60, 0.70, .950, 1.2};

std::vector<float*> v;


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
  TFile* F = new TFile("FinalROOTFiles/TwoTightBtagCorr_MRcategories.root");
  
  v.push_back(c1B);
  v.push_back(c2B);
  v.push_back(c3B);
  v.push_back(c4B);
  
  ///////////////////////////////////////////////////////
  ///////////////Creating MR categories binned in R2/////
  //////////////////////////////////////////////////////
  TH1F* dy[12];
  TH1F* z[12];
  TH1F* w[12];
  TH1F* tt[12];
  TH1F* data[12];
  
  double tt_k2factor = 1.8034;
  double z_k2factor = 1.1973;
  double w_k2factor = 1.2455;
  
  for(int i = 0; i < 3; i++){
    for(int j = 1; j <= 4; j++){
      TString name1 = TString(Form("DY_cat%d_1D_%dmu_Box",j,i));
      dy[4*i+j-1] = (TH1F*)F->Get(name1);
      dy[4*i+j-1]->Scale(z_k2factor);
      TString name2 = TString(Form("Z_cat%d_1D_%dmu_Box",j,i));
      z[4*i+j-1] = (TH1F*)F->Get(name2);
      z[4*i+j-1]->Scale(z_k2factor);
      TString name3 = TString(Form("W_cat%d_1D_%dmu_Box",j,i));
      w[4*i+j-1] = (TH1F*)F->Get(name3);
      w[4*i+j-1]->Scale(w_k2factor);
      TString name4 = TString(Form("TT_cat%d_1D_%dmu_Box",j,i));
      tt[4*i+j-1] = (TH1F*)F->Get(name4);
      tt[4*i+j-1]->Scale(tt_k2factor);
      TString name5 = TString(Form("Data_cat%d_1D_%dmu_Box",j,i));
      data[4*i+j-1] = (TH1F*)F->Get(name5);
      
    }
  }
  
      
  TH1F* dy_ne[12];
  TH1F* z_ne[12];
  TH1F* w_ne[12];
  TH1F* tt_ne[12];
  
  for(int i = 0; i < 12; i++){
    TString s(Form("dy_ne_%d",i));
    dy_ne[i] = new TH1F(s,s,r2B[i%4], v.at(i%4));
    s = Form("tt_ne_%d",i);
    tt_ne[i] = new TH1F(s,s,r2B[i%4], v.at(i%4));
    s = Form("w_ne_%d",i);
    w_ne[i] = new TH1F(s,s,r2B[i%4], v.at(i%4));
    s = Form("z_ne_%d",i);
    z_ne[i] = new TH1F(s,s,r2B[i%4], v.at(i%4));
    for(int j = 1; j <= dy[i]->GetNbinsX(); j++){
      dy_ne[i]->SetBinContent(j,dy[i]->GetBinContent(j));
      tt_ne[i]->SetBinContent(j,tt[i]->GetBinContent(j));
      w_ne[i]->SetBinContent(j,w[i]->GetBinContent(j));
      z_ne[i]->SetBinContent(j,z[i]->GetBinContent(j));
    }
  }
  
  //MC Zero and One Muon Total Histograms and StackPlot
  TH1F* t_mc[4];//Zero Muon Total
  TH1F* t_mc_1mu[4];//One Muon Total
  THStack* t_s_0mu[4];//Stack Zero Muon
  THStack* t_s_1mu[4];//Stack One Muon
  TLegend* leg[4];//Stack One Muon Legend
  TLegend* leg_nm[4];//Stack Zero Muon Legend
  for(int i = 0; i < 4; i++){
    TString s(Form("t_mc_1mu_cat%d",i+1)); 
    //One Muon
    t_mc_1mu[i] = new TH1F(s,s, r2B[i], v.at(i));
    t_s_1mu[i] = new THStack(s+"_stack", s+"_stack");
    
    t_mc_1mu[i] = tt[i+4];
    t_mc_1mu[i]->Add(dy[i+4]);
    t_mc_1mu[i]->Add(z[i+4]);
    t_mc_1mu[i]->Add(w[i+4]);
    //Cosmetics
    tt_ne[i+4]->SetFillColor(kPink+9);
    dy_ne[i+4]->SetFillColor(kViolet+9);
    w_ne[i+4]->SetFillColor(kSpring+4);
    z_ne[i+4]->SetFillColor(kYellow-4);
    //Creating StackPlot
    t_s_1mu[i]->Add(dy_ne[i+4]);
    t_s_1mu[i]->Add(z_ne[i+4]);
    t_s_1mu[i]->Add(w_ne[i+4]);
    t_s_1mu[i]->Add(tt_ne[i+4]);
    //Legend StackPlot
    leg[i] = new TLegend(0.7,0.7,0.9,0.92);
    leg[i]->AddEntry(w_ne[i+4],"W + jets","f");
    leg[i]->AddEntry(z_ne[i+4],"Z(#nu#bar{#nu}) + jets","f");
    leg[i]->AddEntry(tt_ne[i+4],"t #bar{t} + jets","f");
    leg[i]->AddEntry(dy_ne[i+4],"Z/#gamma^{*}(ll) + jets","f");
    leg[i]->AddEntry(data[i+4],"Data","lep");
    
    //Zero Muon
    s = Form("t_mc_0mu_cat%d",i+1);
    t_s_0mu[i] = new THStack(s+"_stack", s+"_stack");
    //Creating Summed Histogram Bkg
    t_mc[i] = new TH1F(s,s, r2B[i], v.at(i));
    t_mc[i] = tt[i];
    t_mc[i]->Add(dy[i]);
    t_mc[i]->Add(z[i]);
    t_mc[i]->Add(w[i]);
    //Cosmetics
    tt_ne[i]->SetFillColor(kPink+9);
    dy_ne[i]->SetFillColor(kViolet+9);
    w_ne[i]->SetFillColor(kSpring+4);
    z_ne[i]->SetFillColor(kYellow-4);
    //Creating StackPlot
    t_s_0mu[i]->Add(dy_ne[i]);
    t_s_0mu[i]->Add(z_ne[i]);
    t_s_0mu[i]->Add(w_ne[i]);
    t_s_0mu[i]->Add(tt_ne[i]);
    //Legend StackPlot
    leg_nm[i] = new TLegend(0.7,0.7,0.9,0.92);
    leg_nm[i]->AddEntry(w_ne[i],"W + jets","f");
    leg_nm[i]->AddEntry(z_ne[i],"Z(#nu#bar{#nu}) + jets","f");
    leg_nm[i]->AddEntry(tt_ne[i],"t #bar{t} + jets","f");
    leg_nm[i]->AddEntry(dy_ne[i],"Z/#gamma^{*}(ll) + jets","f");
    leg_nm[i]->AddEntry(data[i],"Data","lep");
  }
  
  
  TFile* f1 = new TFile("Pred_Files/Two_TT_Cat_PredV2.root","RECREATE");
  TString n, n1, ex_s;
  for(int i = 0; i < 4; i++){
    n = TString(Form("cat%d_1D_1mu_Box_Pred",i+1));
    n1 = TString(Form("cat%d_1D_0mu_Box_Pred",i+1));
    ex_s = TString(Form("cat%d",i+1));
    
    RatioPlotsBandV2( data[i], t_mc[i], "Data  0-#mu BOX", "BKg Pred 0-#mu BOX", "PredPlots/Two_TT_0mu_MC_Pred_V2"+ex_s, "RSQ", r2B[i], v.at(i));
    RatioPlotsBandV2( data[4+i], t_mc_1mu[i], "Data  1-#mu BOX", "BKg Pred 1-#mu BOX", "PredPlots/Two_TT_1mu_MC_Pred_V2"+ex_s, "RSQ", r2B[i], v.at(i));
    RatioPlotsV2(t_s_1mu[i], data[i+4], t_mc_1mu[i], "Data  1-#mu BOX", "BKg Pred 1-#mu BOX", "PredPlots/Stack_Two_TT_1mu_MC_Pred_V2"+ex_s, "RSQ", r2B[i], v.at(i), leg[i]);
    RatioPlotsV2(t_s_0mu[i], data[i], t_mc[i], "Data  0-#mu BOX", "BKg Pred 0-#mu BOX", "PredPlots/Stack_Two_TT_0mu_MC_Pred_V2"+ex_s, "RSQ", r2B[i], v.at(i), leg[i]);

    data[i]->Write();
    t_mc[i]->Write();
   
  }
  f1->Close();
 
  
  return 0;

}
