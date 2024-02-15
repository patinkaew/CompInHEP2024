#ifndef Track_H
#define Track_H

#include<cmath>

template<typename T>
class Track{
    public:
        Track(T E, T px, T py, T pz):E(E), px(px), py(py), pz(pz){};

        T get_E(){return E;}
        T get_px(){return px;}
        T get_py(){return py;}
        T get_pz(){return pz;}

        T get_p(){return std::sqrt(px*px + py*py + pz*pz);}
        T get_pT(){return std::sqrt(px*px + py*py);}
        T get_theta(){return std::acos(pz / get_p());}
        T get_eta(){return -std::log(std::tan(get_theta()*0.5));}
        T get_phi(){return std::atan2(py, px);}
        
    private:
        T E, px, py, pz; 
};

template<typename T>
class SimTrack: public Track<T>{
    public: 
        SimTrack(T E, T px, T py, T pz, int id, int parent_id)
            :Track<T>(E, px, py, pz), id(id), parent_id(parent_id)
            {}
        
        int get_id(){return id;}
        int get_parent_id(){return parent_id;}

    private:
        int id, parent_id;
};

#endif