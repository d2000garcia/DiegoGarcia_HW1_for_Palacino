int PlottingMacro(){

  // Opening files to read
  TFile *f750 = TFile::Open("hist-ZPrime750.root","READ");
  TFile *f2500 = TFile::Open("hist-ZPrime2500.root","READ");
  TFile *f_ttbar = TFile::Open("hist-ttbar_lep.root","READ");
  
  //Making root file to strore
  TFile file3 ("HW1_Diego_Garcia.root", "RECREATE");
  file3.mkdir("Problem1");
  file3.mkdir("Problem2");

  ///////////////////////////////////////////////////////
  //                    Problem 1                      //
  ///////////////////////////////////////////////////////
  //      Section for plotting the lepton pT           //
  ///////////////////////////////////////////////////////
  file3.cd("/");
  file3.cd("/Problem1");

  TH1F *h_ZP750_lep_pt = (TH1F*) f750->Get("h_lep_pt");

  TH1F *h_ZP2500_lep_pt = (TH1F*) f2500->Get("h_lep_pt");

  h_ZP750_lep_pt->Scale(1./h_ZP750_lep_pt->Integral());
  h_ZP2500_lep_pt->Scale(1./h_ZP2500_lep_pt->Integral());

  h_ZP2500_lep_pt->SetLineColor(kRed);

  TCanvas *c_pt1 = new TCanvas("c_pt1");
  c_pt1->cd();
  h_ZP750_lep_pt->Draw();
  h_ZP2500_lep_pt->Draw("same");

  TLegend *leg = new TLegend(0.2,0.6,0.48,0.8);
  leg->SetFillColor(kWhite);
  leg->SetHeader("Problem1_leptons_pT","C");
  leg->AddEntry(h_ZP750_lep_pt,"750 GeV Leptons","l");
  leg->AddEntry(h_ZP2500_lep_pt,"2500 GeV leptons","l");
  leg->Draw("same");

  c_pt1->Write();
  h_ZP750_lep_pt->Write();
  h_ZP2500_lep_pt->Write();  

  ///////////////////////////////////////////////////////
  //      Section for plotting the lepton eta          //
  ///////////////////////////////////////////////////////
  
  TH1F *h_ZP750_lep_eta = (TH1F*) f750->Get("h_lep_eta");

  TH1F *h_ZP2500_lep_eta = (TH1F*) f2500->Get("h_lep_eta");

  h_ZP750_lep_eta->Scale(1./h_ZP750_lep_eta->Integral());
  h_ZP2500_lep_eta->Scale(1./h_ZP2500_lep_eta->Integral());

  h_ZP2500_lep_eta->SetLineColor(kRed);

  TCanvas *c_eta = new TCanvas("c_eta");
  c_eta->cd();
  h_ZP750_lep_eta->Draw();
  h_ZP2500_lep_eta->Draw("same");

  TLegend *leg1 = new TLegend(0.2,0.6,0.48,0.8);
  leg1->SetFillColor(kWhite);
  leg1->SetHeader("Problem1_leptons_eta","C");
  leg1->AddEntry(h_ZP750_lep_eta,"750 GeV Leptons","l");
  leg1->AddEntry(h_ZP2500_lep_eta,"2500 GeV leptons","l");
  leg1->Draw("same");

  c_eta->Write();
  h_ZP750_lep_eta->Write();
  h_ZP2500_lep_eta->Write();    

  ///////////////////////////////////////////////////////
  //      Section for plotting the lepton phi          //
  ///////////////////////////////////////////////////////
  
  TH1F *h_ZP750_lep_phi = (TH1F*) f750->Get("h_lep_phi");

  TH1F *h_ZP2500_lep_phi = (TH1F*) f2500->Get("h_lep_phi");

  h_ZP750_lep_phi->Scale(1./h_ZP750_lep_phi->Integral());
  h_ZP2500_lep_phi->Scale(1./h_ZP2500_lep_phi->Integral());

  h_ZP2500_lep_phi->SetLineColor(kRed);

  TCanvas *c_phi = new TCanvas("c_phi");
  c_phi->cd();
  h_ZP750_lep_phi->Draw();
  h_ZP2500_lep_phi->Draw("same");

  TLegend *leg2 = new TLegend(0.2,0.6,0.48,0.8);
  leg2->SetFillColor(kWhite);
  leg2->SetHeader("Problem1_leptons_phi","C");
  leg2->AddEntry(h_ZP750_lep_phi,"750 GeV Leptons","l");
  leg2->AddEntry(h_ZP2500_lep_phi,"2500 GeV leptons","l");
  leg2->Draw("same");

  c_phi->Write();
  h_ZP750_lep_phi->Write();
  h_ZP2500_lep_phi->Write();    

  ///////////////////////////////////////////////////////
  //                  Problem 2                        //
  ///////////////////////////////////////////////////////
  //      Section for plotting the electron pT         //
  ///////////////////////////////////////////////////////

  file3.cd("/Problem2");
  
  TH1F *h_ZP750_el_pt = (TH1F*) f750->Get("h_el_pt");

  TH1F *h_ZP2500_el_pt = (TH1F*) f2500->Get("h_el_pt");

  TH1F *h_ttbar_el_pt = (TH1F*) f_ttbar->Get("h_el_pt");

  h_ZP2500_el_pt->SetLineColor(kRed);
  h_ttbar_el_pt->SetLineColor(kGreen);
  
  TCanvas *c_pt2 = new TCanvas("c_pt2");
  c_pt2->cd();
  h_ZP750_el_pt->Draw();
  h_ZP2500_el_pt->Draw("same");
  h_ttbar_el_pt->Draw("same");

  TLegend *leg3 = new TLegend(0.2,0.6,0.48,0.8);
  leg3->SetFillColor(kWhite);
  leg3->SetHeader("Problem2_electron_pT","C");
  leg3->AddEntry(h_ZP750_el_pt,"750 GeV electrons","l");
  leg3->AddEntry(h_ZP2500_el_pt,"2500 GeV electrons","l");
  leg3->AddEntry(h_ttbar_el_pt,"ttbar electrons","l");  
  leg3->Draw("same");

  c_pt2->Write();
  h_ZP750_el_pt->Write();
  h_ZP2500_el_pt->Write();
  h_ttbar_el_pt->Write();

  ///////////////////////////////////////////////////////
  //      Section for plotting the electron pT         //
  ///////////////////////////////////////////////////////
  
  TH1F *h_ZP750_mu_pt = (TH1F*) f750->Get("h_mu_pt");

  TH1F *h_ZP2500_mu_pt = (TH1F*) f2500->Get("h_mu_pt");

  TH1F *h_ttbar_mu_pt = (TH1F*) f_ttbar->Get("h_mu_pt");

  h_ZP2500_mu_pt->SetLineColor(kRed);
  h_ttbar_mu_pt->SetLineColor(kGreen);
  
  TCanvas *c_pt3 = new TCanvas("c_pt3");
  c_pt3->cd();
  h_ZP750_mu_pt->Draw();
  h_ZP2500_mu_pt->Draw("same");
  h_ttbar_mu_pt->Draw("same");

  TLegend *leg4 = new TLegend(0.2,0.6,0.48,0.8);
  leg4->SetFillColor(kWhite);
  leg4->SetHeader("Problem2_muon_pT","C");
  leg4->AddEntry(h_ZP750_mu_pt,"750 GeV muons","l");
  leg4->AddEntry(h_ZP2500_mu_pt,"2500 GeV muons","l");
  leg4->AddEntry(h_ttbar_mu_pt,"ttbar muons","l");  
  leg4->Draw("same");

  c_pt3->Write();
  h_ZP750_mu_pt->Write();
  h_ZP2500_mu_pt->Write();
  h_ttbar_mu_pt->Write();
  
  return 0;
}
