/*
Plot MET AND NJETS
*/
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
  //gROOT->Reset();
  set_plot_style();
  TCanvas* cc = new TCanvas("cc", "cc", 640, 640);

  //Pushing Binning
  v.push_back(c1B);
  v.push_back(c2B);
  v.push_back(c3B);
  v.push_back(c4B);
  //Pushing Binning
  v_tt.push_back(c1B_tt);
  v_tt.push_back(c2B_tt);
  v_tt.push_back(c3B_tt);
  v_tt.push_back(c4B_tt);

  TFile* F = new TFile("FinalROOTFiles/VetoBtag_FixBtag_PFNoPu_Sep2014_met_njetsV2.root");
  
  ///////////////////////////////////////////////////////
  ///////////////Creating MR categories binned in R2/////
  //////////////////////////////////////////////////////
  TH1F* dy_met[12];
  TH1F* z_met[12];
  TH1F* w_met[12];
  TH1F* tt_met[12];
  TH1F* data_met[12];

  TH1F* dy_njets[12];
  TH1F* z_njets[12];
  TH1F* w_njets[12];
  TH1F* tt_njets[12];
  TH1F* data_njets[12];
  
  
  double z_k2factor[] = {1.1973, 1.1973, 1.1973, 1.1973};//NoMu Only
  double w_k2factor[] = {1.2401, 1.2401, 1.2401, 1.2401};
  
  TFile* tt_F = new TFile("TT_KFACT_and_SYS.root");
  TH1F* h_ttK = (TH1F*)tt_F->Get("k_factor");
  TH1F* h_SYS = (TH1F*)tt_F->Get("SYS");
  //double tt_k2factor = 1.8034;
  double tt_k2factor = h_ttK->GetBinContent(1);
  std::cout << "====KF: " << tt_k2factor << std::endl;

  for(int i = 0; i < 3; i++){
    for(int j = 1; j <= 4; j++){
      TString name1 = TString(Form("DY_cat%d_met_%dmu_Box",j,i));
      dy_met[4*i+j-1] = (TH1F*)F->Get(name1);
      dy_met[4*i+j-1]->Scale(z_k2factor[j-1]);
      
      TString name2 = TString(Form("Z_cat%d_met_%dmu_Box",j,i));
      z_met[4*i+j-1] = (TH1F*)F->Get(name2);
      z_met[4*i+j-1]->Scale(z_k2factor[j-1]);
      
      TString name3 = TString(Form("W_cat%d_met_%dmu_Box",j,i));
      w_met[4*i+j-1] = (TH1F*)F->Get(name3);
      w_met[4*i+j-1]->Scale(w_k2factor[j-1]);
      
      //TString name4 = TString(Form("TT_L_cat%d_1D_%dmu_Box",j,i));
      TString name4 = TString(Form("TT_cat%d_met_%dmu_Box",j,i));
      tt_met[4*i+j-1] = (TH1F*)F->Get(name4);
      tt_met[4*i+j-1]->Scale(tt_k2factor);
      
      TString name5 = TString(Form("Data_cat%d_met_%dmu_Box",j,i));
      data_met[4*i+j-1] = (TH1F*)F->Get(name5);
    }
  }

  for(int i = 0; i < 3; i++){
    for(int j = 1; j <= 4; j++){
      TString name1 = TString(Form("DY_cat%d_njets_%dmu_Box",j,i));
      dy_njets[4*i+j-1] = (TH1F*)F->Get(name1);
      dy_njets[4*i+j-1]->Scale(z_k2factor[j-1]);
      
      TString name2 = TString(Form("Z_cat%d_njets_%dmu_Box",j,i));
      z_njets[4*i+j-1] = (TH1F*)F->Get(name2);
      z_njets[4*i+j-1]->Scale(z_k2factor[j-1]);
      
      TString name3 = TString(Form("W_cat%d_njets_%dmu_Box",j,i));
      w_njets[4*i+j-1] = (TH1F*)F->Get(name3);
      w_njets[4*i+j-1]->Scale(w_k2factor[j-1]);
      
      //TString name4 = TString(Form("TT_L_cat%d_1D_%dmu_Box",j,i));
      TString name4 = TString(Form("TT_cat%d_njets_%dmu_Box",j,i));
      tt_njets[4*i+j-1] = (TH1F*)F->Get(name4);
      tt_njets[4*i+j-1]->Scale(tt_k2factor);
      
      TString name5 = TString(Form("Data_cat%d_njets_%dmu_Box",j,i));
      data_njets[4*i+j-1] = (TH1F*)F->Get(name5);
    }
  }
  
  std::string fname0;
  std::cout.precision(16);
  std::ifstream mfile0("list_DM_BugFixed.list");
  TString plotName[24];
  int ctr = 0;
  if (mfile0.is_open()){
    while ( mfile0.good() ){
      mfile0 >> fname0;
      if(mfile0.eof())break;
      std::cout << fname0 << std::endl;
      int low_ = fname0.find("DMm");
      int high_ = fname0.find("_testMC_0.root") - low_;
      
      std::string dm_sample = fname0.substr(low_,high_);
      std::cout << "============ " << dm_sample << " ==================" << std::endl;
      plotName[ctr] = dm_sample.c_str();
      ctr++;
    }
  }else{
    std::cout << "Unable to Open the File!!!" << std::endl;
  }

  TH1F* hs_met[24][4];
  TH1F* hs_njets[24][4];
  TString sn;
  TFile* fs_in = new TFile("/Users/cmorgoth/Software/git/DM_Signal/SIGNAL_MET_NJETS.root");
  for(int j = 0; j < 24; j++){
    for(int i = 1; i <= 4; i++){
      sn = TString(Form("signal%d_cat%i_met",j,i));
      hs_met[j][i-1] = (TH1F*)fs_in->Get(sn);
      sn = TString(Form("signal%d_cat%i_njets",j,i));
      hs_njets[j][i-1] = (TH1F*)fs_in->Get(sn);
    }
  }
    
  TLegend* leg;
  THStack* stack1 = new THStack("stack1", "");
  
  for(int ls = 0; ls < 24; ls++){
    for(int k = 0; k < 4; k++){
      stack1 = new THStack("stack1", "");
      
      data_met[k]->Sumw2();
      data_met[k]->SetMarkerStyle(20);
      data_met[k]->SetLineColor(1);
      data_met[k]->SetMarkerSize(1.5);
      
      tt_met[k]->SetFillColor(kPink+9);
      dy_met[k]->SetFillColor(kViolet+9);
      z_met[k]->SetFillColor(kYellow-4);
      w_met[k]->SetFillColor(kSpring+4);
      
      hs_met[ls][k]->SetLineColor(kOrange+7);
      hs_met[ls][k]->SetLineWidth(4);
      hs_met[ls][k]->SetLineStyle(2);
      
      leg = new TLegend(0.65,0.7,0.89,0.92);
      leg->AddEntry(w_met[k],"W + jets","f");
      leg->AddEntry(z_met[k],"Z(#nu#bar{#nu}) + jets","f");
      leg->AddEntry(tt_met[k],"t #bar{t} + jets","f");
      leg->AddEntry(dy_met[k],"Z/#gamma^{*}(ll) + jets","f");
      leg->AddEntry(data_met[k],"Data","lep");
      leg->AddEntry(hs_met[ls][k],"DM monojet","l");
      
      //leg->SetHeader("R^{2} Signal Region");
      
      w_met[k]->SetTitle("");
      w_met[k]->SetStats(0);
      tt_met[k]->SetTitle("");
      tt_met[k]->SetStats(0);
      dy_met[k]->SetTitle("");
      dy_met[k]->SetStats(0);
      z_met[k]->SetTitle("");
      z_met[k]->SetStats(0);
      data_met[k]->SetTitle("");
      data_met[k]->SetStats(0);
      
      stack1->Add(dy_met[k]);//DY
      stack1->Add(tt_met[k]);//TTbar
      stack1->Add(z_met[k]);//Wjets
      stack1->Add(w_met[k]);//ZJets
      
      stack1->Draw();
      ( (TAxis*)( stack1->GetXaxis() ) )->SetTitle("R^{2}");
      stack1->Draw();
      data_met[k]->Draw("same");
      
      TH1F* aux2 = new TH1F( *dy_met[k] );
      aux2->Sumw2();
      aux2->Add(tt_met[k], 1);
      aux2->Add(z_met[k], 1);
      aux2->Add(w_met[k], 1);
      for(int j = 1; j <= 10; j++){
	std::cout << "b_Content: " << aux2->GetBinContent(j) << std::endl;
	std::cout << "Data b_Content: " << data_met[k]->GetBinContent(j) << std::endl;
      }
      TString s = TString(Form("MET_AND_NJETS/Data_MC_MET_cat%d_",k+1))+plotName[ls];
      TString y_axis;
      if(k == 0){
	y_axis = "Events/0.05";
      }else if(k ==3){
	y_axis = "Events/0.1";
      }else{
	y_axis = "Events/0.075";
      }
      
      
      //RatioPlotsV3(stack1, data_met[k], aux2, "MC 0 #mu BOX", "Data 0 #mu BOX", s, "MET", r2B[k],  v.at(k),leg, y_axis);
      RatioPlotSignal(stack1, data_met[k], aux2, "MC 0 #mu BOX", "Data 0 #mu BOX", s+"_signal_Vu_1TeV", "MET", r2B[k],  v.at(k),leg, y_axis, hs_met[ls][k]);
      delete leg;
      delete aux2;
      delete stack1;
    }
    
    for(int k = 0; k < 4; k++){
      stack1 = new THStack("stack1", "");
      
      data_njets[k]->Sumw2();
      data_njets[k]->SetMarkerStyle(20);
      data_njets[k]->SetLineColor(1);
      data_njets[k]->SetMarkerSize(1.5);
      
      tt_njets[k]->SetFillColor(kPink+9);
      dy_njets[k]->SetFillColor(kViolet+9);
      z_njets[k]->SetFillColor(kYellow-4);
      w_njets[k]->SetFillColor(kSpring+4);
      
      hs_njets[ls][k]->SetLineColor(kBlue-3);
      hs_njets[ls][k]->SetLineWidth(3);
      hs_njets[ls][k]->SetLineStyle(2);
      
      leg = new TLegend(0.65,0.7,0.89,0.92);
      leg->AddEntry(w_njets[k],"W + jets","f");
      leg->AddEntry(z_njets[k],"Z(#nu#bar{#nu}) + jets","f");
      leg->AddEntry(tt_njets[k],"t #bar{t} + jets","f");
      leg->AddEntry(dy_njets[k],"Z/#gamma^{*}(ll) + jets","f");
      leg->AddEntry(data_njets[k],"Data","lep");
      leg->AddEntry(hs_njets[ls][k],"DM monojet","l");
      
      //leg->SetHeader("R^{2} Signal Region");
      
      w_njets[k]->SetTitle("");
      w_njets[k]->SetStats(0);
      tt_njets[k]->SetTitle("");
      tt_njets[k]->SetStats(0);
      dy_njets[k]->SetTitle("");
      dy_njets[k]->SetStats(0);
      z_njets[k]->SetTitle("");
      z_njets[k]->SetStats(0);
      data_njets[k]->SetTitle("");
      data_njets[k]->SetStats(0);
    
      stack1->Add(dy_njets[k]);//DY
      stack1->Add(tt_njets[k]);//TTbar
      stack1->Add(z_njets[k]);//Wjets
      stack1->Add(w_njets[k]);//ZJets
    
      stack1->Draw();
      ( (TAxis*)( stack1->GetXaxis() ) )->SetTitle("R^{2}");
      stack1->Draw();
      data_njets[k]->Draw("same");
  
      TH1F* aux2 = new TH1F( *dy_njets[k] );
      aux2->Sumw2();
      aux2->Add(tt_njets[k], 1);
      aux2->Add(z_njets[k], 1);
      aux2->Add(w_njets[k], 1);
      for(int j = 1; j <= 10; j++){
	std::cout << "b_Content: " << aux2->GetBinContent(j) << std::endl;
	std::cout << "Data b_Content: " << data_njets[k]->GetBinContent(j) << std::endl;
      }
      TString s = TString(Form("MET_AND_NJETS/Data_MC_NJETS_cat%d_",k+1))+plotName[ls];
      TString y_axis;
      if(k == 0){
	y_axis = "Events/0.05";
      }else if(k ==3){
	y_axis = "Events/0.1";
      }else{
	y_axis = "Events/0.075";
      }
      
      
      //RatioPlotsV3(stack1, data_njets[k], aux2, "MC 0 #mu BOX", "Data 0 #mu BOX", s, "NJETS", r2B[k],  v.at(k),leg, y_axis);
      RatioPlotSignal(stack1, data_njets[k], aux2, "MC 0 #mu BOX", "Data 0 #mu BOX", s+"_signal_Vu_1TeV", "NJETS", r2B[k],  v.at(k),leg, y_axis, hs_njets[ls][k]);
      delete leg;
      delete aux2;
      delete stack1;
    }
    
  }

  return 0;

}
