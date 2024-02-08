#pragma once
#ifndef Measure2_H
#define Measure2_H

#include<vector>

template <typename T>
class Measure2{
    public: 
        // constructor
        Measure2(T x, T y, std::vector<T> m) : x(x), y(y), m(m) {}
        Measure2(T x, T y, T x_var, T y_var, T cov) : x(x), y(y){
            m.push_back(x_var);
            m.push_back(cov);
            m.push_back(y_var);
        }

        T get_x() const {return x;}
        T get_y() const {return y;}
        std::vector<T> get_m() const {return m;}
        T get_x_var() const {return m[0];}
        T get_y_var() const {return m[2];}
        T get_cov() const {return m[1];}

        T get_r();
        T get_r_error();
        T get_r_significance();

    private:
        T x, y;
        // since error is a symmetric matric, we can represent it with vector of 3 elements: [x_var, cov, y_var] 
        std::vector<T> m; 

};

typedef Measure2<float> Measure2F;
typedef Measure2<double> Measure2D;

#endif //Measure2_H