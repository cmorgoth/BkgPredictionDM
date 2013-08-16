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

const float BaseDM::RSQ_BinArr[] = {0.5, 0.7, 0.9, 1.1, 2.50};
const float BaseDM::MR_BinArr[] = {200., 466., 732., 1000., 3500.};

int main(){
  gROOT->Reset();


  /////////////////////////////////////////
  //////////////1Tight Btag///////////////
  ////////////////////////////////////////
  //TFile* f = new TFile("1Tight.root");
  TFile* f = new TFile("Btag_Tight.root");
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
  
  
  std::cout << "tt 0-mu1b: " << tt_1b_0mu->Integral() << " tt 1-mu1b: " << tt_1b_1mu->Integral() << std::endl; 
  std::cout << "data 0-mu1b: " << data_1b_0mu->Integral() << " data 1-mu1b: " << data_1b_1mu->Integral() << std::endl;
  std::cout << "W 0-mu1b: " << W_1b_0mu_R2->Integral() << " W 1-mu1b: " << W_1b_1mu_R2->Integral() << std::endl;
  


  /////////////////////////////////////////////
  //////////////1Tight 1Med///////////////////
  ///////////////////////////////////////////
    
  //TFile* f1 = new TFile("1Tight_1Medium.root");
  TFile* f1 = new TFile("Btag_1Tight_1Medium.root");
  TH2F* data_2b_1mu = (TH2F*)f1->Get("data_2d_1mu");
  TH1F* data_2b_1mu_MR = (TH1F*)f1->Get("data_MR_1mu");
  TH1F* data_2b_1mu_R2 = (TH1F*)f1->Get("data_R2_1mu");
  TH2F* tt_2b_1mu = (TH2F*)f1->Get("TT_2d_1mu");
  TH1F* tt_2b_1mu_MR = (TH1F*)f1->Get("TT_MR_1mu");
  TH1F* tt_2b_1mu_R2 = (TH1F*)f1->Get("TT_R2_1mu");
  
  ///////////////////////////////////////////
  ////////////////Veto Btag/////////////////
  //////////////////////////////////////////
  //TFile* F = new TFile("VetoBtag.root");
  TFile* F = new TFile("VetoBtag_NewBinning.root");
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
  
  //////////////////////////////////////////////////
  /////////////tt prediction and closure //////////
  /////////////////////////////////////////////////
  double error = -1.0;
  double Integral = data_1b_2mu->IntegralAndError(1, 6, 1, 6, error, "");
  std::cout << "int and error: " << Integral << " " << error << std::endl;
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
  
  RatioPlots( tt_0b_2mu_MR, pred_MR, "t#bar{t} MC 2-#mu BOX", "t#bar{t} Pred 2-#mu BOX", "PredPlots/tt_MR_2mu_pred", "MR");
  RatioPlots( tt_0b_2mu_R2, pred_R2, "t#bar{t} MC 2-#mu BOX", "t#bar{t} Pred 2-#mu BOX", "PredPlots/tt_R2_2mu_Pred", "RSQ");
  
  RatioPlots( tt_1b_1mu_MR, pred_MR_1mu, "t#bar{t} MC 1-#mu BOX", "t#bar{t} Pred 1-#mu BOX", "PredPlots/tt_MR_1mu_1b_pred", "MR");
  RatioPlots( tt_1b_1mu_R2, pred_R2_1mu, "t#bar{t} MC 1-#mu BOX", "t#bar{t} Pred 1-#mu BOX", "PredPlots/tt_R2_1mu_1b_Pred", "RSQ");
  
  RatioPlots( tt_1b_0mu_MR, pred_MR_0mu, "t#bar{t} MC 1-#mu BOX", "t#bar{t} Pred 0-#mu BOX", "PredPlots/tt_MR_0mu_1b_pred", "MR");
  RatioPlots( tt_1b_0mu_R2, pred_R2_0mu, "t#bar{t} MC 1-#mu BOX", "t#bar{t} Pred 0-#mu BOX", "PredPlots/tt_R2_0mu_1b_Pred", "RSQ");

  ///////////////////////////////////////////////////
  /////////////////////Signal Prediction////////////
  /////////////////////////////////////////////////
  
  //////////////////////////////////////////
  ////////Drell-Yan 1 mu box///////////////
  /////////////////////////////////////////
  
  RatioPlots( dy_0b_1mu_MR, dy_0b_2mu_MR, "Z/#gamma^{*} MC 1-#mu BOX", "Z/#gamma^{*} MC 2-#mu BOX", "RatioPlots/dy_MR_1mu_to_2mu", "MR");
  RatioPlots( dy_0b_1mu_R2, dy_0b_2mu_R2, "Z/#gamma^{*} MC 1-#mu BOX", "Z/#gamma^{*} MC 2-#mu BOX", "RatioPlots/dy_R2_1mu_to_2mu", "RSQ");
  TH2F* p_0b_1mu_dy = new TH2F( *data_0b_2mu );//Drell-Yan prediction for 0b 1mu box
  p_0b_1mu_dy->Add(data_1b_2mu, -1.0);//Subtracting tt 0b 2mu prediction
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
  //RatioPlots( dy_0b_1mu_MR, pred_MR_dy_0b_1mu, "Z/#gamma^{*} MC 1-#mu BOX", "Z/#gamma^{*} Pred 1-#mu BOX", "RatioPlots/dy_MR_1mu_0b_pred_ttMC", "MR");
  //RatioPlots( dy_0b_1mu_R2, pred_R2_dy_0b_1mu, "Z/#gamma^{*} MC 1-#mu BOX", "Z/#gamma^{*} Pred 1-#mu BOX", "RatioPlots/dy_R2_1mu_0b_Pred_ttMC", "RSQ");

  ///////////////////////////////////////////
  //////////////tt 1mu box//////////////////
  //////////////////////////////////////////
  RatioPlots( tt_0b_1mu_MR, tt_2b_1mu_MR, "t#bar{t} MC 1-#mu 0b BOX", "t#bar{t} MC 1-#mu 2b BOX", "RatioPlots/tt_MR_1mu_0b_to_2b", "MR");
  RatioPlots( tt_0b_1mu_R2, tt_2b_1mu_R2, "t#bar{t} MC 1-#mu 0b BOX" , "t#bar{t} MC 1-#mu 2b BOX", "RatioPlots/tt_R2_1mu_0b_to_2b", "RSQ");
  TH2F* p_0b_1mu_tt = new TH2F( *data_2b_1mu );//tt prediction for 0b 1mu box
  TH2F* r_0b_1mu_tt = new TH2F( *tt_0b_1mu );
  r_0b_1mu_tt->Divide(tt_2b_1mu);
  p_0b_1mu_tt->Multiply(r_0b_1mu_tt);
  Integral = p_0b_1mu_tt->IntegralAndError(1, 6, 1, 6, error, "");
  std::cout << "---------2)-------" << std::endl;
  std::cout << "tt Prediction 0b 1mu box: " << Integral << " error: " << error << std::endl;
  TH1F* pred_MR_tt_0b_1mu = (TH1F*)p_0b_1mu_tt->ProjectionX("MR_tt_1mu_0b_pred", 0, -1, "eo");
  TH1F* pred_R2_tt_0b_1mu = (TH1F*)p_0b_1mu_tt->ProjectionY("R2_tt_1mu_0b_pred", 0, -1, "eo");
  RatioPlots( tt_0b_1mu_MR, pred_MR_tt_0b_1mu, "t#bar{t} MC 1-#mu BOX", "t#bar{t} Pred 1-#mu BOX", "PredPlots/tt_MR_1mu_0b_pred", "MR");
  RatioPlots( tt_0b_1mu_R2, pred_R2_tt_0b_1mu, "t#bat{t} MC 1-#mu BOX", "t#bar{t} Pred 1-#mu BOX", "PredPlots/tt_R2_1mu_0b_Pred", "RSQ");

  ////////////////////////////////////////
  //////////////////W 1mu/////////////////
  ////////////////////////////////////////
  TH2F* p_0b_1mu_W = new TH2F( *data_0b_1mu );//W prediction for 0b 1mu box
  //p_0b_1mu_W->Add(p_0b_1mu_tt, -1.0);//Subtraction tt 1mu prediction
  p_0b_1mu_W->Add(tt_0b_1mu, -1.0);//Subtraction tt 1mu from MC
  p_0b_1mu_W->Add(p_0b_1mu_dy, -1.0);//Subtraction Drell-Yan 1mu prediction
  Integral = p_0b_1mu_W->IntegralAndError(1, 6, 1, 6, error, "");
  std::cout << "---------3)-------" << std::endl;
  std::cout << "W Prediction 0b 1mu box: " << Integral << " error: " << error << std::endl;
  TH1F* pred_MR_W_0b_1mu = (TH1F*)p_0b_1mu_W->ProjectionX("MR_W_1mu_0b_pred", 0, -1, "eo");
  TH1F* pred_R2_W_0b_1mu = (TH1F*)p_0b_1mu_W->ProjectionY("R2_W_1mu_0b_pred", 0, -1, "eo");
  //RatioPlots( W_0b_1mu_MR, pred_MR_W_0b_1mu, "W MC 1-#mu BOX", "W Pred 1-#mu BOX", "RatioPlots/W_MR_1mu_0b_pred", "MR");
  //RatioPlots( W_0b_1mu_R2, pred_R2_W_0b_1mu, "W MC 1-#mu BOX", "W Pred 1-#mu BOX", "RatioPlots/W_R2_1mu_0b_Pred", "RSQ");
  RatioPlots( W_0b_1mu_MR, pred_MR_W_0b_1mu, "W MC 1-#mu BOX", "W Pred 1-#mu BOX", "PredPlots/W_MR_1mu_0b_pred_ttMC", "MR");
  RatioPlots( W_0b_1mu_R2, pred_R2_W_0b_1mu, "W MC 1-#mu BOX", "W Pred 1-#mu BOX", "PredPlots/W_R2_1mu_0b_Pred_ttMC", "RSQ");
  
  ///////////////////////////////////
  /////////Drell-Yan 0 mu box////////
  //////////////////////////////////
  RatioPlots( dy_0b_0mu_MR, dy_0b_2mu_MR, "Z/#gamma^{*} MC 0-#mu BOX", "Z/#gamma^{*} MC 2-#mu BOX", "RatioPlots/dy_MR_0mu_to_2mu", "MR");
  RatioPlots( dy_0b_0mu_R2, dy_0b_2mu_R2, "Z/#gamma^{*} MC 0-#mu BOX", "Z/#gamma^{*} MC 2-#mu BOX", "RatioPlots/dy_R2_0mu_to_2mu", "RSQ");
  TH2F* p_0b_0mu_dy = new TH2F( *data_0b_2mu );//Drell-Yan prediction for 0b 0mu box
  p_0b_0mu_dy->Add(data_1b_2mu, -1.0);//Subtracting tt 0b 2mu prediction
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
  //RatioPlots( dy_0b_0mu_MR, pred_MR_dy_0b_0mu, "Z/#gamma^{*} MC 0-#mu BOX", "Z/#gamma^{*} Pred 0-#mu BOX", "RatioPlots/dy_MR_0mu_0b_pred_ttMC", "MR");
  //RatioPlots( dy_0b_0mu_R2, pred_R2_dy_0b_0mu, "Z/#gamma^{*} MC 0-#mu BOX", "Z/#gamma^{*} Pred 0-#mu BOX", "RatioPlots/dy_R2_0mu_0b_Pred_ttMC", "RSQ");

  ////////////////////////////////////////
  /////////Z(nunu) 0 mu box///////////////
  ///////////////////////////////////////
  //RatioPlots( Z_0b_0mu_MR, dy_0b_2mu_MR, "Z(#nu#nu) MC 0-#mu BOX", "Z/#gamma^{*} MC 2-#mu BOX", "RatioPlots/Z_dy_MR_0mu_to_2mu", "MR");
  //RatioPlots( Z_0b_0mu_R2, dy_0b_2mu_R2, "Z(#nu#nu) MC 0-#mu BOX", "Z/#gamma^{*} MC 2-#mu BOX", "RatioPlots/Z_dy_R2_0mu_to_2mu", "RSQ");
  TH2F* p_0b_0mu_Z = new TH2F( *data_0b_2mu );//Z(nunu) prediction for 0b 0mu box
  p_0b_0mu_Z->Add(data_1b_2mu, -1.0);//Subtracting tt 0b 2mu prediction
  //p_0b_0mu_Z->Add(tt_0b_2mu, -1.0);//Subtracting tt 0b 2mu from MC
  TH2F* r_0b_0mu_Z = new TH2F( *Z_0b_0mu );
  r_0b_0mu_Z->Divide(dy_0b_2mu);
  p_0b_0mu_Z->Multiply(r_0b_0mu_Z);
  Integral = p_0b_0mu_Z->IntegralAndError(1, 6, 1, 6, error, "");
  std::cout << "---------5)-------" << std::endl;
  std::cout << "Z(nunu) Prediction 0b 0mu box: " << Integral << " error: " << error << std::endl;
  TH1F* pred_MR_Z_0b_0mu = (TH1F*)p_0b_0mu_Z->ProjectionX("MR_Z_0mu_0b_pred", 0, -1, "eo");
  TH1F* pred_R2_Z_0b_0mu = (TH1F*)p_0b_0mu_Z->ProjectionY("R2_Z_0mu_0b_pred", 0, -1, "eo");
  //RatioPlots( Z_0b_0mu_MR, pred_MR_Z_0b_0mu, "Z(#nu#nu) MC 0-#mu BOX", "Z(#nu#nu) Pred 0-#mu BOX", "RatioPlots/Z_MR_0mu_0b_pred", "MR");
  //RatioPlots( Z_0b_0mu_R2, pred_R2_Z_0b_0mu, "Z(#nu#nu) MC 0-#mu BOX", "Z(#nu#nu) Pred 0-#mu BOX", "RatioPlots/Z_R2_0mu_0b_Pred", "RSQ");

  ////////////////////////////////////
  //////////tt 0mu box////////////////
  ////////////////////////////////////
  RatioPlots( tt_0b_0mu_MR, tt_2b_1mu_MR, "t#bar{t} MC 0-#mu 0b BOX", "t#bar{t} MC 1-#mu 2b BOX", "RatioPlots/tt_MR_0mu_to_1mu_0b_to_2b", "MR");
  RatioPlots( tt_0b_0mu_R2, tt_2b_1mu_R2, "t#bar{t} MC 0-#mu 0b BOX" , "t#bar{t} MC 1-#mu 2b BOX", "RatioPlots/tt_R2_0mu_to_1mu_0b_to_2b", "RSQ");
  TH2F* p_0b_0mu_tt = new TH2F( *data_2b_1mu );//tt prediction for 0b 0mu box
  TH2F* r_0b_0mu_tt = new TH2F( *tt_0b_0mu );
  r_0b_0mu_tt->Divide(tt_2b_1mu);
  p_0b_0mu_tt->Multiply(r_0b_0mu_tt);
  Integral = p_0b_0mu_tt->IntegralAndError(1, 6, 1, 6, error, "");
  std::cout << "---------6)-------" << std::endl;
  std::cout << "tt Prediction 0b 0mu box: " << Integral << " error: " << error << std::endl;
  TH1F* pred_MR_tt_0b_0mu = (TH1F*)p_0b_0mu_tt->ProjectionX("MR_tt_0mu_0b_pred", 0, -1, "eo");
  TH1F* pred_R2_tt_0b_0mu = (TH1F*)p_0b_0mu_tt->ProjectionY("R2_tt_0mu_0b_pred", 0, -1, "eo");
  RatioPlots( tt_0b_0mu_MR, pred_MR_tt_0b_0mu, "t#bar{t} MC 0-#mu BOX", "t#bar{t} Pred 0-#mu BOX", "PredPlots/tt_MR_0mu_0b_pred", "MR");
  RatioPlots( tt_0b_0mu_R2, pred_R2_tt_0b_0mu, "t#bat{t} MC 0-#mu BOX", "t#bar{t} Pred 0-#mu BOX", "PredPlots/tt_R2_0mu_0b_Pred", "RSQ");


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
  //bkg->Add(p_0b_0mu_tt);//Adding tt+jets prediction
  bkg->Add(tt_0b_0mu);//Adding tt+jets from MC
  bkg->Add(p_0b_0mu_dy);//Adding Z/gamma*(ll)+jets prediction
  bkg->Add(p_0b_0mu_Z);//Adding Z(nunu)+jets prediction
  Integral = bkg->IntegralAndError(1, 6, 1, 6, error, "");
  std::cout << "---------8)-------" << std::endl;
  std::cout << "Total bkg Prediction 0b 0mu box: " << Integral << " error: " << error << std::endl;
  TH1F* pred_MR_bkg_0b_0mu = (TH1F*)bkg->ProjectionX("MR_bkg_0mu_0b_pred", 0, -1, "eo");
  TH1F* pred_R2_bkg_0b_0mu = (TH1F*)bkg->ProjectionY("R2_bkg_0mu_0b_pred", 0, -1, "eo");
  //RatioPlotsBand( data_0b_0mu_MR, pred_MR_bkg_0b_0mu, "Data  0-#mu BOX", "Bkg Pred 0-#mu BOX", "PredPlots/Total_Bkg_MR_0mu_0b_pred_ttSem_tt1muMC", "MR");
  //RatioPlotsBand( data_0b_0mu_R2, pred_R2_bkg_0b_0mu, "Data  0-#mu BOX", "BKg Pred 0-#mu BOX", "PredPlots/Total_Bkg_R2_0mu_0b_Pred_ttSem_tt1muMC", "RSQ");
  RatioPlotsBand( data_0b_0mu_MR, pred_MR_bkg_0b_0mu, "Data  0-#mu BOX", "Bkg Pred 0-#mu BOX", "PredPlots/Total_Bkg_MR_0mu_0b_pred", "MR");
  RatioPlotsBand( data_0b_0mu_R2, pred_R2_bkg_0b_0mu, "Data  0-#mu BOX", "BKg Pred 0-#mu BOX", "PredPlots/Total_Bkg_R2_0mu_0b_Pred", "RSQ");
  
  
  ///////////////////////////////////////////////////////////
  ///////////////////Closure Test///////////////////////////
  /////////////////////////////////////////////////////////

  RatioPlots( W_0b_1mu_MR, dy_0b_2mu_MR, "Z/#gamma^{*} MC 1-#mu BOX", "Z/#gamma^{*} MC 2-#mu BOX", "RatioPlots/dy_MR_1mu_to_2mu", "MR");
  RatioPlots( W_0b_1mu_R2, dy_0b_2mu_R2, "Z/#gamma^{*} MC 1-#mu BOX", "Z/#gamma^{*} MC 2-#mu BOX", "RatioPlots/dy_R2_1mu_to_2mu", "RSQ");
  TH2F* pred_0b_1mu_W = new TH2F( *data_0b_2mu );//Drell-Yan prediction for 0b 1mu box
  //pred_0b_1mu_W->Add(data_1b_2mu, -1.0);//Subtracting tt 0b 2mu prediction
  p_0b_1mu_dy->Add(tt_0b_2mu, -1.0);//Subtracting tt 0b 2mu from MC                                                     
  TH2F* r_0b_1mu_W_closure = new TH2F( *W_0b_1mu );
  r_0b_1mu_W_closure->Divide(dy_0b_2mu);
  pred_0b_1mu_W->Multiply(r_0b_1mu_W_closure);
  Integral = pred_0b_1mu_W->IntegralAndError(1, 6, 1, 6, error, "");
  std::cout << "---------1)-------" << std::endl;
  std::cout << "W+jets Prediction 0b 1mu box: " << Integral << " error: " << error << std::endl;
  TH1F* pred_MR_W_clo_0b_1mu = (TH1F*)pred_0b_1mu_W->ProjectionX("MR_W_1mu_0b_pred_clo", 0, -1, "eo");
  TH1F* pred_R2_W_clo_0b_1mu = (TH1F*)pred_0b_1mu_W->ProjectionY("R2_W_1mu_0b_pred_clo", 0, -1, "eo");
  
  TH2F* mu1_BOX_Pred = new TH2F(*pred_0b_1mu_W);
  mu1_BOX_Pred->Add(p_0b_1mu_tt);
  mu1_BOX_Pred->Add(p_0b_1mu_dy);

  TH1F* mu1_BOX_Pred_MR = (TH1F*)mu1_BOX_Pred->ProjectionX("Pred_1mu_0b_MR",0,-1,"eo");
  TH1F* mu1_BOX_Pred_R2 = (TH1F*)mu1_BOX_Pred->ProjectionY("Pred_1mu_0b_R2",0,-1,"eo");
  
  
  RatioPlotsBand( data_0b_1mu_MR, mu1_BOX_Pred_MR, "Data 1-#mu BOX", "Pred 1-#mu BOX", "PredPlots/Closure_MR_1mu_0b_pred_clo", "MR");
  RatioPlotsBand( data_0b_1mu_R2, mu1_BOX_Pred_R2, "Data 1-#mu BOX", "Pred 1-#mu BOX", "PredPlots/Closure_R2_1mu_0b_Pred_clo", "RSQ");
  
  
  /////////////////////////////////////////////
  ////////////tt 1-mu 2b prediction///////////
  ////////////////////////////////////////////
  RatioPlots( tt_2b_1mu_MR, tt_1b_2mu_MR, "t#bar{t} MC 1-#mu2-b BOX", "t#bar{t} MC 2-#mu1b BOX", "RatioPlots/tt_MR_1mu_to_2mu_2b_1b", "MR");
  RatioPlots( tt_2b_1mu_R2, tt_1b_2mu_R2, "t#bar{t} MC 1-#mu2-b BOX", "t#bar{t} MC 2-#mu1b BOX", "RatioPlots/tt_R2_1mu_to_2mu_2b_1b", "RSQ");
  TH2F* pred_2b_1mu_tt = new TH2F( *data_1b_2mu );//tt prediction for 2b 1mu box
  TH2F* r_2b_1mu_tt = new TH2F( *tt_2b_1mu );
  r_2b_1mu_tt->Divide(tt_1b_2mu);
  pred_2b_1mu_tt->Multiply(r_2b_1mu_tt);
  Integral = pred_2b_1mu_tt->IntegralAndError(1, 6, 1, 6, error, "");
  std::cout << "---------1)-------" << std::endl;
  std::cout << "tt Prediction 2b 1mu box: " << Integral << " error: " << error << std::endl;
  TH2F* mu1_BOX_Pred_2b = new TH2F(*pred_2b_1mu_tt);
  TH1F* mu1_BOX_Pred_MR_2b = (TH1F*)mu1_BOX_Pred_2b->ProjectionX("Pred_1mu_2b_MR",0,-1,"eo");
  TH1F* mu1_BOX_Pred_R2_2b = (TH1F*)mu1_BOX_Pred_2b->ProjectionY("Pred_1mu_2b_R2",0,-1,"eo");
  
  RatioPlotsBand( data_2b_1mu_MR, mu1_BOX_Pred_MR_2b, "Data 1-#mu2-b BOX", "Pred 1-#mu2-b BOX", "PredPlots/Closure_MR_1mu_2b_pred_clo", "MR");
  RatioPlotsBand( data_2b_1mu_R2, mu1_BOX_Pred_R2_2b, "Data 1-#mu2-b BOX", "Pred 1-#mu2-b BOX", "PredPlots/Closure_R2_1mu_2b_Pred_clo", "RSQ");
  
  f->Close();
  f1->Close();
  F->Close();

  return 0;

}
