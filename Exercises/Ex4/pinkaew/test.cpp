#include<iostream>
#include "Track.h"

using namespace std;
int main(){

    typedef Track<double> TrackD;
    typedef SimTrack<double> SimTrackD;
    
    cout << "Testing Track" << endl;
    TrackD track (100., 10., 20., 30.);
    cout << "get_E expected: " << 100 << " receive: " << track.get_E() << endl;
    cout << "get_px expected: " << 10 << " receive: " << track.get_px() << endl;
    cout << "get_py expected: " << 20 << " receive: " << track.get_py() << endl;
    cout << "get_pz expected: " << 30 << " receive: " << track.get_pz() << endl;
    cout << "get_p expected: " << 37.41657 << " receive: " << track.get_p() << endl;
    cout << "get_pT expected: " << 22.36068 << " receive: " << track.get_pT() << endl;
    cout << "get_theta expected: " << 0.64052 << " receive: " << track.get_theta() << endl;
    cout << "get_eta expected: " << 1.103587 << " receive: " << track.get_eta() << endl;
    cout << "get_phi expected: " << 1.107149 << " receive: " << track.get_phi() << endl;

    cout << endl;
    cout << "Testing SimTrack" << endl;
    SimTrackD sim_track (100., 10., 20., 30., 4, 5);
    cout << "get_E expected: " << 100 << " receive: " << sim_track.get_E() << endl;
    cout << "get_px expected: " << 10 << " receive: " << sim_track.get_px() << endl;
    cout << "get_py expected: " << 20 << " receive: " << sim_track.get_py() << endl;
    cout << "get_pz expected: " << 30 << " receive: " << sim_track.get_pz() << endl;
    cout << "get_p expected: " << 37.41657 << " receive: " << sim_track.get_p() << endl;
    cout << "get_pT expected: " << 22.36068 << " receive: " << sim_track.get_pT() << endl;
    cout << "get_theta expected: " << 0.64052 << " receive: " << sim_track.get_theta() << endl;
    cout << "get_eta expected: " << 1.103587 << " receive: " << sim_track.get_eta() << endl;
    cout << "get_phi expected: " << 1.107149 << " receive: " << sim_track.get_phi() << endl;
    cout << "get_id expected: " << 4 << " receive: " << sim_track.get_id() << endl;
    cout << "get_parent_id expected: " << 5 << " receive: " << sim_track.get_parent_id() << endl;

    return 0;
}