#include <iostream>
#include <fstream>
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

const float BaseDM::RSQ_BinArr[] = {0.5, 0.6, 0.725, 0.85, 1.1, 2.50};
const float BaseDM::MR_BinArr[] = {200., 300., 400., 600., 900., 3500.};  

int main(){
  gROOT->Reset();


  /////////////////////////////////////////
  //////////////1Tight Btag///////////////
  ////////////////////////////////////////
  TFile* f = new TFile("FinalROOTFiles/TwoBtag_LOXsec_NewBinning.root");
  
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
    
  TFile* f1 = new TFile("FinalROOTFiles/TwoBtag_LOXsec_NewBinning.root");
    
  TH2F* data_2b_1mu = (TH2F*)f1->Get("data_2d_1mu");
  TH1F* data_2b_1mu_MR = (TH1F*)f1->Get("data_MR_1mu");
  TH1F* data_2b_1mu_R2 = (TH1F*)f1->Get("data_R2_1mu");
  TH2F* tt_2b_1mu = (TH2F*)f1->Get("TT_2d_1mu");
  TH1F* tt_2b_1mu_MR = (TH1F*)f1->Get("TT_MR_1mu");
  TH1F* tt_2b_1mu_R2 = (TH1F*)f1->Get("TT_R2_1mu");
  
  ///////////////////////////////////////////
  ////////////////Veto Btag/////////////////
  //////////////////////////////////////////
  TFile* F = new TFile("FinalROOTFiles/VetoBtag_FullPromtReco_LOXsec_PU_MU_BTAG.root");
  
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
  
  std::cout << "================= -2) ttbar 2mu-0b Prediction : " << pred_ttbar_2mu0b->Integral() << "  ===================" << std::endl;
  
  /////////////////////////////////////////////////////
  ////////////////////ttbar-1Mu-0Btag Pred////////////
  ////////////////////////////////////////////////////
  TH2F* ttbar_1mu0b_1mu2b_Ratio = new TH2F(*tt_0b_1mu);//Ratio ttbar MC 1mu0b/1mu2b
  ttbar_1mu0b_1mu2b_Ratio->Divide(tt_2b_1mu);//ttbar Ratio 1mu0b/1mu2b
  //Total data(1mu2b) for prediction
  TH2F* pred_ttbar_1mu0b = new TH2F(*data_2b_1mu);//Data 1mu2b
  //////////////Actual Prediction ttbar 1mu-0Btag/////////////////////
  pred_ttbar_1mu0b->Multiply(ttbar_1mu0b_1mu2b_Ratio);
  
  std::cout << "================= -1) ttbar 1mu-0b Prediction : " << pred_ttbar_1mu0b->Integral() << "  ===================" << std::endl;

  /////////////////////////////////////////////////////
  ////////////////////ttbar-1Mu-0Btag Pred////////////
  ////////////////////////////////////////////////////
  TH2F* ttbar_0mu0b_1mu2b_Ratio = new TH2F(*tt_0b_0mu);//Ratio ttbar MC 0mu0b/1mu2b
  ttbar_0mu0b_1mu2b_Ratio->Divide(tt_2b_1mu);//ttbar Ratio 0mu0b/1mu2b
  //Total data(1mu2b) for prediction
  TH2F* pred_ttbar_0mu0b = new TH2F(*data_2b_1mu);//Data 1mu2b
  //////////////Actual Prediction ttbar 0mu-0Btag/////////////////////
  pred_ttbar_0mu0b->Multiply(ttbar_0mu0b_1mu2b_Ratio);
  std::cout << "================= 0) ttbar 0mu-0b Prediction : " << pred_ttbar_0mu0b->Integral() << "  ===================" << std::endl;
  
  

  /////////////////////////////////////////////////////////
  /////////////////DY 2mu Prediction//////////////////////
  ////////////////////////////////////////////////////////
  
  TH2F* p_0b_2mu_dy = new TH2F(*data_0b_2mu);
  p_0b_2mu_dy->Add(pred_ttbar_2mu0b, -1.0);
  
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
  
  //TH2F* p_0b_0mu_Z = new TH2F( *data_0b_2mu );//Z(nunu) prediction for 0b 0mu box
  //p_0b_0mu_Z->Add(pred_ttbar_2mu0b, -1.0);//Subtracting tt 0b 2mu prediction 
  //r_0b_0mu_Z->Divide(dy_0b_2mu); 
  TH2F* p_0b_0mu_Z = new TH2F( *p_0b_1mu_W );//Z(nunu) prediction for 0b 0mu box
  TH2F* r_0b_0mu_Z = new TH2F( *Z_0b_0mu );
  r_0b_0mu_Z->Divide(W_0b_1mu);
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


  
  double tt_mu[3], dy_mu[3], w_mu[3], z_mu[3];
  double tt_mu_E[3], dy_mu_E[3], w_mu_E[3], z_mu_E[3];
  
  for(int i = 0; i < 3; i++){
    tt_mu[i] = .0;
    tt_mu_E[i] = .0;
    dy_mu[i] = .0;
    dy_mu_E[i] = .0;
    w_mu[i] = .0;
    w_mu_E[i] = .0;
    z_mu[i] = .0;
    z_mu_E[i] = .0;
  }
  
  tt_mu[0] = pred_ttbar_0mu0b->IntegralAndError(1,4, tt_mu_E[0]);
  tt_mu[1] = pred_ttbar_1mu0b->IntegralAndError(1,4, tt_mu_E[1]);
  tt_mu[2] = pred_ttbar_2mu0b->IntegralAndError(1,4, tt_mu_E[2]);

  dy_mu[0] = p_0b_0mu_dy->IntegralAndError(1,4, dy_mu_E[0]);
  dy_mu[1] = p_0b_1mu_dy->IntegralAndError(1,4, dy_mu_E[1]);
  dy_mu[2] = p_0b_2mu_dy->IntegralAndError(1,4, dy_mu_E[2]);
  
  w_mu[0] = p_0b_0mu_W->IntegralAndError(1,4, w_mu_E[0]);
  w_mu[1] = p_0b_1mu_W->IntegralAndError(1,4, w_mu_E[1]);
  //w_mu[2] = MR_RSQ_2BOX_W->IntegralAndError(1,4, w_mu_E[2]);
  
  z_mu[0] = p_0b_0mu_Z->IntegralAndError(1,4, z_mu_E[0]);
  //z_mu[1] = MR_RSQ_1BOX_Z->IntegralAndError(1,4, z_mu_E[1]);
  //z_mu[2] = MR_RSQ_2BOX_Z->IntegralAndError(1,4, z_mu_E[2]);
  
  double tot_0mu = tt_mu[0]+dy_mu[0]+w_mu[0]+z_mu[0];
  double tot_1mu = tt_mu[1]+dy_mu[1]+w_mu[1]+z_mu[1];
  double tot_2mu = tt_mu[2]+dy_mu[2]+w_mu[2]+z_mu[2];

  double tot_0mu_E = sqrt(tt_mu_E[0]*tt_mu_E[0] + dy_mu_E[0]*dy_mu_E[0] + w_mu_E[0]*w_mu_E[0] + z_mu_E[0]*z_mu_E[0]);
  double tot_1mu_E = sqrt(tt_mu_E[1]*tt_mu_E[1] + dy_mu_E[1]*dy_mu_E[1] + w_mu_E[1]*w_mu_E[1] + z_mu_E[1]*z_mu_E[1]);
  double tot_2mu_E = sqrt(tt_mu_E[2]*tt_mu_E[2] + dy_mu_E[2]*dy_mu_E[2] + w_mu_E[2]*w_mu_E[2] + z_mu_E[2]*z_mu_E[2]);

  std::ofstream ofs("Yields_FullData_BtagCorr.tex", std::ofstream::out);
  
  ofs << "\\begin{table}[htdp]\n\\caption{default}\n\\begin{center}\n\\begin{tabular}{|c|c|c|c|}\n\\hline\n";
  ofs << "\t&\t$0-\\mu BOX$\t&\t$1-\\mu BOX$\t&\t$2-\\mu BOX$\\\\\n\\hline";
  ofs << "$t\\bar{t}$ + Jets\t&\t" << tt_mu[0] << "$\\pm$" << tt_mu_E[0] << "\t&\t" << tt_mu[1] << "$\\pm$" << tt_mu_E[1] << "\t&\t" << tt_mu[2] << "$\\pm$" << tt_mu_E[2] <<"\\\\\n";
  ofs << "\\hline\n$Z(ll)$ + Jets\t&\t" << dy_mu[0] << "$\\pm$" << dy_mu_E[0] << "\t&\t" << dy_mu[1] << "$\\pm$" << dy_mu_E[1] << "\t&\t" << dy_mu[2] << "$\\pm$" << dy_mu_E[2] <<"\\\\\n";
  ofs << "\\hline\n$Z(\\nu\\bar{\\nu})$ + Jets\t&\t" << z_mu[0] << "$\\pm$" << z_mu_E[0] << "\t&\t" << z_mu[1] << "$\\pm$" << z_mu_E[1] << "\t&\t" << z_mu[2] << "$\\pm$" << z_mu_E[2] << "\\\\\n";
  ofs << "\\hline\n$W(l\\nu)$ + Jets\t&\t" <<  w_mu[0] << "$\\pm$" << w_mu_E[0] << "\t&\t" << w_mu[1] << "$\\pm$" << w_mu_E[1] << "\t&\t" << w_mu[2] << "$\\pm$" << w_mu_E[2] <<"\\\\\n";
  ofs << "\\hline\n\\hline\nTotal MC\t&\t" << tot_0mu << "$\\pm$" << tot_0mu_E << "\t&\t" << tot_1mu << "$\\pm$" << tot_1mu_E << "\t&\t" << tot_2mu << "$\\pm$" << tot_2mu_E << "\\\\\n";
  ofs << "\\hline\nData\t&\t" << data_0b_0mu->Integral() << "\t&\t" << data_0b_1mu->Integral() << "\t&\t" << data_0b_2mu->Integral() << "\\\\\n\\hline";
  ofs << "\\end{tabular}\n\\end{center}\n\\label{default}\n\\end{table}\n";
  
  ofs.close();

  //////////////////////////////////////////////////////
  //////////////////Output to LimitSetting/////////////
  ////////////////////////////////////////////////////

  TFile *bkg_file_1DRsq = new TFile("Pred_Files/Bkg_Pred_from_Data_1DRsq_FullData_BtagCorr.root","RECREATE");
  TFile *bkg_file_2D = new TFile("Pred_Files/BkgPred_FullData_BtagCorr.root","RECREATE");

  bkg_file_2D->cd();
  bkg->Write("BkgPred_2d");
  data_0b_0mu->Write("Data_2d");
  bkg_file_1DRsq->cd();
  //pred_R2_bkg_0b_0mu->Write("BkgPred_R2"); //   

  double rbins[5] = {0.5, 0.65, 0.8, 1.0, 2.50};
  double mrbins[5] = {200., 400., 600., 800., 3500.};
  
  bkg_file_2D->cd();
  //data_0b_0mu->Write();
  bkg_file_1DRsq->cd();
  //data_0b_0mu_R2->Write();
  //data_0b_0mu->SetName("data_obs");
  //data_0b_0mu_R2->SetName("data_obs");


  bkg_file_2D->cd();
  //data_0b_0mu->Write("data_2d");
  //bkg_file_1DRsq->cd();
  //data_0b_0mu_R2->Write("data_R2");


  TH1F *bkg_rsq_alphaUp = new TH1F("bkg_rsq_alphaUp","bkg_rsq_alphaUp",4,rbins);
  TH1F *bkg_rsq_alphaDown = new TH1F("bkg_rsq_alphaDown","bkg_rsq_alphaDown",4,rbins);

  for (int z=0; z<4; z++)
  {
   double binValue = pred_R2_bkg_0b_0mu->GetBinContent(z+1);
   double error = pred_R2_bkg_0b_0mu->GetBinError(z+1);
   bkg_rsq_alphaUp->SetBinContent(z+1,binValue+error);
   bkg_rsq_alphaDown->SetBinContent(z+1,binValue-error);
  }
  //bkg_file_1DRsq->Write();
  //bkg_rsq_alphaUp->Write("BkgPred_R2_alphaUp");
  //bkg_rsq_alphaDown->Write("BkgPred_R2_alphaDown");


  TH2F *bkg_alphaUp = new TH2F("bkg_alphaUp","bkg_alphaUp",4,mrbins,4,rbins);
  TH2F *bkg_alphaDown = new TH2F("bkg_alphaDown","bkg_alphaUp",4,mrbins,4,rbins);


  for (int x=1; x<5; x++) //mr                                                 
      {
   for (int y=1; y<5; y++) // rsq                                           
  	  {
       double value_in =bkg->GetBinContent(x,y);
       double error_low = bkg->GetBinError(x,y);
       double error_high = bkg->GetBinError(x,y);
       ////double error_low = 0;                                              
       //double error_high = 0;                                             
       bkg_alphaUp->SetBinContent(x,y,value_in+error_high);
       bkg_alphaDown->SetBinContent(x,y,value_in-error_low);
   }
  }
  bkg_file_2D->cd();
  //bkg_alphaUp->Write("BkgPred_2d_alphaUp");
  //bkg_alphaDown->Write("BkgPred_2d_alphaDown");



  TH1F *bkg_1D = new TH1F("bkg_1D","bkg_1D",16,0,16);
  TH1F *bkg_1D_alphaUp = new TH1F("bkg_1D_alphaUp","bkg_1D_alphaUp",16,0,16);
  TH1F *bkg_1D_alphaDown = new TH1F("bkg_1D_alphaDown","bkg_1D_alphaDown",16,0,16);
  TH1F *data_1D_unwrapt = new TH1F("data_unwrapt","data_Unwrapt_16bins",16,0,16);

  
  TH1F *tt_1D = new TH1F("tt_1D","tt_1D",16,0,16);
  TH1F *tt_1D_alphaUp = new TH1F("tt_1D_alphaUp","tt_1D_alphaUp",16,0,16);
  TH1F *tt_1D_alphaDown = new TH1F("tt_1D_alphaDown","tt_1D_alphaDown",16,0,16);

  TH1F *dy_1D = new TH1F("dy_1D","dy_1D",16,0,16);
  TH1F *dy_1D_alphaUp = new TH1F("dy_1D_alphaUp","dy_1D_alphaUp",16,0,16);
  TH1F *dy_1D_alphaDown = new TH1F("dy_1D_alphaDown","dy_1D_alphaDown",16,0,16);

  TH1F *z_1D = new TH1F("z_1D","z_1D",16,0,16);
  TH1F *z_1D_alphaUp = new TH1F("z_1D_alphaUp","z_1D_alphaUp",16,0,16);
  TH1F *z_1D_alphaDown = new TH1F("z_1D_alphaDown","z_1D_alphaDown",16,0,16);

  TH1F *w_1D = new TH1F("w_1D","w_1D",16,0,16);
  TH1F *w_1D_alphaUp = new TH1F("w_1D_alphaUp","w_1D_alphaUp",16,0,16);
  TH1F *w_1D_alphaDown = new TH1F("w_1D_alphaDown","w_1D_alphaDown",16,0,16);
  

  int counter = 0;
  for ( int i=1; i<5; i++){
    for (int j=1; j<5; j++){
      counter++;
      double results = bkg->GetBinContent(i,j);
      double results2 = bkg_alphaUp->GetBinContent(i,j);
      double results3 = bkg_alphaDown->GetBinContent(i,j);
      double results_data = data_0b_0mu->GetBinContent(i,j);
      //ttbar
      double tt_c = tt_0b_0mu->GetBinContent(i,j);
      double tt_e = tt_0b_0mu->GetBinError(i,j);
      double tt_u = tt_0b_0mu->GetBinErrorUp(tt_0b_0mu->GetBin(i,j));
      double tt_l = tt_0b_0mu->GetBinErrorLow(tt_0b_0mu->GetBin(i,j));
      //dy
      double dy_c = p_0b_0mu_dy->GetBinContent(i,j);
      double dy_e = p_0b_0mu_dy->GetBinError(i,j);
      double dy_u = p_0b_0mu_dy->GetBinErrorUp(p_0b_0mu_dy->GetBin(i,j));
      double dy_l = p_0b_0mu_dy->GetBinErrorLow(p_0b_0mu_dy->GetBin(i,j));
      //z
      double z_c = p_0b_0mu_Z->GetBinContent(i,j);
      double z_e = p_0b_0mu_Z->GetBinError(i,j);
      double z_u = p_0b_0mu_Z->GetBinErrorUp(p_0b_0mu_Z->GetBin(i,j));
      double z_l = p_0b_0mu_Z->GetBinErrorLow(p_0b_0mu_Z->GetBin(i,j));
      //w
      double w_c = p_0b_0mu_W->GetBinContent(i,j);
      double w_e = p_0b_0mu_W->GetBinError(i,j);
      double w_u = p_0b_0mu_W->GetBinErrorUp(p_0b_0mu_W->GetBin(i,j));
      double w_l = p_0b_0mu_W->GetBinErrorLow(p_0b_0mu_W->GetBin(i,j));
      std::cout << "error: " << w_e << " w_l: " << w_l << " w_u: " << w_l << " w_c-w_l: " << w_c-w_l << std::endl;
      std::cout << "error: " << z_e << " z_l: " << z_l << " z_u: " << z_l << " z_c-z_l: " << z_c-z_l << std::endl;
      std::cout << "error: " << dy_e << " dy_l: " << dy_l << " dy_u: " << dy_l << " dy_c-dy_l: " << dy_c-dy_l << std::endl;
      std::cout << "error: " << tt_e << " tt_l: " << tt_l << " tt_u: " << tt_l << " tt_c-tt_l: " << tt_c-tt_l << std::endl;
      //unwrapping 2D into 1D
      //tt
      tt_1D->SetBinContent(counter,tt_c);
      tt_1D_alphaUp->SetBinContent(counter,tt_c+tt_u);
      tt_1D_alphaDown->SetBinContent(counter,tt_c-tt_l);
      //dy
      dy_1D->SetBinContent(counter,dy_c);
      dy_1D_alphaUp->SetBinContent(counter,dy_c+dy_u);
      dy_1D_alphaDown->SetBinContent(counter,dy_c-dy_l);
      //z
      z_1D->SetBinContent(counter,z_c);
      z_1D_alphaUp->SetBinContent(counter,z_c+z_u);
      z_1D_alphaDown->SetBinContent(counter,z_c-z_l);
      //w
      w_1D->SetBinContent(counter,w_c);
      w_1D_alphaUp->SetBinContent(counter,w_c+w_u);
      w_1D_alphaDown->SetBinContent(counter,w_c-w_l);
      
      data_1D_unwrapt->SetBinContent(counter,results_data);
      bkg_1D->SetBinContent(counter,results);
      bkg_1D_alphaUp->SetBinContent(counter,results2);
      bkg_1D_alphaDown->SetBinContent(counter,results3);
    }
  }
  //bkg_file_1DRsq->Write("BkgPred_Unwrapt");
  //data_1D_unwrapt->Write("data_Unwrapt");
  //bkg_1D->Write("BkgPred_Unwrapt");
  //bkg_1D_alphaUp->Write("BkgPred_Unwrapt_alphaUp");
  //bkg_1D_alphaDown->Write("BkgPred_Unwrapt_alphaDown");
  
  tt_1D->Write();
  tt_1D_alphaUp->Write();
  tt_1D_alphaDown->Write();

  dy_1D->Write();
  dy_1D_alphaUp->Write();
  dy_1D_alphaDown->Write();

  z_1D->Write();
  z_1D_alphaUp->Write();
  z_1D_alphaDown->Write();

  w_1D->Write();
  w_1D_alphaUp->Write();
  w_1D_alphaDown->Write();

  data_1D_unwrapt->Write("data_obs");

  TTree *info2D = new TTree("info2D","ROOT Tree");
  TTree *info1D = new TTree("info1D","ROOT Tree");


  double num_bkg_1D_Rsq;
  double num_bkg_1D;
  double num_data_1D_Rsq;

  double num_data_1D;
  info1D->Branch("num_bkg_1D_Rsq",&num_bkg_1D_Rsq,"num_bkg_1D_Rsq/D");
  info2D->Branch("num_bkg_1D",&num_bkg_1D,"num_bkg_1D/D");
  info1D->Branch("num_data_1D_Rsq",&num_data_1D_Rsq,"num_data_1D_Rsq/D");
  info2D->Branch("num_data_1D",&num_data_1D,"num_data_1D/D");
  num_bkg_1D_Rsq = pred_R2_bkg_0b_0mu->Integral();
  num_bkg_1D = bkg->Integral();
  num_data_1D_Rsq = data_0b_0mu_R2->Integral();
  num_data_1D = data_0b_0mu->Integral();
  info1D->Fill();
  bkg_file_1DRsq->cd();

  info1D->Branch("num_bkg_1D_Rsq",&num_bkg_1D_Rsq,"num_bkg_1D_Rsq/D");
  info2D->Branch("num_bkg_1D",&num_bkg_1D,"num_bkg_1D/D");
  info1D->Branch("num_data_1D_Rsq",&num_data_1D_Rsq,"num_data_1D_Rsq/D");
  info2D->Branch("num_data_1D",&num_data_1D,"num_data_1D/D");
  num_bkg_1D_Rsq = pred_R2_bkg_0b_0mu->Integral();
  num_bkg_1D = bkg->Integral();
  num_data_1D_Rsq = data_0b_0mu_R2->Integral();
  num_data_1D = data_0b_0mu->Integral();
  info1D->Fill();
  bkg_file_1DRsq->cd();
  //info1D->Write();
  bkg_file_2D->cd();
  //info2D->Write();
  


  f->Close();
  f1->Close();
  F->Close();

  return 0;

  /*

  //////////////////////////////////////////////////////
  //////////////////Output to LimitSetting/////////////
  ////////////////////////////////////////////////////

  TFile *bkg_file_1DRsq = new TFile("Pred_Files/Bkg_Pred_from_Data_1DRsq_FullData_BtagCorr.root","RECREATE");
  TFile *bkg_file_2D = new TFile("Pred_Files/Bkg_Pred_from_Data_2D_FullData_BtagCorr.root","RECREATE");

  bkg_file_2D->cd();
  bkg->Write("BkgPred_2d");
  bkg_file_1DRsq->cd();
  pred_R2_bkg_0b_0mu->Write("BkgPred_R2"); //   

  double rbins[5] = {0.5, 0.65, 0.8, 1.0, 2.50};
  double mrbins[5] = {200., 400., 600., 800., 3500.};
  
  bkg_file_2D->cd();
  //data_0b_0mu->Write();
  bkg_file_1DRsq->cd();
  //data_0b_0mu_R2->Write();
  //data_0b_0mu->SetName("data_obs");
  //data_0b_0mu_R2->SetName("data_obs");


  bkg_file_2D->cd();
  data_0b_0mu->Write("data_2d");
  bkg_file_1DRsq->cd();
  data_0b_0mu_R2->Write("data_R2");


  TH1F *bkg_rsq_alphaUp = new TH1F("bkg_rsq_alphaUp","bkg_rsq_alphaUp",4,rbins);
  TH1F *bkg_rsq_alphaDown = new TH1F("bkg_rsq_alphaDown","bkg_rsq_alphaDown",4,rbins);

  for (int z=0; z<4; z++)
  {
   double binValue = pred_R2_bkg_0b_0mu->GetBinContent(z+1);
   double error = pred_R2_bkg_0b_0mu->GetBinError(z+1);
   bkg_rsq_alphaUp->SetBinContent(z+1,binValue+error);
   bkg_rsq_alphaDown->SetBinContent(z+1,binValue-error);
  }
  //bkg_file_1DRsq->Write();
  bkg_rsq_alphaUp->Write("BkgPred_R2_alphaUp");
  bkg_rsq_alphaDown->Write("BkgPred_R2_alphaDown");


  TH2F *bkg_alphaUp = new TH2F("bkg_alphaUp","bkg_alphaUp",4,mrbins,4,rbins);
  TH2F *bkg_alphaDown = new TH2F("bkg_alphaDown","bkg_alphaUp",4,mrbins,4,rbins);


  for (int x=1; x<5; x++) //mr                                                 
      {
   for (int y=1; y<5; y++) // rsq                                           
  	  {
       double value_in =bkg->GetBinContent(x,y);
       double error_low = bkg->GetBinError(x,y);
       double error_high = bkg->GetBinError(x,y);
       ////double error_low = 0;                                              
       //double error_high = 0;                                             
       bkg_alphaUp->SetBinContent(x,y,value_in+error_high);
       bkg_alphaDown->SetBinContent(x,y,value_in-error_low);
   }
  }
  bkg_file_2D->cd();
  bkg_alphaUp->Write("BkgPred_2d_alphaUp");
  bkg_alphaDown->Write("BkgPred_2d_alphaDown");



  TH1F *bkg_1D = new TH1F("bkg_1D","bkg_1D",16,0,16);
  TH1F *bkg_1D_alphaUp = new TH1F("bkg_1D_alphaUp","bkg_1D_alphaUp",16,0,16);
  TH1F *bkg_1D_alphaDown = new TH1F("bkg_1D_alphaDown","bkg_1D_alphaDown",16,0,16);
  TH1F *data_1D_unwrapt = new TH1F("data_unwrapt","data_Unwrapt_16bins",16,0,16);

  int counter = 0;
  for ( int i=1; i<5; i++)
  {
  for (int j=1; j<5; j++)
  	{
     counter++;
      double results = bkg->GetBinContent(i,j);
      double results2 = bkg_alphaUp->GetBinContent(i,j);
      double results3 = bkg_alphaDown->GetBinContent(i,j);
      double results_data = data_0b_0mu->GetBinContent(i,j);
      //unwrapping 2D into 1D
      data_1D_unwrapt->SetBinContent(counter,results_data);
      bkg_1D->SetBinContent(counter,results);
      bkg_1D_alphaUp->SetBinContent(counter,results2);
      bkg_1D_alphaDown->SetBinContent(counter,results3);
    }
  }
  //bkg_file_1DRsq->Write("BkgPred_Unwrapt");
  data_1D_unwrapt->Write("data_Unwrapt");
  bkg_1D->Write("BkgPred_Unwrapt");
  bkg_1D_alphaUp->Write("BkgPred_Unwrapt_alphaUp");
  bkg_1D_alphaDown->Write("BkgPred_Unwrapt_alphaDown");

  TTree *info2D = new TTree("info2D","ROOT Tree");
  TTree *info1D = new TTree("info1D","ROOT Tree");


  double num_bkg_1D_Rsq;
  double num_bkg_1D;
  double num_data_1D_Rsq;

  double num_data_1D;
  info1D->Branch("num_bkg_1D_Rsq",&num_bkg_1D_Rsq,"num_bkg_1D_Rsq/D");
  info2D->Branch("num_bkg_1D",&num_bkg_1D,"num_bkg_1D/D");
  info1D->Branch("num_data_1D_Rsq",&num_data_1D_Rsq,"num_data_1D_Rsq/D");
  info2D->Branch("num_data_1D",&num_data_1D,"num_data_1D/D");
  num_bkg_1D_Rsq = pred_R2_bkg_0b_0mu->Integral();
  num_bkg_1D = bkg->Integral();
  num_data_1D_Rsq = data_0b_0mu_R2->Integral();
  num_data_1D = data_0b_0mu->Integral();
  info1D->Fill();
  bkg_file_1DRsq->cd();

  info1D->Branch("num_bkg_1D_Rsq",&num_bkg_1D_Rsq,"num_bkg_1D_Rsq/D");
  info2D->Branch("num_bkg_1D",&num_bkg_1D,"num_bkg_1D/D");
  info1D->Branch("num_data_1D_Rsq",&num_data_1D_Rsq,"num_data_1D_Rsq/D");
  info2D->Branch("num_data_1D",&num_data_1D,"num_data_1D/D");
  num_bkg_1D_Rsq = pred_R2_bkg_0b_0mu->Integral();
  num_bkg_1D = bkg->Integral();
  num_data_1D_Rsq = data_0b_0mu_R2->Integral();
  num_data_1D = data_0b_0mu->Integral();
  info1D->Fill();
  bkg_file_1DRsq->cd();
  info1D->Write();
  bkg_file_2D->cd();
  info2D->Write();
  


  f->Close();
  f1->Close();
  F->Close();

  return 0;
  */
}
