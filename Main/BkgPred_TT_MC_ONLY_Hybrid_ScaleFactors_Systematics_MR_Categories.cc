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

/*
float c1B[] = {0.50, 0.55, 0.60, 0.655, 0.705, 0.760, 0.81, 0.86, 0.91, 0.96, 1.05, 1.2};
float c2B[] = {0.50, 0.575, 0.665, 0.76, 0.86, .945, 1.2};
float c3B[] = {0.50, 0.575, 0.65, 0.75, 0.85, .950, 1.2};
float c4B[] = {0.50, 0.60, 0.70, .950, 1.20};
*/

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
  //TFile* F = new TFile("FinalROOTFiles/MRcategoriesV2.root");//Original File Before ALL SYSTEMATICS
  
  //TFile* F = new TFile("FinalROOT_May2014/VetoBtag_May_2014.root");
  TFile* F = new TFile("FinalROOT_May2014/VetoBtag_May_2014_Original.root");
  
  //TFile* F = new TFile("FinalROOT_May2014/VetoBtag_May_2014_Fixe2DHLT.root");
  //TFile* F = new TFile("FinalROOT_May2014/VetoBtag_May_2014_NewTrigger.root");
  //TFile* F = new TFile("FinalROOT_May2014/VetoBtag_May_2014_NewTrigger_ISR_off.root");
  //TFile* F = new TFile("FinalROOT_May2014/VetoBtag_May_2014_SingleTrigger.root");
  //TFile* F = new TFile("FinalROOT_May2014/VetoBtag_May_2014_ISR_Up.root");
  //TFile* F = new TFile("FinalROOT_May2014/VetoBtag_May_2014_ISR_Down.root");
  //TFile* F = new TFile("FinalROOT_May2014/VetoBtag_May_2014_JES_Down.root");
  //TFile* F = new TFile("FinalROOT_May2014/VetoBtag_May_2014_btag_Up.root");
  //TFile* F = new TFile("FinalROOT_May2014/VetoBtag_May_2014_btag_Down.root");
  //TFile* F = new TFile("FinalROOT_May2014/VetoBtag_May_2014_mu_Up.root");
  //TFile* F = new TFile("FinalROOT_May2014/VetoBtag_May_2014_mu_Down.root");

  std::cout << "deb 0" << std::endl;
  v.push_back(c1B);
  v.push_back(c2B);
  v.push_back(c3B);
  v.push_back(c4B);
  
  v_tt.push_back(c1B_tt);
  v_tt.push_back(c2B_tt);
  v_tt.push_back(c3B_tt);
  v_tt.push_back(c4B_tt);
  ///////////////////////////////////////////////////////
  ///////////////Creating MR categories binned in R2/////
  //////////////////////////////////////////////////////
  TH1F* dy[12];
  TH1F* z[12];
  TH1F* w[12];
  TH1F* tt[12];
  TH1F* data[12];
  std::cout << "deb 1" << std::endl;
  double tt_k2factor = 1.8034;
  double z_k2factor = 1.1973;
  double w_k2factor = 1.2455;

  //double tt_k2factor = 1.0;
  //double z_k2factor = 1.1894;
  //double w_k2factor = 0.8567;
  
  for(int i = 0; i < 3; i++){
    for(int j = 1; j <= 4; j++){
      std::cout << "deb 1.1" << std::endl;
      TString name1 = TString(Form("DY_cat%d_1D_%dmu_Box",j,i));
      std::cout << "deb 1.2" << std::endl;
      dy[4*i+j-1] = (TH1F*)F->Get(name1);
      std::cout << "deb 1.3" << std::endl;
      dy[4*i+j-1]->Scale(z_k2factor);
      TString name2 = TString(Form("Z_cat%d_1D_%dmu_Box",j,i));
      z[4*i+j-1] = (TH1F*)F->Get(name2);
       std::cout << "deb 1.4" << std::endl;
      z[4*i+j-1]->Scale(z_k2factor);
      TString name3 = TString(Form("W_cat%d_1D_%dmu_Box",j,i));
      w[4*i+j-1] = (TH1F*)F->Get(name3);
      std::cout << "deb 1.5" << std::endl;
      w[4*i+j-1]->Scale(w_k2factor);
      TString name4 = TString(Form("TT_L_cat%d_1D_%dmu_Box",j,i));
      //TString name4 = TString(Form("TT_cat%d_1D_%dmu_Box",j,i));
      tt[4*i+j-1] = (TH1F*)F->Get(name4);
      std::cout << "deb 1.6" << std::endl;
      tt[4*i+j-1]->Scale(tt_k2factor);
      std::cout << "deb 1.6.1" << std::endl;
      TString name5 = TString(Form("Data_cat%d_1D_%dmu_Box",j,i));
      std::cout << "deb 1.6.2" << std::endl;
      data[4*i+j-1] = (TH1F*)F->Get(name5);
       std::cout << "deb 1.7" << std::endl;
    }
  }
  std::cout << "debug0" << std::endl;
  ///////////////////////////////////////////////////////
  ////////////////ttbar kfactors and SYS/////////////////
  //////////////////////////////////////////////////////
  //TFile* ftt = new TFile("Pred_Files/Two_TT_Cat_PredV2.root"); 
  TFile* ftt = new TFile("Pred_Files/TwoBtag_May_2014_Nominal.root");
  
  std::cout << "debug1" << std::endl;
  TH1F* sys_tt_0mu[4];
  TH1F* kf_tt_0mu[4];
  TH1F* sys_tt_1mu[4];
  TH1F* kf_tt_1mu[4];
  for(int i = 0; i < 4; i++){
    TString nm(Form("sys_cat_%d_0mu", i+1));
    std::cout << nm << std::endl;
    sys_tt_0mu[i] = (TH1F*)ftt->Get(nm);
    nm = Form("cat_%d_0mu_kf", i+1);
    std::cout << nm << std::endl;
    kf_tt_0mu[i] = (TH1F*)ftt->Get(nm);
    
    nm = Form("sys_cat_%d_1mu", i+1);
    std::cout << nm << std::endl;
    sys_tt_1mu[i] = (TH1F*)ftt->Get(nm);
    nm = Form("cat_%d_1mu_kf", i+1);
    std::cout << nm << std::endl;
    kf_tt_1mu[i] = (TH1F*)ftt->Get(nm);
  }
  std::cout << "debug2" << std::endl;
  //Include ttbar systematics and kFactor
  for(int i = 0; i < 4; i++){
    std::cout << "debug2.01 " << kf_tt_0mu[i]->GetBinContent(1) << std::endl;
    tt[i]->Scale(kf_tt_0mu[i]->GetBinContent(1));
    std::cout << "debug2.02" << std::endl;
    tt[i+4]->Scale(kf_tt_1mu[i]->GetBinContent(1));
    std::cout << "debug2.1" << std::endl;
    for(int k = 1; k <= tt[i]->GetNbinsX(); k++){
      int bn = -1;
      if(i == 0 && tt[i]->GetBinCenter(k) > 0.8){
	bn = 7;
      }else if(i != 0 && tt[i]->GetBinCenter(k) > 0.75){
	bn = 4;
      }else{
	bn = k;
      }
      std::cout << "debug2.2" << std::endl;
      double err = sqrt(pow(tt[i]->GetBinError(k),2) + 
			pow(tt[i]->GetBinContent(k)*sys_tt_0mu[i]->GetBinContent(bn),2));
      tt[i]->SetBinError(k,err);
      //1mu
      std::cout << "debug2.3" << std::endl;
      err = sqrt(pow(tt[i+4]->GetBinError(k),2) + 
		 pow(tt[i+4]->GetBinContent(k)*sys_tt_1mu[i]->GetBinContent(bn),2));
      tt[i+4]->SetBinError(k,err); 
    }
  }
  std::cout << "debug3" << std::endl;
  
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
    p_0b_1mu_dy[i] = new TH1F( *data[8+i] );//Drell-Yan prediction for 0b 1mu box
    p_0b_1mu_dy[i]->Sumw2();
    p_0b_1mu_dy[i]->Add(tt[8+i], -1.0);//Subtracting tt 0b 2mu from MC
    r_0b_1mu_dy[i] = new TH1F( *dy[4+i] );
    r_0b_1mu_dy[i]->Sumw2();
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
    p_0b_1mu_wc[i] = new TH1F( *data[8+i] );//W prediction for 0b 1mu box Closure Test
    p_0b_1mu_wc[i]->Sumw2();
    p_0b_1mu_wc[i]->Add(tt[8+i], -1.0);//Subtracting tt 0b 2mu from MC
    r_0b_1mu_wc[i] = new TH1F( *w[4+i] );
    r_0b_1mu_wc[i]->Sumw2();
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
    p_0b_1mu_c[i]->Sumw2();
    p_0b_1mu_c[i]->Add(p_0b_1mu_dy[i]);
    p_0b_1mu_c[i]->Add(tt[4+i]);
  }
 
  //////////////////////////////////////
  ///////////DY 0mu Pred///////////////
  /////////////////////////////////////
  TH1F* p_0b_0mu_dy[4];
  TH1F*  r_0b_0mu_dy[4];
  for(int i = 0; i < 4; i++){
    p_0b_0mu_dy[i] = new TH1F( *data[8+i] );//Drell-Yan prediction for 0b 1mu box
    p_0b_0mu_dy[i]->Sumw2();
    p_0b_0mu_dy[i]->Add(tt[8+i], -1.0);//Subtracting tt 0b 2mu from MC
    r_0b_0mu_dy[i] = new TH1F( *dy[i] );
    r_0b_0mu_dy[i]->Sumw2();
    r_0b_0mu_dy[i]->Divide(dy[8+i]);
    p_0b_0mu_dy[i]->Multiply(r_0b_0mu_dy[i]);
  }
  ////////////////////////////////////
  ///////////W 1mu Pred///////////////
  ////////////////////////////////////
  TH1F* data_copy_1mu[4];
  TString nd;
  for(int i = 0; i < 4; i++){
    nd = TString(Form("cat%d_data_Ori",i+1));
    data_copy_1mu[i] = new TH1F(nd, nd, r2B[i], v.at(i));
    for(int j = 1; j <= data[4+i]->GetNbinsX(); j++){
      data_copy_1mu[i]->SetBinContent(j,data[4+i]->GetBinContent(j));
      data_copy_1mu[i]->SetBinError(j,data[4+i]->GetBinError(j));
    }
  }
  
  TH1F* p_0b_1mu_w[4];
  TH1F* r_0b_1mu_w[4];

  for(int i = 0; i < 4; i++){
    p_0b_1mu_w[i] = new TH1F( *data[4+i] );//W prediction for 0b 1mu box
    //p_0b_1mu_w[i] = new TH1F(*p_0b_1mu_wc[i]);
    p_0b_1mu_w[i]->Sumw2();
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
    p_0b_0mu_w[i]->Sumw2();
    r_0b_0mu_w[i] = new TH1F( *w[i] );
    r_0b_0mu_w[i]->Sumw2();
    r_0b_0mu_w[i]->Divide(w[i+4]);
    p_0b_0mu_w[i]->Multiply(r_0b_0mu_w[i]);
  }
  
  ////////////////////////////////////
  ///////////Z 0mu Pred///////////////
  ////////////////////////////////////
  
  TH1F* p_0b_0mu_z[4];
  TH1F* r_0b_0mu_z[4];
  for(int i = 0; i < 4; i++){
    p_0b_0mu_z[i] = new TH1F( *p_0b_1mu_w[i] );//Z prediction for 0b 0mu box
    p_0b_0mu_z[i]->Sumw2();
    r_0b_0mu_z[i] = new TH1F( *z[i] );
    r_0b_0mu_z[i]->Sumw2();
    r_0b_0mu_z[i]->Divide(w[i+4]);
    p_0b_0mu_z[i]->Multiply(r_0b_0mu_z[i]);
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
  
  //Print Out Prediction in different cat
   for(int i = 0; i < 4; i++){
     std::cout << "==== Cat " << i+1 << " ====" << std::endl;
     std::cout << "W: " << p_0b_0mu_w[i]->Integral() << std::endl;
     std::cout << "Z(nunu): " << p_0b_0mu_z[i]->Integral() << std::endl;
     std::cout << "Z(ll): " << p_0b_0mu_dy[i]->Integral() << std::endl;
     std::cout << "tt: "  << tt[i]->Integral() << std::endl;
     std::cout << "TOTAL: "  << p_0b_0mu[i]->Integral() << std::endl;
  }

  /////////////////////////////////////////////
  //////////Include Systematics////////////////
  /////////////////////////////////////////////

  TH1F* sys[4];
  for(int i = 0; i < 4; i++){
    TString s(Form("sys_cat%d",i+1)); 
    sys[i] = new TH1F(s,s, r2B[i], v.at(i));
  }
  //Get Systematics
  for(int i = 0; i < 4; i++){
    for(int j = 1; j <= p_0b_1mu_c[i]->GetNbinsX(); j++){
      double diff = fabs(p_0b_1mu_c[i]->GetBinContent(j) - data[i+4]->GetBinContent(j))/p_0b_1mu_c[i]->GetBinContent(j);
      sys[i]->SetBinContent(j, diff);
    }
  }
    
  //Apply Systematics
  TH1F* p_0b_1mu_c_sys[4];
  TH1F* p_0b_0mu_sys[4];
  TH1F* p_0b_0mu_dy_sys[4];
  TH1F* p_0b_0mu_z_sys[4];
  TH1F* p_0b_0mu_w_sys[4];
  TH1F* p_0b_0mu_tt_sys[4];
  for(int i = 0; i < 4; i++){
    p_0b_1mu_c_sys[i] = new TH1F(*p_0b_1mu_c[i]);
    
    p_0b_0mu_dy_sys[i] = new TH1F(*p_0b_0mu_dy[i]);
    p_0b_0mu_z_sys[i] = new TH1F(*p_0b_0mu_z[i]);
    p_0b_0mu_w_sys[i] = new TH1F(*p_0b_0mu_w[i]);
    p_0b_0mu_tt_sys[i] = new TH1F(*tt[i]);
    for(int j = 1; j <= p_0b_1mu_c[i]->GetNbinsX(); j++){
      double err = 1.0*sqrt(pow(p_0b_1mu_c_sys[i]->GetBinContent(j)*sys[i]->GetBinContent(j),2) + pow(p_0b_1mu_c_sys[i]->GetBinError(j),2) );
      //p_0b_1mu_c_sys[i]->SetBinError(j, err);
      
      //0-mu
      err = 1.0*sqrt(pow(p_0b_0mu_dy_sys[i]->GetBinContent(j)*sys[i]->GetBinContent(j),2) + pow(p_0b_0mu_dy_sys[i]->GetBinError(j),2));
      //err = 1.0*p_0b_0mu_dy_sys[i]->GetBinContent(j)*sys[i]->GetBinContent(j);
      //err = 1.0*sqrt(pow(p_0b_0mu_dy_sys[i]->GetBinContent(j)*sys[i]->GetBinContent(j),2) + pow(p_0b_1mu_c_sys[i]->GetBinError(j),2) );
      //err = 0.20*p_0b_0mu_dy_sys[i]->GetBinContent(j);
      p_0b_0mu_dy_sys[i]->SetBinError(j, err);
      
      err = 1.0*sqrt(pow(p_0b_0mu_z_sys[i]->GetBinContent(j)*sys[i]->GetBinContent(j),2) + pow(p_0b_0mu_z_sys[i]->GetBinError(j),2));
      //err = 1.0*sqrt(pow(p_0b_0mu_z_sys[i]->GetBinContent(j)*sys[i]->GetBinContent(j),2) + pow(p_0b_1mu_c_sys[i]->GetBinError(j),2) );
      //err = 1.0*p_0b_0mu_z_sys[i]->GetBinContent(j)*sys[i]->GetBinContent(j);
      //err = 0.20*p_0b_0mu_z_sys[i]->GetBinContent(j);
      p_0b_0mu_z_sys[i]->SetBinError(j, err);
      
      err = 1.0*sqrt(pow(p_0b_0mu_w_sys[i]->GetBinContent(j)*sys[i]->GetBinContent(j),2) + pow(p_0b_0mu_w_sys[i]->GetBinError(j),2));
      //err = 1.0*sqrt(pow(p_0b_0mu_w_sys[i]->GetBinContent(j)*sys[i]->GetBinContent(j),2) + pow(p_0b_1mu_c_sys[i]->GetBinError(j),2) );
      //err = 1.0*p_0b_0mu_w_sys[i]->GetBinContent(j)*sys[i]->GetBinContent(j);
      //err = 0.20*p_0b_0mu_w_sys[i]->GetBinContent(j);
      p_0b_0mu_w_sys[i]->SetBinError(j, err);
      //err = 2*p_0b_0mu_tt_sys[i]->GetBinError(j);
      //p_0b_0mu_tt_sys[i]->SetBinError(j, err);
      /*
      if( i == 0 && (j == 6 || j == 11)){
	err = 0.30*p_0b_0mu_dy_sys[i]->GetBinContent(j);
	p_0b_0mu_dy_sys[i]->SetBinError(j, err);
	err = 0.30*p_0b_0mu_z_sys[i]->GetBinContent(j);
	p_0b_0mu_z_sys[i]->SetBinError(j, err);
	err = 0.30*p_0b_0mu_w_sys[i]->GetBinContent(j);
	p_0b_0mu_w_sys[i]->SetBinError(j, err);
      }
      
      if( i == 1 && (j == 2 || j == 5)){
	err = 0.30*p_0b_0mu_dy_sys[i]->GetBinContent(j);
	p_0b_0mu_dy_sys[i]->SetBinError(j, err);
	err = 0.30*p_0b_0mu_z_sys[i]->GetBinContent(j);
	p_0b_0mu_z_sys[i]->SetBinError(j, err);
	err = 0.30*p_0b_0mu_w_sys[i]->GetBinContent(j);
	p_0b_0mu_w_sys[i]->SetBinError(j, err);
      }
      */
    }
    p_0b_0mu_sys[i] = new TH1F(*p_0b_0mu_dy_sys[i]);
    p_0b_0mu_sys[i]->Sumw2();
    p_0b_0mu_sys[i]->Add(p_0b_0mu_z_sys[i]);
    p_0b_0mu_sys[i]->Add(p_0b_0mu_w_sys[i]);
    p_0b_0mu_sys[i]->Add(p_0b_0mu_tt_sys[i]);
  }
  
  //Print Out Prediction in different cat after systematics
  double Nerr = -1.0;
  double Nbkg = -1.0;
  for(int i = 0; i < 4; i++){
    std::cout << "==== Cat " << i+1 << " ====" << std::endl;
    Nbkg = p_0b_0mu_w_sys[i]->IntegralAndError(1,p_0b_0mu_w_sys[i]->GetNbinsX(),Nerr,"");
    std::cout << "W: " << Nbkg << " /\pm " << Nerr << std::endl;
    Nbkg = p_0b_0mu_z_sys[i]->IntegralAndError(1,p_0b_0mu_z_sys[i]->GetNbinsX(),Nerr,"");
    std::cout << "Z(nunu): " << Nbkg << " /\pm " << Nerr << std::endl;
    Nbkg = p_0b_0mu_dy_sys[i]->IntegralAndError(1,p_0b_0mu_dy_sys[i]->GetNbinsX(),Nerr,"");
    std::cout << "Z(ll): " << Nbkg << " /\pm " << Nerr << std::endl;
    Nbkg = p_0b_0mu_tt_sys[i]->IntegralAndError(1,p_0b_0mu_tt_sys[i]->GetNbinsX(),Nerr,"");
    std::cout << "tt: "  << Nbkg << " /\pm " << Nerr << std::endl;
    Nbkg = p_0b_0mu_sys[i]->IntegralAndError(1,p_0b_0mu_sys[i]->GetNbinsX(),Nerr,"");
    std::cout << "TOTAL: " << Nbkg << " /\pm " << Nerr << std::endl;
    std::cout << "Data: " << data[i]->Integral() << std::endl;
  }

  
  
  
  TString n, n1, ex_s;
  TString SYS = "_NEWv4";
  TFile* f1 = new TFile("Pred_Files/MR_Cat_PredV2"+SYS+".root","RECREATE");
  for(int i = 0; i < 4; i++){
    n = TString(Form("cat%d_1D_1mu_Box_Pred",i+1));
    n1 = TString(Form("cat%d_1D_0mu_Box_Pred",i+1));
    ex_s = TString(Form("cat%d",i+1));
    RatioPlotsBandV2( data[4+i], p_0b_1mu_c[i], "Data  1#mu", "BKg Pred 1#mu", "PredPlots/Closure_Bkg_R2_1mu_0b_Pred_V2"+ex_s+SYS, "RSQ", r2B[i], v.at(i),2);
    RatioPlotsBandV2( data[i], p_0b_0mu[i], "Data  0#mu", "BKg Pred 0#mu", "PredPlots/Bkg_R2_0mu_0b_Pred_V2"+ex_s+SYS, "RSQ", r2B[i], v.at(i),0);
    RatioPlotsBandV2( data[4+i], p_0b_1mu_c_sys[i], "Data  1#mu", "BKg Pred 1#mu", "PredPlots/Closure_Bkg_R2_1mu_0b_Pred_SYS_V2"+ex_s+SYS, "RSQ", r2B[i], v.at(i),2);
    RatioPlotsBandV2( data[i], p_0b_0mu_sys[i], "Data  0#mu", "BKg Pred 0#mu", "PredPlots/Bkg_R2_0mu_0b_Pred_SYS_V2"+ex_s+SYS, "RSQ", r2B[i], v.at(i),0);
    //p_0b_1mu_c[i]->Write(n);
    //p_0b_1mu_c_sys[i]->Write(n+"_sys");
    //p_0b_0mu[i]->Write(n1);
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
    //data[8+i]->Write();
    //w[4+i]->Write();
    //dy[8+i]->Write();
    //dy[4+i]->Write();
    //tt[8+i]->Write();
    //tt[4+i]->Write();
  }
  f1->Close();
 
  
  return 0;

}
