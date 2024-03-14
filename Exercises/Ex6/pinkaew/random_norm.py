#!/usr/bin/env python

import ROOT
from array import array

if __name__ == "__main__":
    N = 1000
    seed = 5679
    generator = ROOT.TRandom3(seed)

    f= ROOT.TFile.Open("out_py.root", "RECREATE")

    t = ROOT.TTree("tree", "title")
    s = array('d', [0])
    t.Branch("normal", s, "normal/D")

    for _ in range(N):
        s[0] = generator.Gaus()
        t.Fill()

    f.WriteObject(t, "tree")
    f.Close()