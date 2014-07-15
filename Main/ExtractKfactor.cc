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

int main(){
  
  gROOT->Reset();
  //TFile* F = new TFile("FinalROOT_May2014/VetoBtag_May_2014_Original.root");
  //TFile* F = new TFile("FinalROOTFiles/VetoBtag_May_2014_OriginalTrigger_OnlyNoMU.root");
  TFile* F = new TFile("FinalROOTFiles/VetoBtag_May_2014_OriginalTrigger_NoMU_and_Mu_NOisr.root");
  
  
  ///////////////////////////////////////////////////////
  ///////////////Creating MR categories binned in R2/////
  //////////////////////////////////////////////////////
  TH1F* dy[12];
  TH1F* z[12];
  TH1F* w[12];
  TH1F* tt[12];
  TH1F* data[12];
  
  double tt_k2factor = 1.8034;
  //double tt_k2factor = 1.0;

  for(int i = 0; i < 3; i++){
    for(int j = 1; j <= 4; j++){
      TString name1 = TString(Form("DY_cat%d_1D_%dmu_Box",j,i));
      dy[4*i+j-1] = (TH1F*)F->Get(name1);
      
      TString name2 = TString(Form("Z_cat%d_1D_%dmu_Box",j,i));
      z[4*i+j-1] = (TH1F*)F->Get(name2);
      
      TString name3 = TString(Form("W_cat%d_1D_%dmu_Box",j,i));
      w[4*i+j-1] = (TH1F*)F->Get(name3);
      
      TString name4 = TString(Form("TT_L_cat%d_1D_%dmu_Box",j,i));
      //TString name4 = TString(Form("TT_cat%d_1D_%dmu_Box",j,i));
      tt[4*i+j-1] = (TH1F*)F->Get(name4);
      tt[4*i+j-1]->Scale(tt_k2factor);
      
      TString name5 = TString(Form("Data_cat%d_1D_%dmu_Box",j,i));
      data[4*i+j-1] = (TH1F*)F->Get(name5);
    }
  }

  
  for(int i = 0; i < 4; i++){
    std::cout << "===== Cat " << i+1 << " ====="<< std::endl;
    double Z_kf = (data[i+8]->Integral())/(dy[i+8]->Integral()+tt[i+8]->Integral());
    double W_kf = (data[i+4]->Integral())/(Z_kf*(dy[i+4]->Integral())+tt[i+4]->Integral()+w[i+4]->Integral());
    std::cout << "Z_kf: " << Z_kf << std::endl;
    std::cout << "W_kf: " << W_kf << std::endl;
  }
  
  return 0;

}
