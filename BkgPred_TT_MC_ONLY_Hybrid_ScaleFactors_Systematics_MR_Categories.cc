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



//const int mrBins = 5;
//const int r2Bins = 5;
//const float BaseDM::RSQ_BinArr[] = {0.5, 0.6, 0.725, 0.85, 1.1, 2.50};
//const float BaseDM::MR_BinArr[] = {200., 300., 400., 600., 900., 3500.};

//4x4
const int mrBins = 4;
const float BaseDM::MR_BinArr[] = {200., 300., 400., 600., 3500.};
const int r2Bins1 = 7;
const float BaseDM::RSQ_BinArr1[] = {0.5, 0.55, 0.6, 65, 0.7, 0.8, 1.1, 2.50};
const int r2Bins2 = 6;
const float BaseDM::RSQ_BinArr2[] = {0.5, 0.55, 0.6, 0.7, 0.8, 1.1, 2.50};
const int r2Bins2 = 5;
const float BaseDM::RSQ_BinArr3[] = {0.5, 0.6, 0.7, 0.8, 1.1, 2.50};
const int r2Bins4 = 4;
const float BaseDM::RSQ_BinArr4[] = {0.5, 0.6, 0.725, 0.85, 2.50};


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
  TH2F* flag = new TH2F("flag", "flag", mrBins, BaseDM::MR_BinArr, r2Bins, BaseDM::RSQ_BinArr);
  TCanvas* cc = new TCanvas("cc", "cc", 640, 640);

  TFile* F = new TFile("FinalROOTFiles/VetoBtag_Parked_RunBCD_ParkedTrigger_btagCorr_ISR_March4_2014_4x4.root");
    
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

  TString ex_s = "_Hybrid_ScaleFactors";

  double tt_k2factor = 1.8034;
  double z_k2factor = 1.1973;
  double w_k2factor = 1.2455;
  
  
  ///////////////////////////////////////////////////////
  ///////////////Creating MR categories binned in R2/////
  //////////////////////////////////////////////////////

  


  /////////////////////////////////////////////////////////
  /////////////////DY 2mu Prediction//////////////////////
  ////////////////////////////////////////////////////////

  double data_2mu_total = data_0b_2mu->Integral();
  double MC_2mu_total = tt_k2factor*(tt_0b_2mu->Integral()) + z_k2factor*(dy_0b_2mu->Integral());

  std::cout << "=========Ratio Data/MC ====== 2mu:   " << data_2mu_total/MC_2mu_total << std::endl;

  TH2F* p_0b_2mu_dy = new TH2F(*data_0b_2mu);
  p_0b_2mu_dy->Add(tt_0b_2mu, -tt_k2factor);
  
  
  double error = -1.0;
  double Integral;
  ///////////////////////////////////////////////////
  /////////////////////Signal Prediction////////////
  /////////////////////////////////////////////////
  
  //////////////////////////////////////////
  ////////Drell-Yan 1 mu box///////////////
  /////////////////////////////////////////
  
  double sc_dy_1mu = dy_0b_1mu_MR->Integral();
  double sc_dy_2mu = dy_0b_2mu_MR->Integral();
  
  dy_0b_1mu_MR->Scale(1.0/dy_0b_1mu_MR->Integral());
  dy_0b_2mu_MR->Scale(1.0/dy_0b_2mu_MR->Integral());
  dy_0b_1mu_R2->Scale(1.0/dy_0b_1mu_R2->Integral());
  dy_0b_2mu_R2->Scale(1.0/dy_0b_2mu_R2->Integral());
  
  RatioPlots( dy_0b_1mu_MR, dy_0b_2mu_MR, "Z/#gamma^{*}(ll) MC 1-#mu BOX", "Z/#gamma^{*}(ll) MC 2-#mu BOX", "RatioPlots/dy_MR_1mu_to_2mu"+ex_s, "MR");
  RatioPlots( dy_0b_1mu_R2, dy_0b_2mu_R2, "Z/#gamma^{*}(ll) MC 1-#mu BOX", "Z/#gamma^{*}(ll) MC 2-#mu BOX", "RatioPlots/dy_R2_1mu_to_2mu"+ex_s, "RSQ");

  int TB = 4;//Toltal bins

  ///////////////////////////////////////////
  //////////DY Prediction 1mu BOX ///////////
  ///////////////////////////////////////////
 

  TH2F* p_0b_1mu_dy = new TH2F( *data_0b_2mu );//Drell-Yan prediction for 0b 1mu box
  p_0b_1mu_dy->Add(tt_0b_2mu, -tt_k2factor);//Subtracting tt 0b 2mu from MC
  TH2F* r_0b_1mu_dy = new TH2F( *dy_0b_1mu );
  r_0b_1mu_dy->Divide(dy_0b_2mu);
  p_0b_1mu_dy->Multiply(r_0b_1mu_dy);
  Integral = p_0b_1mu_dy->IntegralAndError(1, TB, 1, TB, error, "");
  std::cout << "---------1)-------" << std::endl;
  std::cout << "Drell-Yan Prediction 0b 1mu box: " << Integral << " error: " << error << std::endl;
  TH1F* pred_MR_dy_0b_1mu = (TH1F*)p_0b_1mu_dy->ProjectionX("MR_dy_1mu_0b_pred", 0, -1, "eo");
  TH1F* pred_R2_dy_0b_1mu = (TH1F*)p_0b_1mu_dy->ProjectionY("R2_dy_1mu_0b_pred", 0, -1, "eo");
    

  ////////////////////////////////////////
  //////////////////W 1mu/////////////////
  ////////////////////////////////////////
  TH2F* p_0b_1mu_W = new TH2F( *data_0b_1mu );//W prediction for 0b 1mu box
  p_0b_1mu_W->Add(tt_0b_1mu, -tt_k2factor);//Subtraction tt 1mu from MC
  p_0b_1mu_W->Add(p_0b_1mu_dy, -1.0);//Subtraction Drell-Yan 1mu prediction
  Integral = p_0b_1mu_W->IntegralAndError(1, TB, 1, TB, error, "");
  std::cout << "---------3)-------" << std::endl;
  std::cout << "W Prediction 0b 1mu box: " << Integral << " error: " << error << std::endl;
  TH1F* pred_MR_W_0b_1mu = (TH1F*)p_0b_1mu_W->ProjectionX("MR_W_1mu_0b_pred", 0, -1, "eo");
  TH1F* pred_R2_W_0b_1mu = (TH1F*)p_0b_1mu_W->ProjectionY("R2_W_1mu_0b_pred", 0, -1, "eo");
  
  ///////////////////////////////////
  /////////Drell-Yan 0 mu box////////
  //////////////////////////////////
  
  dy_0b_0mu_MR->Scale(1.0/dy_0b_0mu_MR->Integral());
  dy_0b_0mu_R2->Scale(1.0/dy_0b_0mu_R2->Integral());
  
  RatioPlots( dy_0b_0mu_MR, dy_0b_2mu_MR, "Z/#gamma^{*}(ll) MC 0-#mu BOX", "Z/#gamma^{*}(ll) MC 2-#mu BOX", "RatioPlots/dy_MR_0mu_to_2mu"+ex_s, "MR");
  RatioPlots( dy_0b_0mu_R2, dy_0b_2mu_R2, "Z/#gamma^{*}(ll) MC 0-#mu BOX", "Z/#gamma^{*}(ll) MC 2-#mu BOX", "RatioPlots/dy_R2_0mu_to_2mu"+ex_s, "RSQ");
  TH2F* p_0b_0mu_dy = new TH2F( *data_0b_2mu );//Drell-Yan prediction for 0b 0mu box
  p_0b_0mu_dy->Add(tt_0b_2mu, -tt_k2factor);//Subtracting tt 0b 2mu from MC
  TH2F* r_0b_0mu_dy = new TH2F( *dy_0b_0mu );
  r_0b_0mu_dy->Divide(dy_0b_2mu);
  p_0b_0mu_dy->Multiply(r_0b_0mu_dy);
  Integral = p_0b_0mu_dy->IntegralAndError(1, TB, 1, TB, error, "");
  std::cout << "---------4)-------" << std::endl;
  std::cout << "Drell-Yan Prediction 0b 0mu box: " << Integral << " error: " << error << std::endl;
  TH1F* pred_MR_dy_0b_0mu = (TH1F*)p_0b_0mu_dy->ProjectionX("MR_dy_0mu_0b_pred", 0, -1, "eo");
  TH1F* pred_R2_dy_0b_0mu = (TH1F*)p_0b_0mu_dy->ProjectionY("R2_dy_0mu_0b_pred", 0, -1, "eo");
  
  ////////////////////////////////////////
  /////////Z(nunu) 0 mu box///////////////
  ///////////////////////////////////////
  Z_0b_0mu_MR->Scale(1.0/Z_0b_0mu_MR->Integral());
  Z_0b_0mu_R2->Scale(1.0/Z_0b_0mu_R2->Integral());

  RatioPlots( Z_0b_0mu_MR, dy_0b_2mu_MR, "Z(#nu#nu) MC 0-#mu BOX", "Z/#gamma^{*}(ll) MC 2-#mu BOX", "RatioPlots/Z_MR_0mu_to_DY2mu"+ex_s, "MR");
  RatioPlots( Z_0b_0mu_R2, dy_0b_2mu_R2, "Z(#nu#nu) MC 0-#mu BOX", "Z/#gamma^{*}(ll) MC 2-#mu BOX", "RatioPlots/Z_R2_0mu_to_DY2mu"+ex_s, "RSQ");

  TH2F* p_0b_0mu_Z = new TH2F( *p_0b_1mu_W );//Z(nunu) prediction for 0b 0mu 
  TH2F* r_0b_0mu_Z = new TH2F( *Z_0b_0mu );
  r_0b_0mu_Z->Scale(z_k2factor);
  TH2F* W_0b_1mu_clone = new TH2F(*W_0b_1mu);
  W_0b_1mu_clone->Scale(w_k2factor);
  r_0b_0mu_Z->Divide(W_0b_1mu_clone);
  p_0b_0mu_Z->Multiply(r_0b_0mu_Z);
  Integral = p_0b_0mu_Z->IntegralAndError(1, TB, 1, TB, error, "");
  std::cout << "---------5)-------" << std::endl;
  std::cout << "Z(nunu) Prediction 0b 0mu box: " << Integral << " error: " << error << std::endl;
  TH1F* pred_MR_Z_0b_0mu = (TH1F*)p_0b_0mu_Z->ProjectionX("MR_Z_0mu_0b_pred", 0, -1, "eo");
  TH1F* pred_R2_Z_0b_0mu = (TH1F*)p_0b_0mu_Z->ProjectionY("R2_Z_0mu_0b_pred", 0, -1, "eo");
  
  /////////////////////////////////
  //////////W 0mu box//////////////
  ////////////////////////////////
  
  W_0b_0mu_MR->Scale(1.0/W_0b_0mu_MR->Integral());
  W_0b_0mu_R2->Scale(1.0/W_0b_0mu_R2->Integral());
  W_0b_1mu_MR->Scale(1.0/W_0b_1mu_MR->Integral());
  W_0b_1mu_R2->Scale(1.0/W_0b_1mu_R2->Integral());
  
  
  RatioPlots( W_0b_0mu_MR, W_0b_1mu_MR, "WJets MC 0-#mu BOX", "WJets MC 1-#mu BOX", "RatioPlots/W_MR_0mu_to_1mu"+ex_s, "MR");
  RatioPlots( W_0b_0mu_R2, W_0b_1mu_R2, "WJets MC 0-#mu BOX" , "WJets MC 1-#mu BOX", "RatioPlots/W_R2_0mu_to_1mu"+ex_s, "RSQ");
  
  RatioPlots( Z_0b_0mu_MR, W_0b_1mu_MR, "Z(#nu#nu) MC 0-#mu BOX", "WJets MC 1-#mu BOX", "RatioPlots/Z_MR_0mu_to_W1mu"+ex_s, "MR");
  RatioPlots( Z_0b_0mu_R2, W_0b_1mu_R2, "Z(#nu#nu) MC 0-#mu BOX", "WJets MC 1-#mu BOX", "RatioPlots/Z_R2_0mu_to_W1mu"+ex_s, "RSQ");

  TH2F* p_0b_0mu_W = new TH2F( *p_0b_1mu_W );//W prediction for 0b 0mu box
  TH2F* r_0b_0mu_W = new TH2F( *W_0b_0mu );
  r_0b_0mu_W->Divide(W_0b_1mu);
  p_0b_0mu_W->Multiply(r_0b_0mu_W);
  Integral = p_0b_0mu_W->IntegralAndError(1, TB, 1, TB, error, "");
  std::cout << "---------7)-------" << std::endl;
  std::cout << "W Prediction 0b 0mu box: " << Integral << " error: " << error << std::endl;
  TH1F* pred_MR_W_0b_0mu = (TH1F*)p_0b_0mu_W->ProjectionX("MR_W_0mu_0b_pred", 0, -1, "eo");
  TH1F* pred_R2_W_0b_0mu = (TH1F*)p_0b_0mu_W->ProjectionY("R2_W_0mu_0b_pred", 0, -1, "eo");
  
  ////////////////////////////////////////////
  ////////Total Prediction 0-mu box///////////
  ////////////////////////////////////////////
  TH2F* bkg = new TH2F( *p_0b_0mu_W );//Adding W+jets prediction
  bkg->Add(tt_0b_0mu, tt_k2factor);//Adding tt+jets from MC
  bkg->Add(p_0b_0mu_dy);//Adding Z/gamma*(ll)+jets prediction
  bkg->Add(p_0b_0mu_Z);//Adding Z(nunu)+jets prediction
  Integral = bkg->IntegralAndError(1, TB, 1, TB, error, "");
  std::cout << "---------8)-------" << std::endl;
  std::cout << "==============Total bkg Prediction 0b 0mu box: " << Integral << " error: " << error << "==============" << std::endl;
  Integral = data_0b_0mu->IntegralAndError(1, TB, 1, TB, error, "");
  std::cout << "======= Data Signal Region: " << Integral << " error: " << error << "============" << std::endl;
  
  TH1F* pred_MR_bkg_0b_0mu = (TH1F*)bkg->ProjectionX("MR_bkg_0mu_0b_pred", 0, -1, "eo");
  TH1F* pred_R2_bkg_0b_0mu = (TH1F*)bkg->ProjectionY("R2_bkg_0mu_0b_pred", 0, -1, "eo");
  RatioPlotsBand( data_0b_0mu_MR, pred_MR_bkg_0b_0mu, "Data  0-#mu BOX", "Bkg Pred 0-#mu BOX", "PredPlots/Total_Bkg_MR_0mu_0b_pred"+ex_s, "MR");
  RatioPlotsBand( data_0b_0mu_R2, pred_R2_bkg_0b_0mu, "Data  0-#mu BOX", "BKg Pred 0-#mu BOX", "PredPlots/Total_Bkg_R2_0mu_0b_Pred"+ex_s, "RSQ");
  
  //////////////////////////////////////////////////////////
  //////////////Flag Plot//////////////////////////////////
  ////////////////////////////////////////////////////////

  for(int b1 = 1; b1 <= mrBins; b1++){
    for(int b2 = 1; b2 <= r2Bins; b2++){
      double r_data_exp = bkg->GetBinContent(b1,b2)/data_0b_0mu->GetBinContent(b1,b2);
      //std::cout << r_data_exp << std::endl;
      flag->SetBinContent(b1,b2,r_data_exp);
    }
  }

  flag->SetStats(0);
  gPad->SetLogy();
  gPad->SetLogx();
  flag->SetMaximum(2);
  flag->SetMinimum(0.0);
  flag->Draw("colztext");
  cc->SaveAs("flag.pdf");
  cc->SaveAs("flag.png");

  ///////////////////////////////////////////////////////////
  ///////////////////Closure Test///////////////////////////
  /////////////////////////////////////////////////////////

  RatioPlots( W_0b_1mu_MR, dy_0b_2mu_MR, "WJets MC 1-#mu BOX", "Z/#gamma^{*}(ll) MC 2-#mu BOX", "RatioPlots/W_MR_1mu_to_DY2mu"+ex_s, "MR");
  RatioPlots( W_0b_1mu_R2, dy_0b_2mu_R2, "WJets MC 1-#mu BOX", "Z/#gamma^{*}(ll) MC 2-#mu BOX", "RatioPlots/W_R2_1mu_to_DY2mu"+ex_s, "RSQ");
  
  Integral = data_0b_2mu->IntegralAndError(1, TB, 1, TB, error, "");
  std::cout << "======= 2mu box Data=======: " << Integral << " error: " << error << "============" << std::endl;

  TH2F* pred_0b_1mu_W = new TH2F( *data_0b_2mu );//Drell-Yan prediction for 0b 1mu box
  pred_0b_1mu_W->Add(tt_0b_2mu, -tt_k2factor);//Subtracting tt 0b 2mu from MC    
  Integral = pred_0b_1mu_W->IntegralAndError(1, TB, 1, TB, error, "");
  std::cout << "======= 2mu box Data ttbar subtracted=======: " << Integral << " error: " << error << "============" << std::endl;
  
  TH2F* r_0b_1mu_W_closure = new TH2F( *W_0b_1mu );//W+Jets (1Mu-0Btag)
  r_0b_1mu_W_closure->Scale(w_k2factor);
  TH2F* dy_0b_2mu_clone = new TH2F(*dy_0b_2mu);
  dy_0b_2mu_clone->Scale(z_k2factor);
  r_0b_1mu_W_closure->Divide(dy_0b_2mu_clone);//Z(ll) (2Mu-0Btag)
  pred_0b_1mu_W->Multiply(r_0b_1mu_W_closure);//Actual Prediction
  
  TH2F* mu1_BOX_Pred = new TH2F(*pred_0b_1mu_W);
  mu1_BOX_Pred->Add(tt_0b_1mu, tt_k2factor);
  mu1_BOX_Pred->Add(p_0b_1mu_dy);

  Integral = mu1_BOX_Pred->IntegralAndError(1, TB, 1, TB, error, "");
  std::cout << "---------9 Closure Test)-------" << std::endl;
  std::cout << "======= 1mu box Prediction=======: " << Integral << " error: " << error << "============" << std::endl;
  Integral = data_0b_1mu->IntegralAndError(1, TB, 1, TB, error, "");
  std::cout << "======= Data 1mu-0Btag===========: " << Integral << " error: " << error << "============" << std::endl;

  TH1F* mu1_BOX_Pred_MR = (TH1F*)mu1_BOX_Pred->ProjectionX("Pred_1mu_0b_MR", 1, TB,"eo");
  TH1F* mu1_BOX_Pred_R2 = (TH1F*)mu1_BOX_Pred->ProjectionY("Pred_1mu_0b_R2", 1, TB,"eo");
  RatioPlotsBand( data_0b_1mu_MR, mu1_BOX_Pred_MR, "Data 1-#mu BOX", "Pred 1-#mu BOX", "PredPlots/Closure_MR_1mu_0b_pred_clo"+ex_s, "MR");
  RatioPlotsBand( data_0b_1mu_R2, mu1_BOX_Pred_R2, "Data 1-#mu BOX", "Pred 1-#mu BOX", "PredPlots/Closure_R2_1mu_0b_Pred_clo"+ex_s, "RSQ");


  ///////////////////////
  ////SYSTEMATICS///////
  //////////////////////
  
  TH2D* sys = new TH2D("sys","sys", 4, BaseDM::MR_BinArr, 4, BaseDM::RSQ_BinArr);
  
  for(int i = 1; i <= mu1_BOX_Pred->GetNbinsX(); i++){
    for(int j = 1; j <= mu1_BOX_Pred->GetNbinsY(); j++){
      double sysf = fabs(mu1_BOX_Pred->GetBinContent(i,j) - data_0b_1mu->GetBinContent(i,j))/mu1_BOX_Pred->GetBinContent(i,j);
      if(sysf < 10000){
	sys->SetBinContent(i,j, sysf);
	std::cout << " Sys Factor (i,j): ("  << i << " , "<< j << ") " << sys->GetBinContent(i,j) << std::endl;
      }else{
	sys->SetBinContent(i,j, 4*mu1_BOX_Pred->GetBinError(i,j));
	std::cout << "Unknown value!!" << std::endl;
      }
    }
  }
  
  
  TH2F* mu1_BOX_Pred_sys = new TH2F(*mu1_BOX_Pred);
  
  for(int i = 1; i <= mu1_BOX_Pred->GetNbinsX(); i++){
    for(int j = 1; j <= mu1_BOX_Pred->GetNbinsY(); j++){
      
      if(sys->GetBinContent(i,j) != 0.0 ){
	//double err = sqrt(pow(4*sys->GetBinContent(i,j)*mu1_BOX_Pred_sys->GetBinError(i,j) ,2) + mu1_BOX_Pred_sys->GetBinError(i,j)*mu1_BOX_Pred_sys->GetBinError(i,j));
	double err = sys->GetBinContent(i,j)*mu1_BOX_Pred_sys->GetBinContent(i,j);
	err = sqrt(err*err + mu1_BOX_Pred_sys->GetBinError(i,j)*mu1_BOX_Pred_sys->GetBinError(i,j));
	//std::cout << "extra error: " << sys->GetBinContent(i,j)*mu1_BOX_Pred_sys->GetBinError(i,j) << std::endl;
	std::cout << "current error: " << mu1_BOX_Pred_sys->GetBinError(i,j) << ",  new error: " << err << " Delta: " << mu1_BOX_Pred_sys->GetBinContent(i,j) - data_0b_1mu->GetBinContent(i,j) << std::endl;
	mu1_BOX_Pred_sys->SetBinError(i,j, err);
      }else{
	std::cout << "Error Left Invariant!!" << std::endl;
      }
    }
   }

  
  
  TH1F* mu1_BOX_Pred_MR_sys = (TH1F*)mu1_BOX_Pred_sys->ProjectionX("Pred_1mu_0b_MR_sys", 1, 6,"eo");
  TH1F* mu1_BOX_Pred_R2_sys = (TH1F*)mu1_BOX_Pred_sys->ProjectionY("Pred_1mu_0b_R2_sys", 1, 6,"eo");
  
  RatioPlotsBand( data_0b_1mu_MR, mu1_BOX_Pred_MR_sys, "Data 1-#mu BOX", "Pred 1-#mu BOX", "PredPlots/Closure_MR_1mu_0b_pred_clo_sys"+ex_s, "MR");
  RatioPlotsBand( data_0b_1mu_R2, mu1_BOX_Pred_R2_sys, "Data 1-#mu BOX", "Pred 1-#mu BOX", "PredPlots/Closure_R2_1mu_0b_Pred_clo_sys"+ex_s, "RSQ");

  Integral = mu1_BOX_Pred_sys->IntegralAndError(1, TB, 1, TB, error, "");
  std::cout << "---------10 Closure Test SYS)-------" << std::endl;
  std::cout << "======= 1mu box Prediction=======: " << Integral << " error: " << error << "============" << std::endl;
  Integral = data_0b_1mu->IntegralAndError(1, TB, 1, TB, error, "");
  std::cout << "======= Data 1mu-0Btag===========: " << Integral << " error: " << error << "============" << std::endl;


  //1d Version
  TH1D* sys_1d = new TH1D("sys_1d","sys_1d", 4, BaseDM::MR_BinArr);
  for(int i = 1; i <= mu1_BOX_Pred_MR->GetNbinsX(); i++){
    double sysf = fabs(mu1_BOX_Pred_MR->GetBinContent(i) - data_0b_1mu_MR->GetBinContent(i))/mu1_BOX_Pred_MR->GetBinContent(i);
      if(sysf < 10000){
	sys_1d->SetBinContent(i, sysf);
	std::cout << " Sys Factor (i): ("  << i << ") " << sys_1d->GetBinContent(i) << std::endl;
      }else{
	sys->SetBinContent(i, 0.0);
	std::cout << "Unknown value!!" << std::endl;
      }
  }

  TH1F* mu1_BOX_Pred_MR_sys_v2 = new TH1F(*mu1_BOX_Pred_MR);
  for(int i = 1; i <= mu1_BOX_Pred_MR->GetNbinsX(); i++){
    double err = sys_1d->GetBinContent(i)*mu1_BOX_Pred_MR_sys_v2->GetBinContent(i);
    std::cout << "Err 1d:  " << err << " diff: " << mu1_BOX_Pred_MR_sys_v2->GetBinContent(i) - data_0b_1mu_MR->GetBinContent(i) << std::endl;
    mu1_BOX_Pred_MR_sys_v2->SetBinError(i,err);
  }
  RatioPlotsBand( data_0b_1mu_MR, mu1_BOX_Pred_MR_sys_v2, "Data 1-#mu BOX", "Pred 1-#mu BOX", "PredPlots/Closure_MR_1mu_0b_pred_clo_sys_v2"+ex_s, "MR");
  
  

  //Apply Systematic to Full Prediction
  TH2F* bkg_sys = new TH2F(*bkg);
  tt_0b_0mu->Scale(tt_k2factor);
  double err_f = 0.9;
  for(int i = 1; i <= bkg->GetNbinsX(); i++){
    for(int j = 1; j <= bkg->GetNbinsY(); j++){
      
      if(sys->GetBinContent(i,j) != 0.0 ){
	double err = sqrt(pow(err_f*sys->GetBinContent(i,j)*bkg_sys->GetBinContent(i,j) ,2) + bkg_sys->GetBinError(i,j)*bkg_sys->GetBinError(i,j));
	bkg_sys->SetBinError(i,j, err);
	bkg->SetBinError(i,j, err);
	if(i == 3 && j ==1){
	  bkg_sys->SetBinError(i,j, err/8.0);
	  bkg->SetBinError(i,j, err/8.0);
	}
	std::cout << "=========ERROR FINAL PREDICTION: ("  << i << " , "<< j << ") " << bkg_sys->GetBinError(i,j) << std:: endl;
	bkg->SetBinError(i,j, err);
	err = sqrt(pow(err_f*sys->GetBinContent(i,j)*p_0b_0mu_W->GetBinContent(i,j) ,2) + p_0b_0mu_W->GetBinError(i,j)*p_0b_0mu_W->GetBinError(i,j));
	p_0b_0mu_W->SetBinError(i,j, err);
	if(i == 3 && j ==1)p_0b_0mu_W->SetBinError(i,j, err/8.0);
	err = sqrt(pow(err_f*sys->GetBinContent(i,j)*p_0b_0mu_Z->GetBinContent(i,j) ,2) + p_0b_0mu_Z->GetBinError(i,j)*p_0b_0mu_Z->GetBinError(i,j));
	p_0b_0mu_Z->SetBinError(i,j, err);
	if(i == 3 && j ==1)p_0b_0mu_Z->SetBinError(i,j, err/8.0);
	//err = sqrt(pow(1.0*sys->GetBinContent(i,j)*p_0b_0mu_dy->GetBinContent(i,j) ,2) + p_0b_0mu_dy->GetBinError(i,j)*p_0b_0mu_dy->GetBinError(i,j));
	//p_0b_0mu_dy->SetBinError(i,j, err);
	err = 2*p_0b_0mu_dy->GetBinError(i,j);
	p_0b_0mu_dy->SetBinError(i,j, err);
	err = 2*tt_0b_0mu->GetBinError(i,j);
	tt_0b_0mu->SetBinError(i,j, err);
      }else{
	std::cout << "Error Left Invariant!!" << std::endl;
      }
    }
   }
  
  
  TH1F* pred_MR_bkg_0b_0mu_sys = (TH1F*)bkg_sys->ProjectionX("MR_bkg_0mu_0b_pred_sys", 0, -1, "eo");
  TH1F* pred_R2_bkg_0b_0mu_sys = (TH1F*)bkg_sys->ProjectionY("R2_bkg_0mu_0b_pred_sys", 0, -1, "eo");
  RatioPlotsBand( data_0b_0mu_MR, pred_MR_bkg_0b_0mu_sys, "Data  0-#mu BOX", "Bkg Pred 0-#mu BOX", "PredPlots/Total_Bkg_MR_0mu_0b_pred_sys"+ex_s, "MR");
  RatioPlotsBand( data_0b_0mu_R2, pred_R2_bkg_0b_0mu_sys, "Data  0-#mu BOX", "BKg Pred 0-#mu BOX", "PredPlots/Total_Bkg_R2_0mu_0b_Pred_sys"+ex_s, "RSQ");


  std::cout << "---------11)-------" << std::endl;
  Integral = bkg_sys->IntegralAndError(1, TB, 1, TB, error, "");
  std::cout << "==============Total bkg Prediction 0b 0mu box SYS: " << Integral << " error: " << error << "==============" << std::endl;
  Integral = data_0b_0mu->IntegralAndError(1, TB, 1, TB, error, "");
  std::cout << "======= Data Signal Region: " << Integral << " error: " << error << "============" << std::endl;

  ////////////////////////

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

  tt_mu[0] = tt_0b_0mu->IntegralAndError(1,mrBins, tt_mu_E[0]);
  tt_mu[1] = tt_0b_1mu->IntegralAndError(1,mrBins, tt_mu_E[1]);
  tt_mu[2] = tt_0b_2mu->IntegralAndError(1,mrBins, tt_mu_E[2]);

  dy_mu[0] = p_0b_0mu_dy->IntegralAndError(1,mrBins, dy_mu_E[0]);
  dy_mu[1] = p_0b_1mu_dy->IntegralAndError(1,mrBins, dy_mu_E[1]);
  dy_mu[2] = p_0b_2mu_dy->IntegralAndError(1,mrBins, dy_mu_E[2]);

  w_mu[0] = p_0b_0mu_W->IntegralAndError(1,mrBins, w_mu_E[0]);
  w_mu[1] = p_0b_1mu_W->IntegralAndError(1,mrBins, w_mu_E[1]);
  //w_mu[2] = MR_RSQ_2BOX_W->IntegralAndError(1,4, w_mu_E[2]);
  
  z_mu[0] = p_0b_0mu_Z->IntegralAndError(1,mrBins, z_mu_E[0]);
  //z_mu[1] = MR_RSQ_1BOX_Z->IntegralAndError(1,4, z_mu_E[1]);
  //z_mu[2] = MR_RSQ_2BOX_Z->IntegralAndError(1,4, z_mu_E[2]);
  
  double tot_0mu = tt_mu[0]+dy_mu[0]+w_mu[0]+z_mu[0];
  double tot_1mu = tt_mu[1]+dy_mu[1]+w_mu[1]+z_mu[1];
  double tot_2mu = tt_mu[2]+dy_mu[2]+w_mu[2]+z_mu[2];

  double tot_0mu_E = sqrt(tt_mu_E[0]*tt_mu_E[0] + dy_mu_E[0]*dy_mu_E[0] + w_mu_E[0]*w_mu_E[0] + z_mu_E[0]*z_mu_E[0]);
  double tot_1mu_E = sqrt(tt_mu_E[1]*tt_mu_E[1] + dy_mu_E[1]*dy_mu_E[1] + w_mu_E[1]*w_mu_E[1] + z_mu_E[1]*z_mu_E[1]);
  double tot_2mu_E = sqrt(tt_mu_E[2]*tt_mu_E[2] + dy_mu_E[2]*dy_mu_E[2] + w_mu_E[2]*w_mu_E[2] + z_mu_E[2]*z_mu_E[2]);

  std::ofstream ofs("Yields.tex", std::ofstream::out);
  
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

  TFile *bkg_file_1DRsq = new TFile("Pred_Files/Bkg_Pred_1D_Rsq_ttMC_LO_RunAB_2sys.root","RECREATE");
  bkg_file_1DRsq->cd();
  pred_R2_bkg_0b_0mu_sys->Write("bkg_rsq");
  data_0b_0mu_R2->Write("data_rsq");
  
  TH1F *bkg_rsq_alphaUp = new TH1F("bkg_rsq_alphaUp","bkg_rsq_alphaUp",r2Bins, BaseDM::RSQ_BinArr);
  TH1F *bkg_rsq_alphaDown = new TH1F("bkg_rsq_alphaDown","bkg_rsq_alphaDown",r2Bins, BaseDM::RSQ_BinArr);

  //Individual RSQ Predictions
  TH1F* p_w_1d_rsq = (TH1F*)p_0b_0mu_W->ProjectionY("w_rsq",0,-1,"eo");
  TH1F* p_z_1d_rsq = (TH1F*)p_0b_0mu_Z->ProjectionY("z_rsq",0,-1,"eo");
  TH1F* p_dy_1d_rsq = (TH1F*)p_0b_0mu_dy->ProjectionY("dy_rsq",0,-1,"eo");
  TH1F* p_tt_1d_rsq = (TH1F*)tt_0b_0mu->ProjectionY("tt_rsq",0,-1,"eo");
  
  //Up and Down Histo for RSQ prediction
  TH1F *w_rsq = new TH1F("w_rsq","w_rsq",r2Bins, BaseDM::RSQ_BinArr);
  TH1F *w_rsq_alphaUp = new TH1F("w_rsq_alphaUp","w_rsq_alphaUp",r2Bins, BaseDM::RSQ_BinArr);
  TH1F *w_rsq_alphaDown = new TH1F("w_rsq_alphaDown","w_rsq_alphaDown",r2Bins, BaseDM::RSQ_BinArr);
  
  TH1F *z_rsq = new TH1F("z_rsq","z_rsq",r2Bins, BaseDM::RSQ_BinArr);
  TH1F *z_rsq_alphaUp = new TH1F("z_rsq_alphaUp","z_rsq_alphaUp",r2Bins, BaseDM::RSQ_BinArr);
  TH1F *z_rsq_alphaDown = new TH1F("z_rsq_alphaDown","z_rsq_alphaDown",r2Bins, BaseDM::RSQ_BinArr);
  
  TH1F *dy_rsq = new TH1F("dy_rsq","dy_rsq",r2Bins, BaseDM::RSQ_BinArr);
  TH1F *dy_rsq_alphaUp = new TH1F("dy_rsq_alphaUp","dy_rsq_alphaUp",r2Bins, BaseDM::RSQ_BinArr);
  TH1F *dy_rsq_alphaDown = new TH1F("dy_rsq_alphaDown","dy_rsq_alphaDown",r2Bins, BaseDM::RSQ_BinArr);
  
  TH1F *tt_rsq = new TH1F("tt_rsq","tt_rsq",r2Bins, BaseDM::RSQ_BinArr);
  TH1F *tt_rsq_alphaUp = new TH1F("tt_rsq_alphaUp","tt_rsq_alphaUp",r2Bins, BaseDM::RSQ_BinArr);
  TH1F *tt_rsq_alphaDown = new TH1F("tt_rsq_alphaDown","tt_rsq_alphaDown",r2Bins, BaseDM::RSQ_BinArr);
  
  for(int z = 1; z <= r2Bins; z++){
    double binValue = pred_R2_bkg_0b_0mu->GetBinContent(z);
    double error = pred_R2_bkg_0b_0mu->GetBinError(z);
    
    bkg_rsq_alphaUp->SetBinContent(z,binValue+error);
    bkg_rsq_alphaDown->SetBinContent(z,binValue-error);
    
    double bv_w = p_w_1d_rsq->GetBinContent(z);
    double be_w = p_w_1d_rsq->GetBinError(z);
    w_rsq->SetBinContent(z,bv_w);
    w_rsq_alphaUp->SetBinContent(z,bv_w + be_w);
    w_rsq_alphaDown->SetBinContent(z,bv_w - be_w);
    
    double bv_z = p_z_1d_rsq->GetBinContent(z);
    double be_z = p_z_1d_rsq->GetBinError(z);
    z_rsq->SetBinContent(z,bv_z);
    z_rsq_alphaUp->SetBinContent(z,bv_z + be_z);
    z_rsq_alphaDown->SetBinContent(z,bv_z - be_z);
    
    double bv_dy = p_dy_1d_rsq->GetBinContent(z);
    double be_dy = p_dy_1d_rsq->GetBinError(z);
    dy_rsq->SetBinContent(z,bv_dy);
    dy_rsq_alphaUp->SetBinContent(z,bv_dy + be_dy);
    dy_rsq_alphaDown->SetBinContent(z,bv_dy - be_dy);

    double bv_tt = p_tt_1d_rsq->GetBinContent(z);
    double be_tt = p_tt_1d_rsq->GetBinError(z);
    tt_rsq->SetBinContent(z,bv_tt);
    tt_rsq_alphaUp->SetBinContent(z,bv_tt + be_tt);
    tt_rsq_alphaDown->SetBinContent(z,bv_tt - be_tt);

  }
  
  bkg_rsq_alphaUp->Write("bkg_rsq_epsilonUp");
  bkg_rsq_alphaDown->Write("bkg_rsq_epsilonDown");
  
  w_rsq->Write();
  w_rsq_alphaUp->Write("w_rsq_zetaUp");
  w_rsq_alphaDown->Write("w_rsq_zetaDown");
  
  z_rsq->Write();
  z_rsq_alphaUp->Write("z_rsq_deltaUp");
  z_rsq_alphaDown->Write("z_rsq_deltaDown");
  
  dy_rsq->Write();
  dy_rsq_alphaUp->Write("dy_rsq_gammaUp");
  dy_rsq_alphaDown->Write("dy_rsq_gammaDown");
  
  tt_rsq->Write();
  tt_rsq_alphaUp->Write("tt_rsq_betaUp");
  tt_rsq_alphaDown->Write("tt_rsq_betaDown");
  
  TFile *bkg_file_2D = new TFile("Pred_Files/BkgPred_ttMC_LO_RunAB_2sys.root","RECREATE");

  bkg_file_2D->cd();
  bkg_sys->Write("BkgPred_2d");
  data_0b_0mu->Write("Data_2d");
  mu1_BOX_Pred_sys->Write("closure_Pred_2d");
  data_0b_1mu->Write("Data_1mu_2d");
  
  bkg_file_2D->cd();

  
  bkg_file_1DRsq->cd();
  bkg_file_2D->cd();
  
  TH2F *bkg_alphaUp = new TH2F("bkg_alphaUp","bkg_alphaUp",mrBins, BaseDM::MR_BinArr,r2Bins, BaseDM::RSQ_BinArr);
  TH2F *bkg_alphaDown = new TH2F("bkg_alphaDown","bkg_alphaUp",mrBins, BaseDM::MR_BinArr,r2Bins, BaseDM::RSQ_BinArr);


  for (int x = 1; x <= mrBins; x++) //mr 
    {
      for (int y = 1; y< r2Bins; y++) // rsq                                           
	{
	  double value_in =bkg->GetBinContent(x,y);
	  double error_low = bkg->GetBinError(x,y);
	  double error_high = bkg->GetBinError(x,y);
	  bkg_alphaUp->SetBinContent(x,y,value_in+error_high);
	  bkg_alphaDown->SetBinContent(x,y,value_in-error_low);
	}
    }
  bkg_file_2D->cd();
  
  TH1F *bkg_1D = new TH1F("bkg_1D","bkg_1D",mrBins*r2Bins,0,mrBins*r2Bins);
  TH1F *bkg_1D_alphaUp = new TH1F("bkg_1D_alphaUp","bkg_1D_alphaUp",mrBins*r2Bins,0,mrBins*r2Bins);
  TH1F *bkg_1D_alphaDown = new TH1F("bkg_1D_alphaDown","bkg_1D_alphaDown",mrBins*r2Bins,0,mrBins*r2Bins);
  TH1F *data_1D_unwrapt = new TH1F("data_unwrapt","data_Unwrapt_16bins",mrBins*r2Bins,0,mrBins*r2Bins);
  
  TH1F *tt_1D = new TH1F("tt_1D","tt_1D",mrBins*r2Bins,0,mrBins*r2Bins);
  TH1F *tt_1D_alphaUp = new TH1F("tt_1D_alphaUp","tt_1D_alphaUp",mrBins*r2Bins,0,mrBins*r2Bins);
  TH1F *tt_1D_alphaDown = new TH1F("tt_1D_alphaDown","tt_1D_alphaDown",mrBins*r2Bins,0,mrBins*r2Bins);
  
  TH1F *dy_1D = new TH1F("dy_1D","dy_1D",mrBins*r2Bins,0,mrBins*r2Bins);
  TH1F *dy_1D_alphaUp = new TH1F("dy_1D_alphaUp","dy_1D_alphaUp",mrBins*r2Bins,0,mrBins*r2Bins);
  TH1F *dy_1D_alphaDown = new TH1F("dy_1D_alphaDown","dy_1D_alphaDown",mrBins*r2Bins,0,mrBins*r2Bins);
  
  TH1F *z_1D = new TH1F("z_1D","z_1D",mrBins*r2Bins,0,mrBins*r2Bins);
  TH1F *z_1D_alphaUp = new TH1F("z_1D_alphaUp","z_1D_alphaUp",mrBins*r2Bins,0,mrBins*r2Bins);
  TH1F *z_1D_alphaDown = new TH1F("z_1D_alphaDown","z_1D_alphaDown",mrBins*r2Bins,0,mrBins*r2Bins);
  
  TH1F *w_1D = new TH1F("w_1D","w_1D",mrBins*r2Bins,0,mrBins*r2Bins);
  TH1F *w_1D_alphaUp = new TH1F("w_1D_alphaUp","w_1D_alphaUp",mrBins*r2Bins,0,mrBins*r2Bins);
  TH1F *w_1D_alphaDown = new TH1F("w_1D_alphaDown","w_1D_alphaDown",mrBins*r2Bins,0,mrBins*r2Bins);
  
  
  int counter = 0;
  for ( int i=1; i<= mrBins; i++){
    for (int j=1; j<= r2Bins; j++){
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
      //std::cout << "error: " << w_e << " w_l: " << w_l << " w_u: " << w_l << " w_c-w_l: " << w_c-w_l << std::endl;
      //std::cout << "error: " << z_e << " z_l: " << z_l << " z_u: " << z_l << " z_c-z_l: " << z_c-z_l << std::endl;
      //std::cout << "error: " << dy_e << " dy_l: " << dy_l << " dy_u: " << dy_l << " dy_c-dy_l: " << dy_c-dy_l << std::endl;
      //std::cout << "error: " << tt_e << " tt_l: " << tt_l << " tt_u: " << tt_l << " tt_c-tt_l: " << tt_c-tt_l << std::endl;
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
    
  std::cout << "HERE!!!" << std::endl;
  
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

  std::cout << "HERE1!!!" << std::endl;

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

  std::cout << "HERE2!!!" << std::endl;

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
  
  bkg_file_2D->cd();
  
  
  bkg_file_2D->Close();
  bkg_file_1DRsq->Close();
  
  return 0;

}
