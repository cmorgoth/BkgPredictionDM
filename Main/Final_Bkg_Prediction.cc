/*
Final Background Prediction, June 2014
Includes bug fixed for the kfactors
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
  gROOT->Reset();

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

  //TFile* F = new TFile("FinalROOT_May2014/VetoBtag_May_2014_Original.root");
  
  //TFile* F = new TFile("FinalROOTFiles/VetoBtag_May_2014_OriginalTrigger_OnlyNoMU.root");
  //TFile* F = new TFile("FinalROOTFiles/VetoBtag_May_2014_OriginalTrigger_NoMU_and_Mu.root");
  
  //TFile* F = new TFile("FinalROOTFiles/VetoBtag_May_2014_NewBinnedTrigger_OnlyNoMU.root");
  //TFile* F = new TFile("FinalROOTFiles/VetoBtag_May_2014_NewBinnedTrigger_NoMU_and_Mu.root");
  
  //TFile* F = new TFile("FinalROOTFiles/VetoBtag_May_2014_SingleTrigger_Only_NoMu.root");
  //TFile* F = new TFile("FinalROOTFiles/VetoBtag_May_2014_SingleTrigger_NoMU_and_Mu.root");

  //TFile* F = new TFile("FinalROOTFiles/VetoBtag_May_2014_OriginalTrigger_NoMU_and_Mu_NOisr.root");
  //TFile* F = new TFile("FinalROOTFiles/VetoBtag_Loose_May_2014_NewTriger_AN.root");
  


  TFile* F = new TFile("FinalROOTFiles/VetoBtag_FixBtag_PFNoPu_Sep2014.root");
  //TFile* F = new TFile("FinalROOTFiles/VetoBtag_NoMonoJet.root");
  
  
  ///////////////////////////////////////////////////////
  ///////////////Creating MR categories binned in R2/////
  //////////////////////////////////////////////////////
  TH1F* dy[12];
  TH1F* z[12];
  TH1F* w[12];
  TH1F* tt[12];
  TH1F* data[12];
  
  //double tt_k2factor = 1.8034;
  //double z_k2factor = 1.1973;
  //double w_k2factor = 1.2455;
 

  //double z_k2factor[] = {1.17908, 1.04922, 0.742194, 0.819435};//NoMu Only
  //double w_k2factor[] = {1.39833, 1.274, 1.14633, 0.897725};
  
  //double z_k2factor[] = {1.14995, 1.04975, 0.742571, 0.819855};//NoMu Only
  //double w_k2factor[] = {1.35609, 1.27472, 1.14695, 0.898208};
  
  //double z_k2factor[] = {1.14995, 1.04975, 0.742571, 0.819855};//NoMu Only
  //double w_k2factor[] = {1.35612, 1.27472, 1.14695, 0.898208};


  
  //double z_k2factor[] = {1.16067, 1.05484, 0.99, 0.80138};//NoMu Only
  //double w_k2factor[] = {1.34902, 1.25454, 1.12949, 0.875763};
  
  //double z_k2factor[] = {1.0, 1.0, 1.0, 1.0};//NoMu Only
  //double w_k2factor[] = {1.0, 1.0, 1.0, 1.0};

  //double z_k2factor[] = {1.0663, 1.0663, 1.0663, 1.0663};//NoMu Only
  //double w_k2factor[] = {1.28877, 1.28877, 1.28877, 1.28877};
  

  double z_k2factor[] = {1.1973, 1.1973, 1.1973, 1.1973};//NoMu Only
  double w_k2factor[] = {1.2401, 1.2401, 1.2401, 1.2401};
  
  //double z_k2factor[] = {1.14995, 1.04975, 0.742571, 0.819855};//NoMu Only
  //double w_k2factor[] = {1.35612, 1.27472, 1.14695, 0.898208};

  TFile* tt_F = new TFile("TT_KFACT_and_SYS.root");
  TH1F* h_ttK = (TH1F*)tt_F->Get("k_factor");
  TH1F* h_SYS = (TH1F*)tt_F->Get("SYS");
  //double tt_k2factor = 1.8034;
  double tt_k2factor = h_ttK->GetBinContent(1);
  std::cout << "====KF: " << tt_k2factor << std::endl;

  for(int i = 0; i < 3; i++){
    for(int j = 1; j <= 4; j++){
      TString name1 = TString(Form("DY_cat%d_1D_%dmu_Box",j,i));
      dy[4*i+j-1] = (TH1F*)F->Get(name1);
      dy[4*i+j-1]->Scale(z_k2factor[j-1]);
      
      TString name2 = TString(Form("Z_cat%d_1D_%dmu_Box",j,i));
      z[4*i+j-1] = (TH1F*)F->Get(name2);
      z[4*i+j-1]->Scale(z_k2factor[j-1]);
      
      TString name3 = TString(Form("W_cat%d_1D_%dmu_Box",j,i));
      w[4*i+j-1] = (TH1F*)F->Get(name3);
      w[4*i+j-1]->Scale(w_k2factor[j-1]);
      
      //TString name4 = TString(Form("TT_L_cat%d_1D_%dmu_Box",j,i));
      TString name4 = TString(Form("TT_cat%d_1D_%dmu_Box",j,i));
      tt[4*i+j-1] = (TH1F*)F->Get(name4);
      tt[4*i+j-1]->Scale(tt_k2factor);
      
      TString name5 = TString(Form("Data_cat%d_1D_%dmu_Box",j,i));
      data[4*i+j-1] = (TH1F*)F->Get(name5);
    }
  }
  //std::cout << "debug 0" << std::endl;
  ///////////////////////////////////////////////////////
  ////////////////ttbar kfactors and SYS/////////////////
  //////////////////////////////////////////////////////
  
  for(int i = 0; i < 4; i++){
    for(int k = 1; k <= tt[i]->GetNbinsX(); k++){
      double err = sqrt(pow(tt[i]->GetBinError(k),2) + 
			pow(tt[i]->GetBinContent(k)*h_SYS->GetBinContent(4),2));//Uses 1mu-2b SF SYS
      tt[i]->SetBinError(k,err);
      //1mu
      err = sqrt(pow(tt[i+4]->GetBinError(k),2) + 
		 pow(tt[i+4]->GetBinContent(k)*h_SYS->GetBinContent(4),2));
      tt[i+4]->SetBinError(k,err);
    }
  }

  /*
  TFile* ftt = new TFile("PredFilesAN/TwoBtag_May_2014_Nominal.root");
  
  TH1F* sys_tt_0mu[4];
  TH1F* kf_tt_0mu[4];
  TH1F* sys_tt_1mu[4];
  TH1F* kf_tt_1mu[4];
  for(int i = 0; i < 4; i++){
    TString nm(Form("sys_cat_%d_0mu", i+1));
    sys_tt_0mu[i] = (TH1F*)ftt->Get(nm);
    nm = Form("cat_%d_0mu_kf", i+1);
    kf_tt_0mu[i] = (TH1F*)ftt->Get(nm);
    
    nm = Form("sys_cat_%d_1mu", i+1);
    sys_tt_1mu[i] = (TH1F*)ftt->Get(nm);
    nm = Form("cat_%d_1mu_kf", i+1);
    kf_tt_1mu[i] = (TH1F*)ftt->Get(nm);
  }
  //std::cout << "debug 1" << std::endl;
  for(int i = 0; i < 4; i++){
    //tt[i]->Scale(kf_tt_0mu[i]->GetBinContent(1));//Uses 0mu-2b SF
    int aux = i; 
    if(i == 3)aux = 2;//Avoid using SF from last category, use third category
    //tt[i]->Scale(kf_tt_1mu[aux]->GetBinContent(1));//Uses 1mu-2b SF
    //tt[i+4]->Scale(kf_tt_1mu[aux]->GetBinContent(1));
    
    for(int k = 1; k <= tt[i]->GetNbinsX(); k++){
      int bn = -1;
      if(i == 0 && tt[i]->GetBinCenter(k) > 0.8){
	bn = 7;
      }else if(i != 0 && tt[i]->GetBinCenter(k) > 0.75){
	bn = 4;
      }else{
	bn = k;
      }
      //double err = sqrt(pow(tt[i]->GetBinError(k),2) + 
      //pow(tt[i]->GetBinContent(k)*sys_tt_0mu[i]->GetBinContent(bn),2));//Uses 0mu-2b SYS
      double err = sqrt(pow(tt[i]->GetBinError(k),2) + 
			pow(tt[i]->GetBinContent(k)*sys_tt_1mu[aux]->GetBinContent(bn),2));//Uses 1mu-2b SF SYS
      tt[i]->SetBinError(k,err);
      //1mu
      err = sqrt(pow(tt[i+4]->GetBinError(k),2) + 
		 pow(tt[i+4]->GetBinContent(k)*sys_tt_1mu[aux]->GetBinContent(bn),2));
      tt[i+4]->SetBinError(k,err); 
    }
  }
*/
  
  /////////////////////////////////////////////////////////
  /////////////////DY 2mu Prediction//////////////////////
  ////////////////////////////////////////////////////////
  
  TH1F* p_0b_2mu_dy[4];
  for(int i = 0; i < 4; i++){
    p_0b_2mu_dy[i] = new TH1F(*data[8+i]);
    p_0b_2mu_dy[i]->Add(tt[8+i], -1.0);//Subtracting tt 0b 2mu from MC
  }
  
  double error = -1.0;
  double Integral;
  
  ///////////////////////////////////////////
  //////////DY Prediction 1mu BOX ///////////
  ///////////////////////////////////////////
  
  TH1F* p_0b_1mu_dy[4];
  TH1F*  r_0b_1mu_dy[4];
  for(int i = 0; i < 4; i++){
    p_0b_1mu_dy[i] = new TH1F( *p_0b_2mu_dy[i] );//Drell-Yan prediction for 0b 1mu box
    r_0b_1mu_dy[i] = new TH1F( *dy[4+i] );
    r_0b_1mu_dy[i]->Divide(dy[8+i]);
    p_0b_1mu_dy[i]->Multiply(r_0b_1mu_dy[i]);
    //Integral = p_0b_1mu_dy->IntegralAndError(1, TB, 1, TB, error, "");
    //std::cout << "---------1)-------" << std::endl;
    //std::cout << "Drell-Yan Prediction 0b 1mu box: " << Integral << " error: " << error << std::endl;
  }
  
  ////////////////////////////////////////
  ///////////W 1mu - Closure//////////////
  ////////////////////////////////////////
  TH1F* p_0b_1mu_wc[4];
  TH1F*  r_0b_1mu_wc[4];
  for(int i = 0; i < 4; i++){
    p_0b_1mu_wc[i] = new TH1F( *p_0b_2mu_dy[i] );//W prediction for 0b 1mu box Closure Test
    r_0b_1mu_wc[i] = new TH1F( *w[4+i] );
    r_0b_1mu_wc[i]->Divide(dy[8+i]);
    p_0b_1mu_wc[i]->Multiply(r_0b_1mu_wc[i]);
  }
  
  //tt_1mu from MC
  
  ///////////////////////////////////////
  ///////////////Total Closure///////////
  //////////////////////////////////////
  TH1F* p_0b_1mu_c[4];//Total Closure Prediction
  for(int i = 0; i < 4; i++){
    p_0b_1mu_c[i] = new TH1F(*p_0b_1mu_wc[i]);
    p_0b_1mu_c[i]->Add(p_0b_1mu_dy[i]);
    p_0b_1mu_c[i]->Add(tt[4+i]);
  }


  //////////////////////////////////////
  ///////////DY 0mu Pred///////////////
  /////////////////////////////////////
  TH1F* p_0b_0mu_dy[4];
  TH1F*  r_0b_0mu_dy[4];
  for(int i = 0; i < 4; i++){
    p_0b_0mu_dy[i] = new TH1F( *p_0b_2mu_dy[i] );//Drell-Yan prediction for 0b 1mu box
    r_0b_0mu_dy[i] = new TH1F( *dy[i] );
    r_0b_0mu_dy[i]->Divide(dy[8+i]);
    p_0b_0mu_dy[i]->Multiply(r_0b_0mu_dy[i]);
  }

  ////////////////////////////////////
  ///////////W 1mu Pred///////////////
  ////////////////////////////////////
  TH1F* data_copy_1mu[4];//cross check to see that data is not changed
  TString nd;
  for(int i = 0; i < 4; i++){
    nd = TString(Form("cat%d_data_Ori",i+1));
    data_copy_1mu[i] = new TH1F(nd, nd, r2B[i], v.at(i));
    for(int j = 1; j <= data[4+i]->GetNbinsX(); j++){
      data_copy_1mu[i]->SetBinContent(j,data[4+i]->GetBinContent(j));
      data_copy_1mu[i]->SetBinError(j,data[4+i]->GetBinError(j));
    }
  }

  TH1F* p_0b_1mu_w[4];//Prediction W jets 1mu Data-1mu - ttbar-1mu - dy-1mu
  TH1F* r_0b_1mu_w[4];
  for(int i = 0; i < 4; i++){
    p_0b_1mu_w[i] = new TH1F( *data[4+i] );//W prediction for 0b 1mu box
    p_0b_1mu_w[i]->Add(tt[4+i], -1.0);//Subtracting tt 0b 2mu from MC
    p_0b_1mu_w[i]->Add(p_0b_1mu_dy[i], -1.0);//Subtracting DY 0b 1mu Prediction
  }

  ////////////////////////////////////
  ///////////W 0mu Pred///////////////
  ////////////////////////////////////
  TH1F* p_0b_0mu_w[4];
  TH1F* r_0b_0mu_w[4];
  for(int i = 0; i < 4; i++){
    p_0b_0mu_w[i] = new TH1F( *p_0b_1mu_w[i] );//W prediction for 0b 0mu box
    r_0b_0mu_w[i] = new TH1F( *w[i] );
    r_0b_0mu_w[i]->Divide(w[i+4]);
    p_0b_0mu_w[i]->Multiply(r_0b_0mu_w[i]);
  }
  
  ////////////////////////////////////
  ///////////Z 0mu Pred from 1mu//////
  ////////////////////////////////////
  TH1F* p_0b_0mu_z[4];
  TH1F* r_0b_0mu_z[4];
  for(int i = 0; i < 4; i++){
    p_0b_0mu_z[i] = new TH1F( *p_0b_1mu_w[i] );//Z prediction for 0b 0mu box from Wjets
    r_0b_0mu_z[i] = new TH1F( *z[i] );
    r_0b_0mu_z[i]->Divide(w[i+4]);
    p_0b_0mu_z[i]->Multiply(r_0b_0mu_z[i]);
  }
  ////////////////////////////////////
  ///////////Z 0mu Pred from 2mu//////
  ////////////////////////////////////
  TH1F* p_0b_0mu_z_v2[4];
  TH1F* r_0b_0mu_z_v2[4];
  for(int i = 0; i < 4; i++){
    p_0b_0mu_z_v2[i] = new TH1F( *p_0b_2mu_dy[i] );//Z prediction for 0b 0mu box from DY
    r_0b_0mu_z_v2[i] = new TH1F( *z[i] );
    r_0b_0mu_z_v2[i]->Divide(dy[i+8]);
    p_0b_0mu_z_v2[i]->Multiply(r_0b_0mu_z_v2[i]);
  }

   //tt 0b 0mu from MC

  ////////////////////////////////////
  ///////////Total 0mu Pred////////////
  ////////////////////////////////////
  TH1F* p_0b_0mu[4];//Total 0b 0mu Prediction
  for(int i = 0; i < 4; i++){
    p_0b_0mu[i] = new TH1F(*p_0b_0mu_w[i]);//Add W prediction
    p_0b_0mu[i]->Add(p_0b_0mu_z[i]);//Add Z prediction
    p_0b_0mu[i]->Add(p_0b_0mu_dy[i]);//Add DY prediction
    p_0b_0mu[i]->Add(tt[i]);//Add tt MC
  }

  ////////////////////////////////////
  ///////////Total 0mu Pred V2///////
  ////////////////////////////////////
  TH1F* p_0b_0mu_v2[4];//Total 0b 0mu Prediction
  for(int i = 0; i < 4; i++){
    p_0b_0mu_v2[i] = new TH1F(*p_0b_0mu_w[i]);//Add W prediction
    p_0b_0mu_v2[i]->Add(p_0b_0mu_z_v2[i]);//Add Z prediction
    p_0b_0mu_v2[i]->Add(p_0b_0mu_dy[i]);//Add DY prediction
    p_0b_0mu_v2[i]->Add(tt[i]);//Add tt MC
  }
  
  ////////////////////////////////////
  ///////////Total 0mu Pred V3////////
  ///////////Purely MC ///////////////
  ////////////////////////////////////
  TH1F* p_0b_0mu_v3[4];//Total 0b 0mu Prediction
  for(int i = 0; i < 4; i++){
    p_0b_0mu_v3[i] = new TH1F(*w[i]);//Add W MC
    p_0b_0mu_v3[i]->Add(z[i]);//Add Z MC
    p_0b_0mu_v3[i]->Add(dy[i]);//Add DY MC
    p_0b_0mu_v3[i]->Add(tt[i]);//Add tt MC
  }


  ////////////////////////////////////
  ///////////Total 0mu Pred V4////////
  //////////Z(nunu) from MC //////////
  ////////////////////////////////////
  TH1F* p_0b_0mu_v4[4];//Total 0b 0mu Prediction
  for(int i = 0; i < 4; i++){
    p_0b_0mu_v4[i] = new TH1F(*p_0b_0mu_w[i]);//Add W prediction
    p_0b_0mu_v4[i]->Add(z[i]);//Add Z MC
    p_0b_0mu_v4[i]->Add(p_0b_0mu_dy[i]);//Add DY prediction
    p_0b_0mu_v4[i]->Add(tt[i]);//Add tt MC
  }

  ////////////////////////////////////
  ///////////Total 0mu Pred V5////////
  //////////W(lnu) from MC //////////
  ////////////////////////////////////
  TH1F* p_0b_0mu_v5[4];//Total 0b 0mu Prediction
  for(int i = 0; i < 4; i++){
    p_0b_0mu_v5[i] = new TH1F(*w[i]);//Add W MC
    p_0b_0mu_v5[i]->Add(p_0b_0mu_z[i]);//Add Z prediction
    p_0b_0mu_v5[i]->Add(p_0b_0mu_dy[i]);//Add DY prediction
    p_0b_0mu_v5[i]->Add(tt[i]);//Add tt MC
  }

  /////////////////////////////////////////////
  //////////Include Systematics////////////////
  /////////////////////////////////////////////
  TH1F* sys[4];
  
  TFile* sysF = new TFile("PredFilesAN/Sys_for_Ana.root");
  for(int i = 0; i < 4; i++){
    TString s(Form("cat%d_SYS",i+1));
    sys[i] = (TH1F*)sysF->Get(s);
  }
  
  //Apply Systematics
  TH1F* p_0b_1mu_c_sys[4];

  TH1F* p_0b_0mu_sys[4];
  TH1F* p_0b_0mu_dy_sys[4];
  TH1F* p_0b_0mu_z_sys[4];
  TH1F* p_0b_0mu_w_sys[4];
  TH1F* p_0b_0mu_tt_sys[4];
  
  TH1F* p_0b_0mu_sys_v4[4];
  TH1F* p_0b_0mu_dy_sys_v4[4];
  TH1F* p_0b_0mu_z_sys_v4[4];
  TH1F* p_0b_0mu_w_sys_v4[4];
  TH1F* p_0b_0mu_tt_sys_v4[4];
  
  TH1F* p_0b_0mu_sys_v5[4];
  TH1F* p_0b_0mu_dy_sys_v5[4];
  TH1F* p_0b_0mu_z_sys_v5[4];
  TH1F* p_0b_0mu_w_sys_v5[4];
  TH1F* p_0b_0mu_tt_sys_v5[4];
  
  for(int i = 0; i < 4; i++){
    //1mu
    p_0b_1mu_c_sys[i] = new TH1F(*p_0b_1mu_c[i]);
    //0mu Analysis
    p_0b_0mu_dy_sys[i] = new TH1F(*p_0b_0mu_dy[i]);//Pred
    p_0b_0mu_z_sys[i] = new TH1F(*p_0b_0mu_z[i]);//Pred
    p_0b_0mu_w_sys[i] = new TH1F(*p_0b_0mu_w[i]);//Pred
    p_0b_0mu_tt_sys[i] = new TH1F(*tt[i]);//MC
    //0mu v4
    p_0b_0mu_dy_sys_v4[i] = new TH1F(*p_0b_0mu_dy[i]);//Pred
    p_0b_0mu_z_sys_v4[i] = new TH1F(*z[i]);//MC
    p_0b_0mu_w_sys_v4[i] = new TH1F(*p_0b_0mu_w[i]);//Pred
    p_0b_0mu_tt_sys_v4[i] = new TH1F(*tt[i]);//MC
    //0mu v5
    p_0b_0mu_dy_sys_v5[i] = new TH1F(*p_0b_0mu_dy[i]);//Pred
    p_0b_0mu_z_sys_v5[i] = new TH1F(*p_0b_0mu_z[i]);//Pred
    p_0b_0mu_w_sys_v5[i] = new TH1F(*w[i]);//MC
    p_0b_0mu_tt_sys_v5[i] = new TH1F(*tt[i]);//MC
    
    //Loop over bins
    for(int j = 1; j <= p_0b_1mu_c[i]->GetNbinsX(); j++){
      //double err = p_0b_1mu_c_sys[i]->GetBinContent(j)*sys[i]->GetBinContent(j);//Closure Only
      double err = sqrt( pow(p_0b_1mu_c_sys[i]->GetBinContent(j)*sys[i]->GetBinContent(j), 2) 
			 + pow( p_0b_1mu_c_sys[i]->GetBinError(j), 2 ) );
      p_0b_1mu_c_sys[i]->SetBinError(j, err);
      
      //0-mu Analysis
      err = 1.0*sqrt(pow(p_0b_0mu_dy_sys[i]->GetBinContent(j)*sys[i]->GetBinContent(j),2) + pow(p_0b_0mu_dy_sys[i]->GetBinError(j),2));
      p_0b_0mu_dy_sys[i]->SetBinError(j, err);
      
      err = 1.0*sqrt(pow(p_0b_0mu_z_sys[i]->GetBinContent(j)*sys[i]->GetBinContent(j),2) + pow(p_0b_0mu_z_sys[i]->GetBinError(j),2));
      p_0b_0mu_z_sys[i]->SetBinError(j, err);
      
      err = 1.0*sqrt(pow(p_0b_0mu_w_sys[i]->GetBinContent(j)*sys[i]->GetBinContent(j),2) + pow(p_0b_0mu_w_sys[i]->GetBinError(j),2));
      
      p_0b_0mu_w_sys[i]->SetBinError(j, err);
      
      //0-mu v4
      err = 1.0*sqrt(pow(p_0b_0mu_dy_sys_v4[i]->GetBinContent(j)*sys[i]->GetBinContent(j),2) + pow(p_0b_0mu_dy_sys_v4[i]->GetBinError(j),2));
      p_0b_0mu_dy_sys_v4[i]->SetBinError(j, err);
      
      err = 1.0*sqrt(pow(p_0b_0mu_z_sys_v4[i]->GetBinContent(j)*sys[i]->GetBinContent(j),2) + pow(p_0b_0mu_z_sys_v4[i]->GetBinError(j),2));
      p_0b_0mu_z_sys_v4[i]->SetBinError(j, err);
      
      err = 1.0*sqrt(pow(p_0b_0mu_w_sys_v4[i]->GetBinContent(j)*sys[i]->GetBinContent(j),2) + pow(p_0b_0mu_w_sys_v4[i]->GetBinError(j),2));
      
      p_0b_0mu_w_sys_v4[i]->SetBinError(j, err);
      
      }
    
    //0mu Analysis
    p_0b_0mu_sys[i] = new TH1F(*p_0b_0mu_dy_sys[i]);
    p_0b_0mu_sys[i]->Sumw2();
    p_0b_0mu_sys[i]->Add(p_0b_0mu_z_sys[i]);
    p_0b_0mu_sys[i]->Add(p_0b_0mu_w_sys[i]);
    p_0b_0mu_sys[i]->Add(p_0b_0mu_tt_sys[i]);
    //0mu v4
    p_0b_0mu_sys_v4[i] = new TH1F(*p_0b_0mu_dy_sys_v4[i]);
    p_0b_0mu_sys_v4[i]->Sumw2();
    p_0b_0mu_sys_v4[i]->Add(p_0b_0mu_z_sys_v4[i]);
    p_0b_0mu_sys_v4[i]->Add(p_0b_0mu_w_sys_v4[i]);
    p_0b_0mu_sys_v4[i]->Add(p_0b_0mu_tt_sys_v4[i]);
    //0mu v5
    p_0b_0mu_sys_v5[i] = new TH1F(*p_0b_0mu_dy_sys_v5[i]);
    p_0b_0mu_sys_v5[i]->Sumw2();
    p_0b_0mu_sys_v5[i]->Add(p_0b_0mu_z_sys_v5[i]);
    p_0b_0mu_sys_v5[i]->Add(p_0b_0mu_w_sys_v5[i]);
    p_0b_0mu_sys_v5[i]->Add(p_0b_0mu_tt_sys_v5[i]);
  }

  //Print Out Prediction in different cat
  for(int i = 0; i < 4; i++){
    std::cout << "==== Cat " << i+1 << " ====" << std::endl;
    Integral = p_0b_0mu_w_sys[i]->IntegralAndError(1, r2B[i], error, "");
    std::cout << "W: " << Integral << " \pm " << error << std::endl;
    Integral = p_0b_0mu_z_sys[i]->IntegralAndError(1, r2B[i], error, "");
    std::cout << "Z(nunu): " << Integral << " \pm " << error << std::endl;
    Integral = p_0b_0mu_dy_sys[i]->IntegralAndError(1, r2B[i], error, "");
    std::cout << "Z(ll): " << Integral << " \pm " << error << std::endl;
    Integral = p_0b_0mu_tt_sys[i]->IntegralAndError(1, r2B[i], error, "");
    //Integral = tt[i]->IntegralAndError(1, r2B[i], error, "");
    std::cout << "tt: "  << Integral << " \pm " << error << std::endl;
    Integral = p_0b_0mu_sys[i]->IntegralAndError(1, r2B[i], error, "");
    std::cout << "TOTAL BKG: "  << Integral << " \pm " << error << std::endl;
    Integral = data[i]->IntegralAndError(1, r2B[i], error, "");
    std::cout << "DATA: "  << Integral << " \pm " << error << std::endl;
    Integral = p_0b_0mu_v2[i]->IntegralAndError(1, r2B[i], error, "");
    std::cout << "TOTAL BKG V2: "  << Integral << " \pm " << error << std::endl;
    std::cout << "------Closure----------" << std::endl;
    Integral = p_0b_1mu_c_sys[i]->IntegralAndError(1, r2B[i], error, "");
    std::cout << "TOTAL BKG: "  << Integral << " \pm " << error << std::endl;
    Integral = data[i+4]->IntegralAndError(1, r2B[i], error, "");
    std::cout << "DATA 1MU: "  << Integral << " \pm " << error << std::endl;    
  }
  
  /////////////////
  ////Finishing////
  /////////////////
  
  TString n, n1, ex_s;
  TString SYS = "_NEW_kF_OriginalANA_TEST";
  TFile* f1 = new TFile("PredFilesAN/MR_Cat_PredV2"+SYS+".root","RECREATE");
  for(int i = 0; i < 4; i++){
    n = TString(Form("cat%d_1D_1mu_Box_Pred",i+1));
    n1 = TString(Form("cat%d_1D_0mu_Box_Pred",i+1));
    ex_s = TString(Form("cat%d",i+1));
    RatioPlotsBandV2( data[4+i], p_0b_1mu_c[i], "Data  1#mu", "BKg Pred 1#mu", "PredPlotsAN/Closure_Bkg_R2_1mu_0b_Pred_"+ex_s+SYS, "RSQ", r2B[i], v.at(i),2);
    RatioPlotsBandV2( data[4+i], p_0b_1mu_c_sys[i], "Data  1#mu", "BKg Pred 1#mu", "PredPlotsAN/Closure_Bkg_R2_1mu_0b_Pred_SYS_ClosureOnly"+ex_s+SYS, "RSQ", r2B[i], v.at(i),2);
    RatioPlotsBandV2( data[i], p_0b_0mu[i], "Data  0#mu", "BKg Pred 0#mu", "PredPlotsAN/Bkg_R2_0mu_0b_Pred_"+ex_s+SYS, "RSQ", r2B[i], v.at(i),0);
    RatioPlotsBandV2( data[i], p_0b_0mu_sys[i], "Data  0#mu", "BKg Pred 0#mu", "PredPlotsAN/Bkg_R2_0mu_0b_Pred_SYS_"+ex_s+SYS, "RSQ", r2B[i], v.at(i),0);
    RatioPlotsBandV2( data[i], p_0b_0mu_v2[i], "Data  0#mu", "BKg Pred 0#mu", "PredPlotsAN/Bkg_R2_0mu_0b_Pred_V2"+ex_s+SYS, "RSQ", r2B[i], v.at(i),0);
    RatioPlotsBandV2( data[i], p_0b_0mu_v3[i], "Data  0#mu", "BKg Pred 0#mu", "PredPlotsAN/Bkg_R2_0mu_0b_Pred_V3"+ex_s+SYS, "RSQ", r2B[i], v.at(i),0);
    RatioPlotsBandV2( data[i], p_0b_0mu_v4[i], "Data  0#mu", "BKg Pred 0#mu", "PredPlotsAN/Bkg_R2_0mu_0b_Pred_V4"+ex_s+SYS, "RSQ", r2B[i], v.at(i),0);
    RatioPlotsBandV2( data[i], p_0b_0mu_sys_v4[i], "Data  0#mu", "BKg Pred 0#mu", "PredPlotsAN/Bkg_R2_0mu_0b_Pred_SYS_V4_"+ex_s+SYS, "RSQ", r2B[i], v.at(i),0);


    //After Pre approval Studies
    RatioPlotsBandV2( data[i], p_0b_0mu[i], "Data  0#mu", "BKg Pred 0#mu", "PlotsBkgPred/R2_Pred_"+ex_s, "RSQ", r2B[i], v.at(i),0);
    RatioPlotsBandV2( data[i], p_0b_0mu_v2[i], "Data  0#mu", "BKg Pred 0#mu", "PlotsBkgPred/R2_Pred_"+ex_s+"_V2", "RSQ", r2B[i], v.at(i),0);
    RatioPlotsBandV2( data[i], p_0b_0mu_v3[i], "Data  0#mu", "BKg Pred 0#mu", "PlotsBkgPred/R2_Pred_"+ex_s+"_V3", "RSQ", r2B[i], v.at(i),0);
    RatioPlotsBandV2( data[i], p_0b_0mu_v4[i], "Data  0#mu", "BKg Pred 0#mu", "PlotsBkgPred/R2_Pred_"+ex_s+"_V4", "RSQ", r2B[i], v.at(i),0);
    RatioPlotsBandV2( data[i], p_0b_0mu_v5[i], "Data  0#mu", "BKg Pred 0#mu", "PlotsBkgPred/R2_Pred_"+ex_s+"_V5", "RSQ", r2B[i], v.at(i),0);
    //RatioPlotsBandV2( data[i], p_0b_0mu_sys[i], "Data  0#mu", "BKg Pred 0#mu", "PlotsBkgPred/R2_Pred_"+ex_s+"_SYS", "RSQ", r2B[i], v.at(i),0);
    //RatioPlotsBandV2( data[i], p_0b_0mu_sys_v4[i], "Data  0#mu", "BKg Pred 0#mu", "PlotsBkgPred/R2_Pred_"+ex_s+"_V4_SYS", "RSQ", r2B[i], v.at(i),0);
    //RatioPlotsBandV2( data[i], p_0b_0mu_sys_v5[i], "Data  0#mu", "BKg Pred 0#mu", "PlotsBkgPred/R2_Pred_"+ex_s+"_V5_SYS", "RSQ", r2B[i], v.at(i),0);
    RatioPlotsBandV2( data[4+i], p_0b_1mu_c[i], "Data  1#mu", "BKg Pred 1#mu", "PlotsBkgPred/Closure_Bkg_R2_1mu_0b_Pred_STAT_" + ex_s, "RSQ", r2B[i], v.at(i),2);
    RatioPlotsBandV2( data[4+i], p_0b_1mu_c_sys[i], "Data  1#mu", "BKg Pred 1#mu", "PlotsBkgPred/Closure_Bkg_R2_1mu_0b_Pred_SYS_" + ex_s, "RSQ", r2B[i], v.at(i),2);
    
    
    p_0b_0mu_sys[i]->Write(n1+"_sys");
    n = TString(Form("cat%d_dy_Pred",i+1));
    p_0b_0mu_dy_sys[i]->Write(n);
    n = TString(Form("cat%d_z_Pred",i+1));
    p_0b_0mu_z_sys[i]->Write(n);
    n = TString(Form("cat%d_w_Pred",i+1));
    p_0b_0mu_w_sys[i]->Write(n);
    n = TString(Form("cat%d_tt_Pred",i+1));
    p_0b_0mu_tt_sys[i]->Write(n);
    data[4+i]->Write();
    data[i]->Write();
    n = TString(Form("cat%d_W1mu_Sub",i+1));
    p_0b_1mu_w[i]->Write(n);
    data_copy_1mu[i]->Write();
    n = TString(Form("cat%d_W_PREDICTION",i+1));
    p_0b_1mu_wc[i]->Write(n);
    n = TString(Form("cat%d_Z0mu_to_W1mu",i+1));
    r_0b_0mu_z[i]->Write(n);
    n = TString(Form("cat%d_W0mu_to_W1mu",i+1));
    r_0b_0mu_w[i]->Write(n);
    n = TString(Form("cat%d_DY0mu_to_DY2mu",i+1));
    r_0b_0mu_dy[i]->Write(n);
    n = TString(Form("cat%d_W1mu_to_DY2mu",i+1));
    r_0b_1mu_wc[i]->Write(n);
    n = TString(Form("cat%d_DY1mu_to_DY2mu",i+1));
    r_0b_1mu_dy[i]->Write(n);
    n = TString(Form("pred_Znunu_cat%d",i+1));
    p_0b_0mu_z[i]->Write(n);
    n = TString(Form("mc_Znunu_cat%d",i+1));
    z[i]->Write(n);
    n = TString(Form("pred_Wlnu_cat%d",i+1));
    p_0b_0mu_w[i]->Write(n);
    n = TString(Form("mc_Wlnu_cat%d",i+1));
    w[i]->Write(n);
    n = TString(Form("pred_Znunu_from_2mu_cat%d",i+1));
    p_0b_0mu_z_v2[i]->Write(n);
    n = TString(Form("pred_1MU_cat%d",i+1));
    p_0b_1mu_c[i]->Write(n);
    n = TString(Form("pred_1MU_sys_cat%d",i+1));
    p_0b_1mu_c_sys[i]->Write(n);
    /*
    n = TString(Form("cat%d_SYS",i+1));
    sys[i]->Write(n);
    */
  }
  f1->Close();
  
  
  return 0;

}
