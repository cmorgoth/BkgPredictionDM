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
  TH1F* data_2b_1mu_MR = (TH1F*)f1->Get("data_MR_1mu");
  TH1F* data_2b_1mu_R2 = (TH1F*)f1->Get("data_R2_1mu");
  TH2F* tt_2b_1mu = (TH2F*)f1->Get("TT_2d_1mu");
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
  
  /////////////////////////////////////////////////////
  ////////////////////ttbar-2Mu-0Btag Pred////////////
  ////////////////////////////////////////////////////
  TH2F* ttbar_2mu0b_2mu1b_Ratio = new TH2F(*tt_0b_2mu);//Ratio ttbar MC 2mu0b/2mu1b
  ttbar_2mu0b_2mu1b_Ratio->Divide(tt_1b_2mu);//ttbar Ratio 2mu0b/2mu1b
  //Total data(2mu1b) for prediction
  TH2F* pred_ttbar_2mu0b = new TH2F(*data_1b_2mu);//Data 2mu1b
  //////////////Actual Prediction ttbar 2mu-0Btag/////////////////////
  pred_ttbar_2mu0b->Multiply(ttbar_2mu0b_2mu1b_Ratio);

  
  /////////////////////////////////////////////////////
  ////////////////////ttbar-1Mu-0Btag Pred////////////
  ////////////////////////////////////////////////////
  TH2F* ttbar_1mu0b_1mu2b_Ratio = new TH2F(*tt_0b_1mu);//Ratio ttbar MC 1mu0b/1mu2b
  ttbar_1mu0b_1mu2b_Ratio->Divide(tt_2b_1mu);//ttbar Ratio 1mu0b/1mu2b
  //Total data(1mu2b) for prediction
  TH2F* pred_ttbar_1mu0b = new TH2F(*data_2b_1mu);//Data 1mu2b
  //////////////Actual Prediction ttbar 1mu-0Btag/////////////////////
  pred_ttbar_1mu0b->Multiply(ttbar_1mu0b_1mu2b_Ratio);

  /////////////////////////////////////////////////////
  ////////////////////ttbar-1Mu-0Btag Pred////////////
  ////////////////////////////////////////////////////
  TH2F* ttbar_0mu0b_1mu2b_Ratio = new TH2F(*tt_0b_0mu);//Ratio ttbar MC 0mu0b/1mu2b
  ttbar_0mu0b_1mu2b_Ratio->Divide(tt_2b_1mu);//ttbar Ratio 0mu0b/1mu2b
  //Total data(1mu2b) for prediction
  TH2F* pred_ttbar_0mu0b = new TH2F(*data_2b_1mu);//Data 1mu2b
  //////////////Actual Prediction ttbar 0mu-0Btag/////////////////////
  pred_ttbar_0mu0b->Multiply(ttbar_0mu0b_1mu2b_Ratio);
  
  
  ///////////////////////////////////////////////////
  /////////////////////Signal Prediction////////////
  /////////////////////////////////////////////////

  double Integral = 0.0;
  double error = 0.0;


  //////////////////////////////////////////
  ////////Drell-Yan 1 mu box///////////////
  /////////////////////////////////////////
  
  RatioPlots( dy_0b_1mu_MR, dy_0b_2mu_MR, "Z/#gamma^{*} MC 1-#mu BOX", "Z/#gamma^{*} MC 2-#mu BOX", "RatioPlots/dy_MR_1mu_to_2mu", "MR");
  RatioPlots( dy_0b_1mu_R2, dy_0b_2mu_R2, "Z/#gamma^{*} MC 1-#mu BOX", "Z/#gamma^{*} MC 2-#mu BOX", "RatioPlots/dy_R2_1mu_to_2mu", "RSQ");
  TH2F* p_0b_1mu_dy = new TH2F( *data_0b_2mu );//Drell-Yan prediction for 0b 1mu box
  p_0b_1mu_dy->Add(pred_ttbar_2mu0b, -1.0);//Subtracting tt 0b 2mu prediction
  //p_0b_1mu_dy->Add(tt_0b_2mu, -1.0);//Subtracting tt 0b 2mu from MC
  TH2F* r_0b_1mu_dy = new TH2F( *dy_0b_1mu );
  r_0b_1mu_dy->Divide(dy_0b_2mu);
  p_0b_1mu_dy->Multiply(r_0b_1mu_dy);
  Integral = p_0b_1mu_dy->IntegralAndError(1, 6, 1, 6, error, "");
  std::cout << "---------1)-------" << std::endl;
  std::cout << "Drell-Yan Prediction 0b 1mu box: " << Integral << " error: " << error << std::endl;
  TH1F* pred_MR_dy_0b_1mu = (TH1F*)p_0b_1mu_dy->ProjectionX("MR_dy_1mu_0b_pred", 0, -1, "eo");
  TH1F* pred_R2_dy_0b_1mu = (TH1F*)p_0b_1mu_dy->ProjectionY("R2_dy_1mu_0b_pred", 0, -1, "eo");
  RatioPlots( dy_0b_1mu_MR, pred_MR_dy_0b_1mu, "Z/#gamma^{*} MC 1-#mu BOX", "Z/#gamma^{*} Pred 1-#mu BOX", "PredPlots/dy_MR_1mu_0b_pred", "MR");
  RatioPlots( dy_0b_1mu_R2, pred_R2_dy_0b_1mu, "Z/#gamma^{*} MC 1-#mu BOX", "Z/#gamma^{*} Pred 1-#mu BOX", "PredPlots/dy_R2_1mu_0b_Pred", "RSQ");
  
  ////////////////////////////////////////
  //////////////////W 1mu/////////////////
  ////////////////////////////////////////
  TH2F* p_0b_1mu_W = new TH2F( *data_0b_1mu );//W prediction for 0b 1mu box
  p_0b_1mu_W->Add(pred_ttbar_1mu0b, -1.0);//Subtraction tt 1mu prediction
  //p_0b_1mu_W->Add(tt_0b_1mu, -1.0);//Subtraction tt 1mu from MC
  p_0b_1mu_W->Add(p_0b_1mu_dy, -1.0);//Subtraction Drell-Yan 1mu prediction
  Integral = p_0b_1mu_W->IntegralAndError(1, 6, 1, 6, error, "");
  std::cout << "---------3)-------" << std::endl;
  std::cout << "W Prediction 0b 1mu box: " << Integral << " error: " << error << std::endl;
  TH1F* pred_MR_W_0b_1mu = (TH1F*)p_0b_1mu_W->ProjectionX("MR_W_1mu_0b_pred", 0, -1, "eo");
  TH1F* pred_R2_W_0b_1mu = (TH1F*)p_0b_1mu_W->ProjectionY("R2_W_1mu_0b_pred", 0, -1, "eo");
  RatioPlots( W_0b_1mu_MR, pred_MR_W_0b_1mu, "W MC 1-#mu BOX", "W Pred 1-#mu BOX", "PredPlots/W_MR_1mu_0b_pred_ttMC", "MR");
  RatioPlots( W_0b_1mu_R2, pred_R2_W_0b_1mu, "W MC 1-#mu BOX", "W Pred 1-#mu BOX", "PredPlots/W_R2_1mu_0b_Pred_ttMC", "RSQ");
  
  ///////////////////////////////////
  /////////Drell-Yan 0 mu box////////
  //////////////////////////////////
  RatioPlots( dy_0b_0mu_MR, dy_0b_2mu_MR, "Z/#gamma^{*} MC 0-#mu BOX", "Z/#gamma^{*} MC 2-#mu BOX", "RatioPlots/dy_MR_0mu_to_2mu", "MR");
  RatioPlots( dy_0b_0mu_R2, dy_0b_2mu_R2, "Z/#gamma^{*} MC 0-#mu BOX", "Z/#gamma^{*} MC 2-#mu BOX", "RatioPlots/dy_R2_0mu_to_2mu", "RSQ");
  TH2F* p_0b_0mu_dy = new TH2F( *data_0b_2mu );//Drell-Yan prediction for 0b 0mu box
  p_0b_0mu_dy->Add(pred_ttbar_2mu0b, -1.0);//Subtracting tt 0b 2mu prediction
  //p_0b_0mu_dy->Add(tt_0b_2mu, -1.0);//Subtracting tt 0b 2mu from MC
  TH2F* r_0b_0mu_dy = new TH2F( *dy_0b_0mu );
  r_0b_0mu_dy->Divide(dy_0b_2mu);
  p_0b_0mu_dy->Multiply(r_0b_0mu_dy);
  Integral = p_0b_0mu_dy->IntegralAndError(1, 6, 1, 6, error, "");
  std::cout << "---------4)-------" << std::endl;
  std::cout << "Drell-Yan Prediction 0b 0mu box: " << Integral << " error: " << error << std::endl;
  TH1F* pred_MR_dy_0b_0mu = (TH1F*)p_0b_0mu_dy->ProjectionX("MR_dy_0mu_0b_pred", 0, -1, "eo");
  TH1F* pred_R2_dy_0b_0mu = (TH1F*)p_0b_0mu_dy->ProjectionY("R2_dy_0mu_0b_pred", 0, -1, "eo");
  RatioPlots( dy_0b_0mu_MR, pred_MR_dy_0b_0mu, "Z/#gamma^{*} MC 0-#mu BOX", "Z/#gamma^{*} Pred 0-#mu BOX", "PredPlots/dy_MR_0mu_0b_pred", "MR");
  RatioPlots( dy_0b_0mu_R2, pred_R2_dy_0b_0mu, "Z/#gamma^{*} MC 0-#mu BOX", "Z/#gamma^{*} Pred 0-#mu BOX", "PredPlots/dy_R2_0mu_0b_Pred", "RSQ");

  ////////////////////////////////////////
  /////////Z(nunu) 0 mu box///////////////
  ///////////////////////////////////////
  
  TH2F* p_0b_0mu_Z = new TH2F( *data_0b_2mu );//Z(nunu) prediction for 0b 0mu box
  p_0b_0mu_Z->Add(pred_ttbar_2mu0b, -1.0);//Subtracting tt 0b 2mu prediction
  //p_0b_0mu_Z->Add(tt_0b_2mu, -1.0);//Subtracting tt 0b 2mu from MC
  TH2F* r_0b_0mu_Z = new TH2F( *Z_0b_0mu );
  r_0b_0mu_Z->Divide(dy_0b_2mu);
  p_0b_0mu_Z->Multiply(r_0b_0mu_Z);
  Integral = p_0b_0mu_Z->IntegralAndError(1, 6, 1, 6, error, "");
  std::cout << "---------5)-------" << std::endl;
  std::cout << "Z(nunu) Prediction 0b 0mu box: " << Integral << " error: " << error << std::endl;
  TH1F* pred_MR_Z_0b_0mu = (TH1F*)p_0b_0mu_Z->ProjectionX("MR_Z_0mu_0b_pred", 0, -1, "eo");
  TH1F* pred_R2_Z_0b_0mu = (TH1F*)p_0b_0mu_Z->ProjectionY("R2_Z_0mu_0b_pred", 0, -1, "eo");
    
  /////////////////////////////////
  //////////W 0mu box//////////////
  ////////////////////////////////
  RatioPlots( W_0b_0mu_MR, W_0b_1mu_MR, "W MC 0-#mu BOX", "W MC 1-#mu BOX", "RatioPlots/W_MR_0mu_to_1mu", "MR");
  RatioPlots( W_0b_0mu_R2, W_0b_1mu_R2, "W MC 0-#mu BOX" , "W MC 1-#mu BOX", "RatioPlots/W_R2_0mu_to_1mu", "RSQ");
  TH2F* p_0b_0mu_W = new TH2F( *p_0b_1mu_W );//W prediction for 0b 0mu box
  TH2F* r_0b_0mu_W = new TH2F( *W_0b_0mu );
  r_0b_0mu_W->Divide(W_0b_1mu);
  p_0b_0mu_W->Multiply(r_0b_0mu_W);
  Integral = p_0b_0mu_W->IntegralAndError(1, 6, 1, 6, error, "");
  std::cout << "---------7)-------" << std::endl;
  std::cout << "W Prediction 0b 0mu box: " << Integral << " error: " << error << std::endl;
  TH1F* pred_MR_W_0b_0mu = (TH1F*)p_0b_0mu_W->ProjectionX("MR_W_0mu_0b_pred", 0, -1, "eo");
  TH1F* pred_R2_W_0b_0mu = (TH1F*)p_0b_0mu_W->ProjectionY("R2_W_0mu_0b_pred", 0, -1, "eo");
  RatioPlots( W_0b_0mu_MR, pred_MR_W_0b_0mu, "W MC 0-#mu BOX", "W Pred 0-#mu BOX", "PredPlots/W_MR_0mu_0b_pred", "MR");
  RatioPlots( W_0b_0mu_R2, pred_R2_W_0b_0mu, "W MC 0-#mu BOX", "W Pred 0-#mu BOX", "PredPlots/W_R2_0mu_0b_Pred", "RSQ");

  ////////////////////////////////////////////
  ////////Total Prediction 0-mu box///////////
  ////////////////////////////////////////////
  TH2F* bkg = new TH2F( *p_0b_0mu_W );//Adding W+jets prediction
  bkg->Add(pred_ttbar_0mu0b);//Adding tt+jets prediction
  //bkg->Add(tt_0b_0mu);//Adding tt+jets from MC
  bkg->Add(p_0b_0mu_dy);//Adding Z/gamma*(ll)+jets prediction
  bkg->Add(p_0b_0mu_Z);//Adding Z(nunu)+jets prediction
  Integral = bkg->IntegralAndError(1, 6, 1, 6, error, "");
  std::cout << "---------8)-------" << std::endl;
  std::cout << "==============Total bkg Prediction 0b 0mu box: " << Integral << " error: " << error << "==============" << std::endl;
  Integral = data_0b_0mu->IntegralAndError(1, 6, 1, 6, error, "");
  std::cout << "======= Data 1mu-0Btag===========: " << Integral << " error: " << error << "============" << std::endl;
  
  TH1F* pred_MR_bkg_0b_0mu = (TH1F*)bkg->ProjectionX("MR_bkg_0mu_0b_pred", 0, -1, "eo");
  TH1F* pred_R2_bkg_0b_0mu = (TH1F*)bkg->ProjectionY("R2_bkg_0mu_0b_pred", 0, -1, "eo");
  RatioPlotsBand( data_0b_0mu_MR, pred_MR_bkg_0b_0mu, "Data  0-#mu BOX", "Bkg Pred 0-#mu BOX", "PredPlots/Total_Bkg_MR_0mu_0b_pred", "MR");
  RatioPlotsBand( data_0b_0mu_R2, pred_R2_bkg_0b_0mu, "Data  0-#mu BOX", "BKg Pred 0-#mu BOX", "PredPlots/Total_Bkg_R2_0mu_0b_Pred", "RSQ");
  
  ///////////////////////////////////////////////////////////
  ///////////////////Closure Test///////////////////////////
  /////////////////////////////////////////////////////////
  
  RatioPlots( W_0b_1mu_MR, dy_0b_2mu_MR, "Z/#gamma^{*} MC 1-#mu BOX", "Z/#gamma^{*} MC 2-#mu BOX", "RatioPlots/dy_MR_1mu_to_2mu", "MR");
  RatioPlots( W_0b_1mu_R2, dy_0b_2mu_R2, "Z/#gamma^{*} MC 1-#mu BOX", "Z/#gamma^{*} MC 2-#mu BOX", "RatioPlots/dy_R2_1mu_to_2mu", "RSQ");
  
  Integral = data_0b_2mu->IntegralAndError(1, 6, 1, 6, error, "");
  std::cout << "======= 2mu box Data=======: " << Integral << " error: " << error << "============" << std::endl;

  TH2F* pred_0b_1mu_W = new TH2F( *data_0b_2mu );//Drell-Yan prediction for 0b 1mu box
  pred_0b_1mu_W->Add(pred_ttbar_2mu0b, -1.0);//Subtracting tt 0b 2mu from MC    
  Integral = pred_0b_1mu_W->IntegralAndError(1, 6, 1, 6, error, "");
  std::cout << "======= 2mu box Data ttbar subtracted=======: " << Integral << " error: " << error << "============" << std::endl;
  
  TH2F* r_0b_1mu_W_closure = new TH2F( *W_0b_1mu );//W+Jets (1Mu-0Btag)
  r_0b_1mu_W_closure->Divide(dy_0b_2mu);//Z(ll) (2Mu-0Btag)
  pred_0b_1mu_W->Multiply(r_0b_1mu_W_closure);//Actual Prediction
  
  TH2F* mu1_BOX_Pred = new TH2F(*pred_0b_1mu_W);
  mu1_BOX_Pred->Add(tt_0b_1mu);
  mu1_BOX_Pred->Add(p_0b_1mu_dy);

  Integral = mu1_BOX_Pred->IntegralAndError(1, 6, 1, 6, error, "");
  std::cout << "---------9 Closure Test)-------" << std::endl;
  std::cout << "======= 1mu box Prediction=======: " << Integral << " error: " << error << "============" << std::endl;
  Integral = data_0b_1mu->IntegralAndError(1, 6, 1, 6, error, "");
  std::cout << "======= Data 1mu-0Btag===========: " << Integral << " error: " << error << "============" << std::endl;

  TH1F* mu1_BOX_Pred_MR = (TH1F*)mu1_BOX_Pred->ProjectionX("Pred_1mu_0b_MR",0,-1,"eo");
  TH1F* mu1_BOX_Pred_R2 = (TH1F*)mu1_BOX_Pred->ProjectionY("Pred_1mu_0b_R2",0,-1,"eo");
  
  RatioPlotsBand( data_0b_1mu_MR, mu1_BOX_Pred_MR, "Data 1-#mu BOX", "Pred 1-#mu BOX", "PredPlots/Closure_MR_1mu_0b_pred_clo", "MR");
  RatioPlotsBand( data_0b_1mu_R2, mu1_BOX_Pred_R2, "Data 1-#mu BOX", "Pred 1-#mu BOX", "PredPlots/Closure_R2_1mu_0b_Pred_clo", "RSQ");  
  
  f->Close();
  f1->Close();
  F->Close();

  return 0;

}
