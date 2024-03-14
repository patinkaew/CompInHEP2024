#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"
#include "TF1.h"
#include "TCanvas.h"

int main(){
    TFile *in_file = TFile::Open("out.root", "READ");
    TTree* t = (TTree*)in_file->Get("tree");

    Double_t s;
    t -> SetBranchAddress("normal",&s);

    TH1D* h= new TH1D("histo","", 50, -5, 5);

    for(size_t i=0; i < t -> GetEntries(); i++){
        t -> GetEntry(i);
        h -> Fill(s);
    }

    TF1 *fn = new TF1("fn", "gaus", -5, 5);
    h -> Fit("fn");

    h -> SetFillColor(kYellow);
    h -> SetLineWidth(3);

    fn -> SetLineColor(kBlack);
    fn -> SetLineWidth(3);

    h -> GetXaxis() -> SetTitle("Random number");
    h -> GetYaxis() -> SetTitle("Number of events");
    
    TCanvas* canvas = new TCanvas("fit","",500,500);
    canvas->cd();

    h -> Draw();
    fn -> Draw("SAME");

    canvas -> Print("plot.pdf");

    TFile *out_file = TFile::Open("histo.root", "RECREATE");
    out_file -> cd();
    h -> Write();
    out_file -> Close();
    in_file -> Close();

    return 0;
}