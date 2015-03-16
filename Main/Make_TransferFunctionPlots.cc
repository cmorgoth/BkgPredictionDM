#include <iostream>
#include <fstream>
#include <vector>
#include "Math.h"

//ROOT
#include "TROOT.h"
#include "TH1F.h"
#include "TFile.h"
#include "TH2F.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TColor.h"
#include "TLegend.h"
#include "TPad.h"
#include "TString.h"
#include "TLatex.h"


bool PlotCosmetics(TH1F*, TString, TString);
int CreateZeroB();
int CreateOneB();
int CreateTwoB();

int main(){
  CreateZeroB();
  CreateOneB();
  CreateTwoB();

  return 0;
}

int CreateZeroB(){
  TFile* F = new TFile("/Users/cmorgoth/Software/git/BkgPredictionDM/PredFilesAN/MR_Cat_PredV2_NEW_kF_OriginalANA.root");
  
  //Bkg Prediction Ratios
  TH1F* TF_Z_W[4];
  TH1F* TF_W_W[4];
  TH1F* TF_DY0mu_DY2mu[4];

  //Closure Test Ratios
  TH1F* TF_W_DY[4];
  TH1F* TF_DY1mu_DY2mu[4];
  
  TString name;
  for(int i = 0; i < 4; i++){
    name = TString(Form("cat%d_Z0mu_to_W1mu", i+1));
    TF_Z_W[i] = (TH1F*)F->Get(name);
    name = TString(Form("cat%d_W0mu_to_W1mu", i+1));
    TF_W_W[i] = (TH1F*)F->Get(name);
    name = TString(Form("cat%d_DY0mu_to_DY2mu", i+1));
    TF_DY0mu_DY2mu[i] = (TH1F*)F->Get(name);
    //Closure Ratios
    name = TString(Form("cat%d_W1mu_to_DY2mu", i+1));
    TF_W_DY[i] = (TH1F*)F->Get(name);
    name = TString(Form("cat%d_DY1mu_to_DY2mu", i+1));
    TF_DY1mu_DY2mu[i] = (TH1F*)F->Get(name);
  }

  TFile* fsys = new TFile("/Users/cmorgoth/Software/git/BkgPredictionDM/PredFilesAN/Sys_for_Ana.root");
  TH1F* sys[4];
  for(int i = 0; i < 4; i++){
    TString fn = TString(Form("cat%d_SYS", i+1));
    sys[i] = (TH1F*)fsys->Get(fn);
  }

  //Apply systematic
  for(int i = 0; i < 4; i++){
    for(int j = 1; j <= sys[i]->GetNbinsX(); j++){
      double err = pow(TF_Z_W[i]->GetBinContent(j)*sys[i]->GetBinContent(j),2) 
	+ pow(TF_Z_W[i]->GetBinError(j), 2);
      TF_Z_W[i]->SetBinError(j, sqrt(err));
      
      err =  pow(TF_W_W[i]->GetBinContent(j)*sys[i]->GetBinContent(j),2) 
	+ pow(TF_W_W[i]->GetBinError(j), 2);
      TF_W_W[i]->SetBinError(j, sqrt(err));
      
      err = pow(TF_DY0mu_DY2mu[i]->GetBinContent(j)*sys[i]->GetBinContent(j),2) 
	+ pow(TF_DY0mu_DY2mu[i]->GetBinError(j), 2);
      TF_DY0mu_DY2mu[i]->SetBinError(j, sqrt(err));
      
      err = pow(TF_W_DY[i]->GetBinContent(j)*sys[i]->GetBinContent(j),2) 
	+ pow(TF_W_DY[i]->GetBinError(j), 2);
      TF_W_DY[i]->SetBinError(j, sqrt(err));
      
      err = pow(TF_DY1mu_DY2mu[i]->GetBinContent(j)*sys[i]->GetBinContent(j),2) 
	+ pow(TF_DY1mu_DY2mu[i]->GetBinError(j), 2);
      TF_DY1mu_DY2mu[i]->SetBinError(j, sqrt(err));
    }
  }

  TString p_name, l_name;
  //Z(0mu) to W(1mu)
  for(int i = 0; i < 4; i++){
    p_name = TString(Form("TF_Plots/TF_Z0mu_W1mu_cat%d", i+1));
    switch(i){
    case 0:
      l_name = "TF Z(0#mu) to W(1#mu) cat(VL)";
      break;
    case 1:
      l_name = "TF Z(0#mu) to W(1#mu) cat(L)";
      break;
    case 2:
      l_name = "TF Z(0#mu) to W(1#mu) cat(H)";
      break;
    case 3:
      l_name = "TF Z(0#mu) to W(1#mu) cat(VH)";
      break;
    default:
      break;
    }
    PlotCosmetics(TF_Z_W[i], p_name, l_name);
  }
  
  //W(0mu) to W(1mu)
  for(int i = 0; i < 4; i++){
    p_name = TString(Form("TF_Plots/TF_W0mu_W1mu_cat%d", i+1));
    switch(i){
    case 0:
      l_name = "TF W(0#mu) to W(1#mu) cat(VL)";
      break;
    case 1:
      l_name = "TF W(0#mu) to W(1#mu) cat(L)";
      break;
    case 2:
      l_name = "TF W(0#mu) to W(1#mu) cat(H)";
      break;
    case 3:
      l_name = "TF W(0#mu) to W(1#mu) cat(VH)";
      break;
    default:
      break;
    }
    PlotCosmetics(TF_W_W[i], p_name, l_name);
  }

  //DY(0mu) to DY(2mu)
  for(int i = 0; i < 4; i++){
    p_name = TString(Form("TF_Plots/TF_DY0mu_DY2mu_cat%d", i+1));
    switch(i){
    case 0:
      l_name = "TF Z/#gamma^{*}(0#mu) to Z/#gamma^{*}(2#mu) cat(VL)";
      break;
    case 1:
      l_name = "TF Z/#gamma^{*}(0#mu) to Z/#gamma^{*}(2#mu) cat(L)";
      break;
    case 2:
      l_name = "TF Z/#gamma^{*}(0#mu) to Z/#gamma^{*}(2#mu) cat(H)";
      break;
    case 3:
      l_name = "TF Z/#gamma^{*}(0#mu) to Z/#gamma^{*}(2#mu) cat(VH)";
      break;
    default:
      break;
    }
    PlotCosmetics(TF_DY0mu_DY2mu[i], p_name, l_name);
  }
  
  //W(1mu) to DY(2mu)
  for(int i = 0; i < 4; i++){
    p_name = TString(Form("TF_Plots/TF_W1mu_DY2mu_cat%d", i+1));
    switch(i){
    case 0:
      l_name = "TF W(1#mu) to Z/#gamma^{*}(2#mu) cat(VL)";
      break;
    case 1:
      l_name = "TF W(1#mu) to Z/#gamma^{*}(2#mu) cat(L)";
      break;
    case 2:
      l_name = "TF W(1#mu) to Z/#gamma^{*}(2#mu) cat(H)";
      break;
    case 3:
      l_name = "TF W(1#mu) to Z/#gamma^{*}(2#mu) cat(VH)";
      break;
    default:
      break;
    }
    PlotCosmetics(TF_W_DY[i], p_name, l_name);
  }

  //DY(0mu) to DY(2mu)
  for(int i = 0; i < 4; i++){
    p_name = TString(Form("TF_Plots/TF_DY1mu_DY2mu_cat%d", i+1));
    switch(i){
    case 0:
      l_name = "TF Z/#gamma^{*}(1#mu) to Z/#gamma^{*}(2#mu) cat(VL)";
      break;
    case 1:
      l_name = "TF Z/#gamma^{*}(1#mu) to Z/#gamma^{*}(2#mu) cat(L)";
      break;
    case 2:
      l_name = "TF Z/#gamma^{*}(1#mu) to Z/#gamma^{*}(2#mu) cat(H)";
      break;
    case 3:
      l_name = "TF Z/#gamma^{*}(1#mu) to Z/#gamma^{*}(2#mu) cat(VH)";
      break;
    default:
      break;
    }
    PlotCosmetics(TF_DY1mu_DY2mu[i], p_name, l_name);
  }

  return 0;
  
};


int CreateOneB(){
  //TFile* F = new TFile("/Users/cmorgoth/Software/git/BkgPred-Btag/test_CP_1TB.root");
  TFile* F = new TFile("/Users/cmorgoth/Software/git/BkgPred-Btag/test_CP_1TB_ptReweighting.root");
  
  
  //Bkg Prediction Ratios
  TH1F* TF_TT_TT;
  TH1F* TF_Z_DY;
  TH1F* TF_W_DY;
  TH1F* TF_DY_DY;

  TString name;
  name = "TT_Ratio";
  TF_TT_TT = (TH1F*)F->Get(name);
  name = "Z0mu_2muDYRatio";
  TF_Z_DY = (TH1F*)F->Get(name);
  name = "W0mu_2muDYRatio";
  TF_W_DY = (TH1F*)F->Get(name);
  name = "DY0mu_2muDYRatio";
  TF_DY_DY = (TH1F*)F->Get(name);

  //Add Systematics
  TFile* fsys = new TFile("/Users/cmorgoth/Software/git/BkgPred-Btag/Closure_CP.root");
  TH1F* sys = (TH1F*)fsys->Get("sys");
  
  for(int j = 1; j <= sys->GetNbinsX(); j++){
    double err = sqrt(pow(TF_TT_TT->GetBinContent(j)*sys->GetBinContent(j), 2) 
		      + pow(TF_TT_TT->GetBinError(j), 2));
    TF_TT_TT->SetBinError(j, err);
    
    err = sqrt(pow(TF_Z_DY->GetBinContent(j)*sys->GetBinContent(j), 2) 
	       + pow(TF_Z_DY->GetBinError(j), 2));
    TF_Z_DY->SetBinError(j, err);
    
    err = sqrt(pow(TF_W_DY->GetBinContent(j)*sys->GetBinContent(j), 2) 
	       + pow(TF_W_DY->GetBinError(j), 2));
    TF_W_DY->SetBinError(j, err);

    err = sqrt(pow(TF_DY_DY->GetBinContent(j)*sys->GetBinContent(j), 2) 
	       + pow(TF_DY_DY->GetBinError(j), 2));
    TF_DY_DY->SetBinError(j, err);
  }
  TString p_name, l_name;
  TString app = "_reweighted";
  //TT(0mu) to TT(2mu)
  p_name = "TF_Plots/TF_tt0mub_tt2mubb";
  l_name = "TF t#bar{t}(0#mub) to t#bar{t}(2#mubb)";
  PlotCosmetics(TF_TT_TT, p_name+app, l_name);
  
  //Z(0mu) to DY(2mu)
  p_name = "TF_Plots/TF_Z0mub_DY2mubb";
  l_name = "TF Z(0#mub) to Z/#gamma^{*}(2#mubb-Z/#gamma^{*})";
  PlotCosmetics(TF_Z_DY, p_name+app, l_name);

  //W(0mu) to DY(2mu)
  p_name = "TF_Plots/TF_W0mub_DY2mubb";
  l_name = "TF W(0#mub) to Z/#gamma^{*}(2#mubb-Z/#gamma^{*})";
  PlotCosmetics(TF_W_DY, p_name+app, l_name);

  //DY(0mu) to DY(2mu)
  p_name = "TF_Plots/TF_DY0mub_DY2mubb";
  l_name = "TF Z/#gamma^{*}(0#mub) to Z/#gamma^{*}(2#mubb-Z/#gamma^{*})";
  PlotCosmetics(TF_DY_DY, p_name+app, l_name);
  
  return 0;
  
};

int CreateTwoB(){
  //TFile* F = new TFile("/Users/cmorgoth/Software/git/BkgPred-Btag/test_CP_2TB.root");
  TFile* F = new TFile("/Users/cmorgoth/Software/git/BkgPred-Btag/test_CP_2TB_ptReweighting.root");
  //Bkg Prediction Ratios
  TH1F* TF_TT_TT;
  TH1F* TF_Z_DY;
  TH1F* TF_W_DY;
  TH1F* TF_DY_DY;

  TString name;
  name = "TT_Ratio";
  TF_TT_TT = (TH1F*)F->Get(name);
  name = "Z0mu_2muDYRatio";
  TF_Z_DY = (TH1F*)F->Get(name);
  name = "W0mu_2muDYRatio";
  TF_W_DY = (TH1F*)F->Get(name);
  name = "DY0mu_2muDYRatio";
  TF_DY_DY = (TH1F*)F->Get(name);

  //Add Systematics
  TFile* fsys = new TFile("/Users/cmorgoth/Software/git/BkgPred-Btag/Closure_CP.root");
  TH1F* sys = (TH1F*)fsys->Get("sys");
  
  for(int j = 1; j <= sys->GetNbinsX(); j++){
    double err = sqrt(pow(TF_TT_TT->GetBinContent(j)*sys->GetBinContent(j), 2) 
		      + pow(TF_TT_TT->GetBinError(j), 2));
    TF_TT_TT->SetBinError(j, err);
    
    err = sqrt(pow(TF_Z_DY->GetBinContent(j)*sys->GetBinContent(j), 2) 
	       + pow(TF_Z_DY->GetBinError(j), 2));
    TF_Z_DY->SetBinError(j, err);
    
    err = sqrt(pow(TF_W_DY->GetBinContent(j)*sys->GetBinContent(j), 2) 
	       + pow(TF_W_DY->GetBinError(j), 2));
    TF_W_DY->SetBinError(j, err);

    err = sqrt(pow(TF_DY_DY->GetBinContent(j)*sys->GetBinContent(j), 2) 
	       + pow(TF_DY_DY->GetBinError(j), 2));
    TF_DY_DY->SetBinError(j, err);
  }
  
  TString p_name, l_name;
  TString app = "_reweighted";
  //TT(0mu) to TT(2mu)
  p_name = "TF_Plots/TF_tt0mubb_tt2mubb";
  l_name = "TF t#bar{t}(0#mubb) to t#bar{t}(2#mubb)";
  PlotCosmetics(TF_TT_TT, p_name+app, l_name);
  
  //Z(0mu) to DY(2mu)
  p_name = "TF_Plots/TF_Z0mubb_DY2mubb";
  l_name = "TF Z(0#mubb) to Z/#gamma^{*}(2#mubb-Z/#gamma^{*})";
  PlotCosmetics(TF_Z_DY, p_name+app, l_name);

  //W(0mu) to DY(2mu)
  p_name = "TF_Plots/TF_W0mubb_DY2mubb";
  l_name = "TF W(0#mubb) to Z/#gamma^{*}(2#mubb-Z/#gamma^{*})";
  PlotCosmetics(TF_W_DY, p_name+app, l_name);

  //DY(0mu) to DY(2mu)
  p_name = "TF_Plots/TF_DY0mubb_DY2mubb";
  l_name = "TF Z/#gamma^{*}(0#mubb) to Z/#gamma^{*}(2#mubb-Z/#gamma^{*})";
  PlotCosmetics(TF_DY_DY, p_name+app, l_name);
  
  return 0;
};

bool PlotCosmetics(TH1F* h, TString name, TString lname){
  TLegend* leg = new TLegend(0.2, 0.8, 0.88, 0.88);//(xmin, ymin, xmax, ymax)
  leg->AddEntry(h, lname,"f");
  leg->SetHeader("");
  leg->SetTextSize(.042);
  leg->SetFillColor(0);
  leg->SetLineColor(0);
  
  TCanvas* C = new TCanvas("c","c", 640, 640);
  C->cd();
  
  h->SetStats(0);
  h->SetTitle("");
  h->SetXTitle("R^{2}");
  h->GetXaxis()->CenterTitle(1);
  h->SetMarkerColor(kBlue);
  h->SetMarkerSize(1.2);
  //h->SetMarkerStyle(20);
  h->SetFillColor(kBlue-10);
  h->SetLineColor(kBlue);
  h->SetLineWidth(2);
  h->SetMaximum(3.0*h->GetMaximum());
  h->SetMinimum(0.33*h->GetMinimum());
  
  h->DrawCopy("LE2");
  h->SetFillColor(0);
  h->DrawCopy("samehist][");
  leg->Draw();
  
  TLatex *t = new TLatex();
  t->SetNDC();
  t->SetTextAlign(22);
  t->SetTextSize(0.03);
  t->DrawLatex(0.22,0.95,"CMS Preliminary:");
  t->DrawLatex(0.42,0.95,"#sqrt{s} = 8 TeV,");
  t->DrawLatex(0.62,0.95,"#int L dt = 18.84 fb^{-1}");
  
  C->SaveAs(name+".pdf");
  C->SaveAs(name+".png");
  C->SaveAs(name+".C");
  delete C;
  return 0;
};
