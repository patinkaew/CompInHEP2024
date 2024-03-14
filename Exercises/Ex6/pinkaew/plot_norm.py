#!/usr/bin/env python

import ROOT

if __name__ == "__main__":
    in_file = ROOT.TFile.Open("out_py.root", "READ")
    t = in_file.Get("tree")

    h= ROOT.TH1D("histo","", 50, -5, 5)

    for s in t:  
        h.Fill(s.normal)

    fn = ROOT.TF1("fn", "gaus", -5, 5)
    h.Fit("fn")

    h.SetFillColor(ROOT.kYellow)
    h.SetLineWidth(3)

    fn.SetLineColor(ROOT.kBlack)
    fn.SetLineWidth(3)

    h.GetXaxis().SetTitle("Random number")
    h.GetYaxis().SetTitle("Number of events")
    
    canvas = ROOT.TCanvas("fit","",500,500)

    h.Draw()
    fn.Draw("SAME")

    canvas.Print("plot_py.pdf")

    out_file = ROOT.TFile.Open("histo_py.root", "RECREATE")

    out_file.WriteObject(h, "histo")
    out_file.Close()
    in_file.Close()