import ROOT

ROOT.gROOT.SetBatch(True)

fname = "DYJetsToLL.root"
df = ROOT.RDataFrame("Events", fname)
hPileup = df.Filter("HLT_IsoMu24").Histo1D(("h_pileup", ";pileup;events", 25, 0, 50), "PV_npvs")

c1 = ROOT.TCanvas("c1", "DY Analysis", 10, 10, 800, 600)
hPileup.Draw()
c1.Update()

c1.SaveAs("pileup_rdf.pdf")
c1.SaveAs("pileup_rdf.png")
