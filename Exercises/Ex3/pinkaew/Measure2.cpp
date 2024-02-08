#include "Measure2.h"
#include<cmath>

template <typename T>
T Measure2<T>::get_r(){
    return std::sqrt(x*x + y*y);
}

template <typename T>
T Measure2<T>::get_r_error(){
    T r = get_r();
    T dr_dx =  x / r;
    T dr_dy = y / r;
    return std::sqrt((dr_dx * dr_dx * m[0]) + (dr_dy * dr_dy * m[2]) + (2*dr_dx * dr_dy * m[1]));
}

template <typename T>
T Measure2<T>::get_r_significance(){
    return get_r_error()/get_r();
}