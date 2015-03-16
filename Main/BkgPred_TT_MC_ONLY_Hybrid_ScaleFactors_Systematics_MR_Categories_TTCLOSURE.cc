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
/*
const int r2B[4] = {11, 6, 6, 4};
float c1B[] = {0.50, 0.55, 0.60, 0.65, 0.70, 0.75, 0.80, 0.85, 0.9, 0.95, 1.0, 1.2};
float c2B[] = {0.50, 0.575, 0.65, 0.75, 0.85, .950, 1.2};
float c3B[] = {0.50, 0.575, 0.65, 0.75, 0.85, .950, 1.2};
float c4B[] = {0.50, 0.60, 0.70, .950, 1.2};
*/
const int r2B[4] = {7, 4, 4, 4};
float c1B[] = {0.50, 0.55, 0.60, 0.65, 0.70, 0.75, 0.80, 1.2};
float c2B[] = {0.50, 0.575, 0.65, 0.75, 1.2};
float c3B[] = {0.50, 0.575, 0.65, 0.75, 1.2};
float c4B[] = {0.50, 0.575, 0.65, 0.75, 1.2};

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
  //TFile* F = new TFile("FinalROOTFiles/TwoTightBtagCorr_MRcategories.root");
  //TFile* F = new TFile("FinalROOT_May2014/TwoBtag_May_2014.root");
  TFile* F = new TFile("FinalROOTFiles/TwoBtag_Tight_May_2014_NewTriger_AN.root");
  
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
      TString name4 = TString(Form("TT_L_cat%d_1D_%dmu_Box",j,i));
      tt[4*i+j-1] = (TH1F*)F->Get(name4);
      tt[4*i+j-1]->Scale(tt_k2factor);
      TString name5 = TString(Form("Data_cat%d_1D_%dmu_Box",j,i));
      data[4*i+j-1] = (TH1F*)F->Get(name5);
      
    }
  }
  
  TH1F* t_MC[12];
  for(int j = 0; j < 12; j++){
    t_MC[j] = new TH1F(*tt[j]);
    t_MC[j]->Add(dy[j]);
    t_MC[j]->Add(z[j]);
    t_MC[j]->Add(w[j], 1.0);
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
    //t_mc_1mu[i] = new TH1F(s,s, r2B[i], v.at(i));
    t_s_1mu[i] = new THStack(s+"_stack", s+"_stack");
    //t_mc_1mu[i] = tt[i+4];
    t_mc_1mu[i] = new TH1F(*tt[i+4]);
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
    //t_mc[i] = new TH1F(s,s, r2B[i], v.at(i));
    t_mc[i] = new TH1F(*tt[i]);
    //t_mc[i] = tt[i];
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
  
 

  /*
  for(int i = 0; i < 4; i++){
    std::cout << "==== Cat " << i+1 << "====" << std::endl;
    std::cout << t_MC[i]->Integral()-t_mc[i]->Integral() << "  " << t_MC[i]->Integral()
	      << " " << t_mc[i]->Integral() << std::endl;
    std::cout << t_MC[i+4]->Integral()-t_mc_1mu[i]->Integral() << "  " << t_MC[i+4]->Integral()
	      << " " << t_mc_1mu[i]->Integral() << std::endl;
  }
  */

 
  //Print Out Prediction in different cat after systematics
  double Nerr[7] = {-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0};
  double Nbkg[7] = {-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0};
  TString catN[4] = {"VL","L","H","VH"};
  std::cout << "==== 0-mu ====" << std::endl;
  for(int i = 0; i < 4; i++){
    //std::cout << "==== Cat " << i+1 << " ====" << std::endl;
    Nbkg[0] = z[i]->IntegralAndError(1,z[i]->GetNbinsX(),Nerr[0],"");
    Nbkg[1] = w[i]->IntegralAndError(1,w[i]->GetNbinsX(),Nerr[1],"");
    Nbkg[2] = dy[i]->IntegralAndError(1,dy[i]->GetNbinsX(),Nerr[2],"");
    Nbkg[3] = tt[i]->IntegralAndError(1,tt[i]->GetNbinsX(),Nerr[3],"");
    Nbkg[4] = t_mc[i]->IntegralAndError(1,t_mc[i]->GetNbinsX(),Nerr[4],"");
    Nbkg[5] = data[i]->IntegralAndError(1,data[i]->GetNbinsX(),Nerr[5],"");
    
    std::cout << catN[i] << " & " << Nbkg[0] << "\\pm" << Nerr[0] <<
      " & " << Nbkg[1] << "\\pm" << Nerr[1] <<
      " & " << Nbkg[2] << "\\pm" << Nerr[2] <<
      " & " << Nbkg[3] << "\\pm" << Nerr[3] <<
      " & " << Nbkg[4] << "\\pm" << Nerr[4] <<
      " & " << Nbkg[5] << " \\\\"<< std::endl;
    
  }
  
   std::cout << "==== 1-mu ====" << std::endl;
  for(int i = 0; i < 4; i++){
    //std::cout << "==== Cat " << i+1 << " ====" << std::endl;
    Nbkg[0] = z[i+4]->IntegralAndError(1,z[i+4]->GetNbinsX(),Nerr[0],"");
    Nbkg[1] = w[i+4]->IntegralAndError(1,w[i+4]->GetNbinsX(),Nerr[1],"");
    Nbkg[2] = dy[i+4]->IntegralAndError(1,dy[i+4]->GetNbinsX(),Nerr[2],"");
    Nbkg[3] = tt[i+4]->IntegralAndError(1,tt[i+4]->GetNbinsX(),Nerr[3],"");
    Nbkg[4] = t_mc_1mu[i]->IntegralAndError(1,t_mc_1mu[i+4]->GetNbinsX(),Nerr[4],"");
    Nbkg[5] = data[i+4]->IntegralAndError(1,data[i+4]->GetNbinsX(),Nerr[5],"");
    
    std::cout << catN[i] << " & " << Nbkg[0] << "\\pm" << Nerr[0] <<
      " & " << Nbkg[1] << "\\pm" << Nerr[1] <<
      " & " << Nbkg[2] << "\\pm" << Nerr[2] <<
      " & " << Nbkg[3] << "\\pm" << Nerr[3] <<
      " & " << Nbkg[4] << "\\pm" << Nerr[4] <<
      " & " << Nbkg[5] << " \\\\"<< std::endl;
  }
  
  //Preparing k_factors and Systematics
  t_mc[2]->Add(t_mc[3]);//Adding 3rd and 4th category
  t_mc_1mu[2]->Add(t_mc_1mu[3]);//Adding 3rd and 4th category
  TH1F* kf[8];//1bin-kFactor
  //Scaling MC to match data->ttbar k-Factor
  for(int i = 0; i < 4; i++){
    std::cout << "==== Cat " << i+1 << "====" << std::endl;
    TString s(Form("cat_%d_0mu_kf",i+1));
    kf[i] = new TH1F(s, s, 1, 0.0, 1.0);
    kf[i]->SetBinContent(1,data[i]->Integral()/t_mc[i]->Integral());
    std::cout << "scale 0mu: " << data[i]->Integral()/t_mc[i]->Integral() 
	      << " "  << kf[i]->GetBinContent(1) << std::endl;
    t_mc[i]->Scale(data[i]->Integral()/t_mc[i]->Integral());
    
    s = Form("cat_%d_1mu_kf",i+1);
    kf[i+4] = new TH1F(s, s, 1, 0.0, 1.0);
    kf[i+4]->SetBinContent(1,data[i+4]->Integral()/t_mc_1mu[i]->Integral());
    std::cout << "scale 1mu: " << data[i+4]->Integral()/t_mc_1mu[i]->Integral() 
	      << " "  << kf[i+4]->GetBinContent(1) << std::endl;
    t_mc_1mu[i]->Scale(data[i+4]->Integral()/t_mc_1mu[i]->Integral()); 
  }

  //Get Systematics
  TH1F* sys[8];
  for(int j = 0; j < 4; j++){
    TString s(Form("sys_cat_%d_0mu",j+1)); 
    sys[j] = new TH1F(s,s, r2B[j], v.at(j));
    sys[j]->Sumw2();
    for(int k = 1; k <= sys[j]->GetNbinsX(); k++){
      double ss = (data[j]->GetBinContent(k)-t_mc[j]->GetBinContent(k))/t_mc[j]->GetBinContent(k);
      sys[j]->SetBinContent(k,ss);
    }
  }
  
  for(int j = 0; j < 4; j++){
    TString s(Form("sys_cat_%d_1mu",j+1)); 
    sys[j+4] = new TH1F(s,s, r2B[j], v.at(j));
    sys[j+4]->Sumw2();
    for(int k = 1; k <= sys[j+4]->GetNbinsX(); k++){
      double ss = fabs(data[j+4]->GetBinContent(k)-t_mc_1mu[j]->GetBinContent(k))/t_mc_1mu[j]->GetBinContent(k);
      sys[j+4]->SetBinContent(k,ss);
    }
  }
  
  //Apply Systematics
  for(int j = 0; j < 4; j++){
    for(int k = 1; k <= sys[j]->GetNbinsX(); k++){
      double err = sqrt(pow(t_mc[j]->GetBinError(k),2) + 
			pow(t_mc[j]->GetBinContent(k)*sys[j]->GetBinContent(k),2));
      t_mc[j]->SetBinError(k,err);
    }
  }

  for(int j = 0; j < 4; j++){
    for(int k = 1; k <= sys[j+4]->GetNbinsX(); k++){
      double err = sqrt(pow(t_mc_1mu[j]->GetBinError(k),2) + 
			pow(t_mc_1mu[j]->GetBinContent(k)*sys[j+4]->GetBinContent(k),2));
      t_mc_1mu[j]->SetBinError(k,err);
    }
  }

  TString SYS = "_Nominal";
  TFile* f1 = new TFile("PredFilesAN/TwoBtag_May_2014_Nominal.root","RECREATE");
  TString n, n1, ex_s;
  for(int i = 0; i < 3; i++){
    n = TString(Form("cat%d_1D_1mu_Box_Pred",i+1));
    n1 = TString(Form("cat%d_1D_0mu_Box_Pred",i+1));
    ex_s = TString(Form("cat%d",i+1));
    
    RatioPlotsBandV2( data[i], t_mc[i], "Data  0#mu-2b", "BKg Pred 0#mu-2b", "PredPlotsAN/Two_TT_0mu_MC_Pred_V2"+ex_s+SYS, "RSQ", r2B[i], v.at(i),1);
    RatioPlotsBandV2( data[4+i], t_mc_1mu[i], "Data  1#mu-2b", "BKg Pred 1#mu-2b", "PredPlotsAN/Two_TT_1mu_MC_Pred_V2"+ex_s+SYS, "RSQ", r2B[i], v.at(i),1);
    RatioPlotsV2(t_s_1mu[i], data[i+4], t_mc_1mu[i], "Data  1#mu-2b", "BKg Pred 1#mu-2b", "PredPlotsAN/Stack_Two_TT_1mu_MC_Pred_V2"+ex_s+SYS, "RSQ", r2B[i], v.at(i), leg[i]);
    RatioPlotsV2(t_s_0mu[i], data[i], t_mc[i], "Data  0#mu-2b", "BKg Pred 0#mu-2b", "PredPlotsAN/Stack_Two_TT_0mu_MC_Pred_V2"+ex_s+SYS, "RSQ", r2B[i], v.at(i), leg[i]);
    
    data[i]->Write();
    t_mc[i]->Write();
    t_mc_1mu[i]->Write();
    sys[i]->Write();
    sys[i+4]->Write();
    kf[i]->Write();
    kf[i+4]->Write();
  }
  f1->Close();
  
  
  return 0;

}
