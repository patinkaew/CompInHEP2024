#include "TFile.h"
#include "TTree.h"
#include "TRandom3.h"

int main(){
    size_t N = 1000;
    UInt_t seed = 5679;
    TRandom3 *generator = new TRandom3(seed);

    TFile *f = TFile::Open("out.root", "RECREATE");
    f -> cd();

    TTree * t = new TTree("tree", "title");
    Double_t s;
    t -> Branch("normal", &s, "normal/D");

    for(size_t i = 0; i < N; i++){
        s = generator -> Gaus();
        t -> Fill();
    }

    t -> Write();
    f -> Close();

    return 0;
}