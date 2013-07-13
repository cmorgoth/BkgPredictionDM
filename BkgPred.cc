#include <iostream>
#include "TROOT.h"
#include "TH1F.h"
#include "TFile.h"
#include "TH2F.h"
#include "DM_1DRatio.hh"
#include "DM_2DRatio.hh"
#include "DM_Base.hh"


const float BaseDM::RSQ_BinArr[] = {0.5, 0.6, 0.7, 0.8, 0.9, 1.0, 2.50};
const float BaseDM::MR_BinArr[] = {200., 300., 400., 500., 600., 900., 3500.};

int main(){
  gROOT->Reset();

  TFile* f = new TFile("1Tight.root");
  TH2F* data_1b_2mu = (TH2F*)f->Get("data_2d_2mu");
  TH2F* data_1b_1mu = (TH2F*)f->Get("data_2d_1mu");
  TH2F* data_1b_0mu = (TH2F*)f->Get("data_2d_0mu");
  TH1F* W_1b_0mu_R2 = (TH1F*)f->Get("W_R2_0mu");
  TH1F* W_1b_1mu_R2 = (TH1F*)f->Get("W_R2_1mu");
  TH2F* tt_1b_2mu = (TH2F*)f->Get("TT_2d_2mu");
  TH2F* tt_1b_1mu = (TH2F*)f->Get("TT_2d_1mu");
  TH2F* tt_1b_0mu = (TH2F*)f->Get("TT_2d_0mu");
  TH1F* tt_1b_1mu_MR = (TH1F*)f->Get("TT_MR_1mu");
  TH1F* tt_1b_0mu_MR = (TH1F*)f->Get("TT_MR_0mu");
  TH1F* tt_1b_1mu_R2 = (TH1F*)f->Get("TT_R2_1mu");
  TH1F* tt_1b_0mu_R2 = (TH1F*)f->Get("TT_R2_0mu");
  data_1b_2mu->Sumw2();
  tt_1b_2mu->Sumw2();
  tt_1b_1mu->Sumw2();
  tt_1b_0mu->Sumw2();

  std::cout << "tt 0-mu1b: " << tt_1b_0mu->Integral() << " tt 1-mu1b: " << tt_1b_1mu->Integral() << std::endl; 
  std::cout << "data 0-mu1b: " << data_1b_0mu->Integral() << " data 1-mu1b: " << data_1b_1mu->Integral() << std::endl;
  std::cout << "W 0-mu1b: " << W_1b_0mu_R2->Integral() << " W 1-mu1b: " << W_1b_1mu_R2->Integral() << std::endl;
  
  TFile* F = new TFile("VetoBtag.root");
  TH2F* tt_0b_2mu = (TH2F*)F->Get("TT_2d_2mu");
  tt_0b_2mu->Sumw2();
  TH1F* tt_2mu_0b_MR = (TH1F*)F->Get("TT_MR_2mu");
  TH1F* tt_2mu_0b_R2 = (TH1F*)F->Get("TT_R2_2mu");
  tt_2mu_0b_MR->Sumw2();
  tt_2mu_0b_R2->Sumw2();

  //TH2F* tt_2mu_ratio = (TH2F*)RatioPlotsTwoD( tt_0b_2mu, tt_1b_2mu, "RatioPlots/tt_2mu", "tt_2mu_2dRatio");
  TH2F* tt_1b_2mu_c1 = new TH2F(*tt_1b_2mu);
  TH2F* tt_1b_2mu_c2 = new TH2F(*tt_1b_2mu);
  TH2F* data_1b_2mu_copy1 = new TH2F(*data_1b_2mu);
  TH2F* data_1b_2mu_copy2 = new TH2F(*data_1b_2mu);
  
  tt_0b_2mu->Divide(tt_1b_2mu);
  tt_1b_1mu->Divide(tt_1b_2mu_c1);
  tt_1b_0mu->Divide(tt_1b_2mu_c2);
  data_1b_2mu->Multiply(tt_0b_2mu);
  data_1b_2mu_copy1->Multiply(tt_1b_1mu);
  data_1b_2mu_copy2->Multiply(tt_1b_0mu);
  double error = -1.0;

  double Integral = data_1b_2mu->IntegralAndError(1, 6, 1, 6, error, "");

  std::cout << "int and error: " << Integral << " " << error << std::endl;
  std::cout << "int: " << data_1b_2mu->Integral() << std::endl;
  
  Integral = data_1b_2mu_copy1->IntegralAndError(1, 6, 1, 6, error, "");
  std::cout << "1-mu int and error: " << Integral << " " << error << std::endl;
  
  Integral = data_1b_2mu_copy2->IntegralAndError(1, 6, 1, 6, error, "");
  std::cout << "0-mu int and error: " << Integral << " " << error << std::endl;
  
  TH1F* pred_MR = (TH1F*)data_1b_2mu->ProjectionX("MR_tt_2mu_0b_pred", 0, -1, "eo");
  TH1F* pred_R2 = (TH1F*)data_1b_2mu->ProjectionY("R2_tt_2mu_0b_pred", 0, -1, "eo");
  
  TH1F* pred_MR_1mu = (TH1F*)data_1b_2mu_copy1->ProjectionX("MR_tt_1mu_pred", 0, -1, "eo");
  TH1F* pred_R2_1mu = (TH1F*)data_1b_2mu_copy1->ProjectionY("R2_tt_1mu_pred", 0, -1, "eo");
  
  TH1F* pred_MR_0mu = (TH1F*)data_1b_2mu_copy2->ProjectionX("MR_tt_0mu_pred", 0, -1, "eo");
  TH1F* pred_R2_0mu = (TH1F*)data_1b_2mu_copy2->ProjectionY("R2_tt_0mu_pred", 0, -1, "eo");
  
  RatioPlots( tt_2mu_0b_MR, pred_MR, "t#bar{t} + MC 2-#mu BOX", "t#bar{t} + Pred 2-#mu BOX", "RatioPlots/tt_MR_2mu_pred", "MR");
  RatioPlots( tt_2mu_0b_R2, pred_R2, "t#bar{t} + MC 2-#mu BOX", "t#bar{t} + Pred 2-#mu BOX", "RatioPlots/tt_R2_2mu_Pred", "RSQ");
  
  RatioPlots( tt_1b_1mu_MR, pred_MR_1mu, "t#bar{t} + MC 1-#mu BOX", "t#bar{t} + Pred 1-#mu BOX", "RatioPlots/tt_MR_1mu_1b_pred", "MR");
  RatioPlots( tt_1b_1mu_R2, pred_R2_1mu, "t#bar{t} + MC 1-#mu BOX", "t#bar{t} + Pred 1-#mu BOX", "RatioPlots/tt_R2_1mu_1b_Pred", "RSQ");
  
  RatioPlots( tt_1b_0mu_MR, pred_MR_0mu, "t#bar{t} + MC 1-#mu BOX", "t#bar{t} + Pred 0-#mu BOX", "RatioPlots/tt_MR_0mu_1b_pred", "MR");
  RatioPlots( tt_1b_0mu_R2, pred_R2_0mu, "t#bar{t} + MC 1-#mu BOX", "t#bar{t} + Pred 0-#mu BOX", "RatioPlots/tt_R2_0mu_1b_Pred", "RSQ");

  f->Close();
  F->Close();

  return 0;

}
