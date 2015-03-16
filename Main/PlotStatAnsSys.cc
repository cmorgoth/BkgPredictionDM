#include <iostream>
#include <vector>
//ROOT INCLUDES
#include "TFile.h"
#include "TH1F.h"
#include "TString.h"

//LOCAL INCLUDES
#include "DM_1DRatio.hh"
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
std::vector<float*> v;

int main()
{

  //Pushing Binning
  v.push_back(c1B);
  v.push_back(c2B);
  v.push_back(c3B);
  v.push_back(c4B);
  
  TH1F* data[4];
  TH1F* p[4];
  TH1F* p_sys[4];
    
  TFile* f  = new TFile("PredFilesAN/MR_Cat_PredV2_NEW_kF_OriginalANA_TEST.root");
  TString name;
  for ( int i = 0; i < 4; i++ )
    {
      //getting data
      name = TString( Form("Data_cat%d_1D_1mu_Box", i+1) );
      data[i] = (TH1F*)f->Get(name);
      //getting prediction(stat only)
      name = TString( Form("pred_1MU_cat%d", i+1) );
      p[i] = (TH1F*)f->Get(name);
      //getting prediction(systematic+stat)
      name = TString( Form("pred_1MU_sys_cat%d", i+1) );
      p_sys[i] = (TH1F*)f->Get(name);
      name = TString( Form("DoubleBandPlots/OneMu_sys_cat_%d", i+1) );
      RatioPlotsBandV3( data[i], p_sys[i], p[i], "Data  1#mu", "BKg Pred 1#mu", name, "RSQ", r2B[i], v.at(i),2);
    }
  
  return 0;
}
