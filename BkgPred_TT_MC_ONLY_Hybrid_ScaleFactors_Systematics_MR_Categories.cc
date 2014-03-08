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
float c1B[] = {0.50, 0.55, 0.60, 0.65, 0.70, 0.75, 0.80, 0.85, 0.9, 0.95, 1.0, 2.5};
float c2B[] = {0.50, 0.575, 0.65, 0.75, 0.85, .950, 2.5};
float c3B[] = {0.50, 0.575, 0.65, 0.75, 0.85, .950, 2.5};
float c4B[] = {0.50, 0.60, 0.70, .950, 2.50};

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
  TFile* F = new TFile("FinalROOTFiles/MRcategories.root");
  
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
    p_0b_1mu_dy[i]->Add(tt[8+i], -1.0);//Subtracting tt 0b 2mu from MC
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
    p_0b_1mu_wc[i] = new TH1F( *data[8+i] );//W prediction for 0b 1mu box Closure Test
    p_0b_1mu_wc[i]->Add(tt[8+i], -1.0);//Subtracting tt 0b 2mu from MC
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
    p_0b_0mu_dy[i] = new TH1F( *data[8+i] );//Drell-Yan prediction for 0b 1mu box
    p_0b_0mu_dy[i]->Add(tt[8+i], -1.0);//Subtracting tt 0b 2mu from MC
    r_0b_0mu_dy[i] = new TH1F( *dy[i] );
    r_0b_0mu_dy[i]->Divide(dy[8+i]);
    p_0b_0mu_dy[i]->Multiply(r_0b_0mu_dy[i]);
  }
  ////////////////////////////////////
  ///////////W 1mu Pred///////////////
  ////////////////////////////////////

  TH1F* p_0b_1mu_w[4];
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
  ///////////Z 0mu Pred///////////////
  ////////////////////////////////////
  
  TH1F* p_0b_0mu_z[4];
  TH1F* r_0b_0mu_z[4];
  for(int i = 0; i < 4; i++){
    p_0b_0mu_z[i] = new TH1F( *p_0b_1mu_w[i] );//W prediction for 0b 0mu box
    r_0b_0mu_z[i] = new TH1F( *z[i] );
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
  
 
  TFile* f1 = new TFile("FinalROOTFiles/MR_Cat_Pred.root","RECREATE");
  TString n, n1, ex_s;
  for(int i = 0; i < 4; i++){
    n = TString(Form("cat%d_1D_1mu_Box_Pred",i+1));
    n1 = TString(Form("cat%d_1D_0mu_Box_Pred",i+1));
    ex_s = TString(Form("cat%d",i+1));
    RatioPlotsBandV2( data[4+i], p_0b_1mu_c[i], "Data  1-#mu BOX", "BKg Pred 1-#mu BOX", "PredPlots/Closure_Bkg_R2_1mu_0b_Pred"+ex_s, "RSQ", r2B[i], v.at(i));
    RatioPlotsBandV2( data[i], p_0b_0mu[i], "Data  0-#mu BOX", "BKg Pred 0-#mu BOX", "PredPlots/Bkg_R2_0mu_0b_Pred"+ex_s, "RSQ", r2B[i], v.at(i));
    p_0b_1mu_c[i]->Write(n);
    p_0b_0mu[i]->Write(n1);
    data[4+i]->Write();
    data[i]->Write();

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
