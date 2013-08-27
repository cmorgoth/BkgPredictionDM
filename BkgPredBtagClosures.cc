#include <iostream>
#include "TROOT.h"
#include "TH1F.h"
#include "TFile.h"
#include "TH2F.h"
#include "DM_1DRatio.hh"
#include "DM_2DRatio.hh"
#include "DM_Base.hh"


//const float BaseDM::RSQ_BinArr[] = {0.5, 0.6, 0.7, 0.8, 0.9, 1.0, 2.50};
//const float BaseDM::MR_BinArr[] = {200., 300., 400., 500., 600., 900., 3500.};

//const float BaseDM::RSQ_BinArr[] = {0.5, 0.7, 0.9, 1.1, 2.50};
//const float BaseDM::MR_BinArr[] = {200., 466., 732., 1000., 3500.};

const float BaseDM::RSQ_BinArr[] = {0.5, 0.65, 0.8, 1.0, 2.50};                                                     
const float BaseDM::MR_BinArr[] = {200., 400., 600., 800., 3500.};   

int main(){
  gROOT->Reset();


  /////////////////////////////////////////
  //////////////1Tight Btag///////////////
  ////////////////////////////////////////
  TFile* f = new TFile("BtagFullPromtReco.root");
  TH2F* data_1b_2mu = (TH2F*)f->Get("data_2d_2mu");
  TH2F* data_1b_1mu = (TH2F*)f->Get("data_2d_1mu");
  TH2F* data_1b_0mu = (TH2F*)f->Get("data_2d_0mu");
  
  TH1F* W_1b_0mu_R2 = (TH1F*)f->Get("W_R2_0mu");
  TH1F* W_1b_1mu_R2 = (TH1F*)f->Get("W_R2_1mu");
  TH2F* tt_1b_2mu = (TH2F*)f->Get("TT_2d_2mu");
  TH2F* tt_1b_1mu = (TH2F*)f->Get("TT_2d_1mu");
  TH2F* tt_1b_0mu = (TH2F*)f->Get("TT_2d_0mu");
  TH2F* dy_1b_2mu = (TH2F*)f->Get("dy_2d_2mu");
  TH2F* dy_1b_1mu = (TH2F*)f->Get("dy_2d_1mu");
  TH2F* dy_1b_0mu = (TH2F*)f->Get("dy_2d_0mu");
  TH2F* W_1b_1mu = (TH2F*)f->Get("W_2d_1mu");
  TH2F* W_1b_0mu = (TH2F*)f->Get("W_2d_0mu");
  
  TH1F* tt_1b_1mu_MR = (TH1F*)f->Get("TT_MR_1mu");
  TH1F* tt_1b_0mu_MR = (TH1F*)f->Get("TT_MR_0mu");
  TH1F* tt_1b_1mu_R2 = (TH1F*)f->Get("TT_R2_1mu");
  TH1F* tt_1b_0mu_R2 = (TH1F*)f->Get("TT_R2_0mu");
  TH1F* tt_1b_2mu_MR = (TH1F*)f->Get("TT_MR_2mu");
  TH1F* tt_1b_2mu_R2 = (TH1F*)f->Get("TT_R2_2mu");

  TH1F* data_1b_1mu_MR = (TH1F*)f->Get("data_MR_1mu");
  TH1F* data_1b_0mu_MR = (TH1F*)f->Get("data_MR_0mu");
  TH1F* data_1b_1mu_R2 = (TH1F*)f->Get("data_R2_1mu");
  TH1F* data_1b_0mu_R2 = (TH1F*)f->Get("data_R2_0mu");
  TH1F* data_1b_2mu_MR = (TH1F*)f->Get("data_MR_2mu");
  TH1F* data_1b_2mu_R2 = (TH1F*)f->Get("data_R2_2mu");
  
  
  /////////////////////////////////////////////
  //////////////1Tight 1Med///////////////////
  ///////////////////////////////////////////
    
  TFile* f1 = new TFile("MedandTightBtag_FullPromtReco.root");
  TH2F* data_2b_1mu = (TH2F*)f1->Get("data_2d_1mu");
  TH2F* data_2b_2mu = (TH2F*)f1->Get("data_2d_2mu");

  TH1F* data_2b_1mu_MR = (TH1F*)f1->Get("data_MR_1mu");
  TH1F* data_2b_1mu_R2 = (TH1F*)f1->Get("data_R2_1mu");
  TH2F* tt_2b_1mu = (TH2F*)f1->Get("TT_2d_1mu");
  TH2F* tt_2b_2mu = (TH2F*)f1->Get("TT_2d_2mu");
  TH1F* tt_2b_1mu_MR = (TH1F*)f1->Get("TT_MR_1mu");
  TH1F* tt_2b_1mu_R2 = (TH1F*)f1->Get("TT_R2_1mu");
  
  ///////////////////////////////////////////
  ////////////////Veto Btag/////////////////
  //////////////////////////////////////////
  TFile* F = new TFile("VetoBtagFullPromtReco.root");
  TH2F* tt_0b_2mu = (TH2F*)F->Get("TT_2d_2mu");
  TH2F* tt_0b_1mu = (TH2F*)F->Get("TT_2d_1mu");	
  TH2F* tt_0b_0mu = (TH2F*)F->Get("TT_2d_0mu");
  TH2F* dy_0b_2mu = (TH2F*)F->Get("dy_2d_2mu");
  TH2F* dy_0b_1mu = (TH2F*)F->Get("dy_2d_1mu");	
  TH2F* dy_0b_0mu = (TH2F*)F->Get("dy_2d_0mu");
  TH2F* W_0b_1mu = (TH2F*)F->Get("W_2d_1mu");	
  TH2F* W_0b_0mu = (TH2F*)F->Get("W_2d_0mu");
  TH2F* Z_0b_0mu = (TH2F*)F->Get("Z_2d_0mu");
  TH2F* data_0b_2mu = (TH2F*)F->Get("data_2d_2mu");
  TH2F* data_0b_1mu = (TH2F*)F->Get("data_2d_1mu");	
  TH2F* data_0b_0mu = (TH2F*)F->Get("data_2d_0mu");

  TH1F* tt_0b_2mu_MR = (TH1F*)F->Get("TT_MR_2mu");
  TH1F* tt_0b_2mu_R2 = (TH1F*)F->Get("TT_R2_2mu");
  TH1F* tt_0b_1mu_MR = (TH1F*)F->Get("TT_MR_1mu");
  TH1F* tt_0b_1mu_R2 = (TH1F*)F->Get("TT_R2_1mu");
  TH1F* tt_0b_0mu_MR = (TH1F*)F->Get("TT_MR_0mu");
  TH1F* tt_0b_0mu_R2 = (TH1F*)F->Get("TT_R2_0mu");

  TH1F* dy_0b_2mu_MR = (TH1F*)F->Get("dy_MR_2mu");
  TH1F* dy_0b_2mu_R2 = (TH1F*)F->Get("dy_R2_2mu");
  TH1F* dy_0b_1mu_MR = (TH1F*)F->Get("dy_MR_1mu");
  TH1F* dy_0b_1mu_R2 = (TH1F*)F->Get("dy_R2_1mu");
  TH1F* dy_0b_0mu_MR = (TH1F*)F->Get("dy_MR_0mu");
  TH1F* dy_0b_0mu_R2 = (TH1F*)F->Get("dy_R2_0mu");
  
  TH1F* data_0b_2mu_MR = (TH1F*)F->Get("data_MR_2mu");
  TH1F* data_0b_2mu_R2 = (TH1F*)F->Get("data_R2_2mu");
  TH1F* data_0b_1mu_MR = (TH1F*)F->Get("data_MR_1mu");
  TH1F* data_0b_1mu_R2 = (TH1F*)F->Get("data_R2_1mu");
  TH1F* data_0b_0mu_MR = (TH1F*)F->Get("data_MR_0mu");
  TH1F* data_0b_0mu_R2 = (TH1F*)F->Get("data_R2_0mu");
  
  TH1F* W_0b_1mu_MR = (TH1F*)F->Get("W_MR_1mu");
  TH1F* W_0b_1mu_R2 = (TH1F*)F->Get("W_R2_1mu");
  TH1F* W_0b_0mu_MR = (TH1F*)F->Get("W_MR_0mu");
  TH1F* W_0b_0mu_R2 = (TH1F*)F->Get("W_R2_0mu");
  
  TH1F* Z_0b_0mu_MR = (TH1F*)F->Get("Z_MR_0mu");
  TH1F* Z_0b_0mu_R2 = (TH1F*)F->Get("Z_R2_0mu");
  
  ///////////////////////////////////////////////////
  ///////////////////Prediction 2Mu-0Btag////////////
  /////////////////////////////////////////////////
  
  ///////////////Prediction 2mu0b//////////////////////
  TH2F* ttbar_2mu0b_2mu1b_Ratio = new TH2F(*tt_0b_2mu);//Ratio ttbar MC 2mu0b/2mu1b
  ttbar_2mu0b_2mu1b_Ratio->Divide(tt_1b_2mu);//ttbar Ratio 2mu0b/2mu1b
  TH2F* ratio_DY_tt = new TH2F(*dy_0b_2mu);//Ratio DY2mu0b/ttbar2mu1b
  ratio_DY_tt->Divide(tt_1b_2mu);
  
  //Total data(2mu1b) for prediction
  TH2F* pred_ttbar_2mu0b = new TH2F(*data_1b_2mu);//Data 2mu1b
  TH2F* pred_DY_2mu0b = new TH2F(*data_1b_2mu);//Data 2mu1b
 
  //////////////Actual Prediction 2mu-0Btag/////////////////////
  pred_ttbar_2mu0b->Multiply(ttbar_2mu0b_2mu1b_Ratio);
  pred_DY_2mu0b->Multiply(ratio_DY_tt);
  
  TH2F* Total2mu0bPred = new TH2F(*pred_DY_2mu0b);//Total Prediction (ttbar+DY)
  Total2mu0bPred->Add(pred_ttbar_2mu0b,1.0);  
  
  //////////////////////////////////////////////////
  /////////////2Mu-0Btag prediction and closure////
  ////////////////////////////////////////////////
  double error = -1.0;
  double Integral = Total2mu0bPred->IntegralAndError(1, 6, 1, 6, error, "");
  std::cout << "================int and error Data 2mu0b===============: " << Integral << " " << error << std::endl;
  
  TH1F* pred_MR = (TH1F*)Total2mu0bPred->ProjectionX("MR_tt_2mu_0b_pred", 0, -1, "eo");
  TH1F* pred_R2 = (TH1F*)Total2mu0bPred->ProjectionY("R2_tt_2mu_0b_pred", 0, -1, "eo");
  
  RatioPlotsBand( data_0b_2mu_MR, pred_MR, "t#bar{t} MC 2-#mu BOX", "t#bar{t} Pred 2-#mu BOX", "PredPlots/Closure_MR_2Mu0Btag_pred", "MR");
  RatioPlotsBand( data_0b_2mu_R2, pred_R2, "t#bar{t} MC 2-#mu BOX", "t#bar{t} Pred 2-#mu BOX", "PredPlots/Closure_R2_2Mu0Btag_Pred", "RSQ"); 
  

  ///////////////////////////////////////////////
  ///////////Prediction 2mu-1Btag///////////////
  //////////////////////////////////////////////
  
  TH2F* Ratio_tt2mu1b_tt2mu2b = new TH2F(*tt_1b_2mu);//Ratio ttbar 2Mu-1Btag/2Mu-2Btag
  TH2F* Ratio_dy2mu1b_tt2mu2b = new TH2F(*dy_1b_2mu);//Ratio DY(2Mu-1Btag)/ttbar(2Mu-2Btag)
  
  Ratio_tt2mu1b_tt2mu2b->Divide(tt_2b_2mu);//ttbar(2Mu-2Btag)
  Ratio_dy2mu1b_tt2mu2b->Divide(tt_2b_2mu);//ttbar(2Mu-2Btag)
  
  TH2F* Pred_ttbar_2mu1b = new TH2F(*data_2b_2mu);//Data 2Mu-2Btag
  TH2F* Pred_DY_2mu1b = new TH2F(*data_2b_2mu);//Data 2Mu-2Btag
  Pred_ttbar_2mu1b->Multiply(Ratio_tt2mu1b_tt2mu2b);//TTbar contribution Prediction
  Pred_DY_2mu1b->Multiply(Ratio_dy2mu1b_tt2mu2b);//DY contribution Prediction

  TH2F* Total2mu1bPred = new TH2F(*Pred_ttbar_2mu1b);//Total Prediction DY+ttbar
  Total2mu1bPred->Add(Pred_DY_2mu1b);

  Integral = Total2mu1bPred->IntegralAndError(1, 6, 1, 6, error, "");
  std::cout << "================int and error Data 2mu-1Btag===============: " << Integral << " " << error << std::endl;
  
  TH1F* pred_MR_2mu1b = (TH1F*)Total2mu1bPred->ProjectionX("MR_tt_2mu_1b_pred", 0, -1, "eo");
  TH1F* pred_R2_2mu1b = (TH1F*)Total2mu1bPred->ProjectionY("R2_tt_2mu_1b_pred", 0, -1, "eo");
  
  RatioPlotsBand( data_1b_2mu_MR, pred_MR_2mu1b, "Data 2#mu-1Btag BOX", "Pred 2#mu-1Btag BOX", "PredPlots/Closure_MR_2Mu1Btag_pred", "MR");
  RatioPlotsBand( data_1b_2mu_R2, pred_R2_2mu1b, "Data 2#mu-1Btag BOX", "Pred 2#mu-1Btag BOX", "PredPlots/Closure_R2_2Mu1Btag_Pred", "RSQ"); 
  
  ///////////////////////////////////////////////
  ///////////Prediction 1mu-1Btag///////////////
  //////////////////////////////////////////////
  
  TH2F* Ratio_tt1mu1b_tt1mu2b = new TH2F(*tt_1b_1mu);
  TH2F* Ratio_dy1mu1b_tt1mu2b = new TH2F(*dy_1b_1mu);
  TH2F* Ratio_W1mu1b_tt1mu2b = new TH2F(*W_1b_1mu);

  Ratio_tt1mu1b_tt1mu2b->Divide(tt_2b_1mu);
  Ratio_dy1mu1b_tt1mu2b->Divide(tt_2b_1mu);
  Ratio_W1mu1b_tt1mu2b->Divide(tt_2b_1mu);

  TH2F* Pred_ttbar_1mu1b = new TH2F(*data_2b_1mu);
  TH2F* Pred_DY_1mu1b = new TH2F(*data_2b_1mu);
  TH2F* Pred_W_1mu1b = new TH2F(*data_2b_1mu);
  
  Pred_ttbar_1mu1b->Multiply(Ratio_tt1mu1b_tt1mu2b);
  Pred_DY_1mu1b->Multiply(Ratio_dy1mu1b_tt1mu2b);
  Pred_W_1mu1b->Multiply(Ratio_W1mu1b_tt1mu2b);

  TH2F* Total1mu1bPred = new TH2F(*Pred_ttbar_1mu1b);
  Total1mu1bPred->Add(Pred_DY_1mu1b);
  Total1mu1bPred->Add(Pred_W_1mu1b);

  Integral = Total1mu1bPred->IntegralAndError(1, 6, 1, 6, error, "");
  std::cout << "================int and error Data 1Mu-1Btag===============: " << Integral << " " << error << std::endl;
  
  TH1F* pred_MR_1mu1b = (TH1F*)Total1mu1bPred->ProjectionX("MR_tt_1mu_1b_pred", 0, -1, "eo");
  TH1F* pred_R2_1mu1b = (TH1F*)Total1mu1bPred->ProjectionY("R2_tt_1mu_1b_pred", 0, -1, "eo");
  
  RatioPlotsBand( data_1b_1mu_MR, pred_MR_1mu1b, "Data 1#mu-1Btag BOX", "Pred 1#mu-1Btag BOX", "PredPlots/Closure_MR_1mu1b_pred", "MR");
  RatioPlotsBand( data_1b_1mu_R2, pred_R2_1mu1b, "Data 1#mu-1Btag BOX", "Pred 1#mu-1Btag BOX", "PredPlots/Closure_R2_1mu1b_Pred", "RSQ"); 
  

  f->Close();
  f1->Close();
  F->Close();

  return 0;

}
