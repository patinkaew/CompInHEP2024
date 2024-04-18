void run_analysis(){
   TFile *input_file = TFile::Open("DYJetsToLL.root");
   TTree *input_tree = (TTree*) input_file->Get("Events");
   input_tree->Process("DYanalysis.C");
   exit(0);
}
