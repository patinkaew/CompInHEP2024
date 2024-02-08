#include"Measure2.h"
#include"Measure2.cpp"
#include<vector>
#include<iostream>

int main(){
    double x =1.1;
    double y = 2.2;
    double x_var = 0.1;
    double y_var = 0.2;
    double cov = 0.05;
    std::vector<double> m = {x_var, cov, y_var};
    
    Measure2D measure1(x, y, m);

    std::cout << "Testing initializing with std::vector" << std::endl;
    std::cout << "get_x expect: " << x << " receive: "<< measure1.get_x() << std::endl;
    std::cout << "get_y expect: " << y << " receive: "<< measure1.get_y() << std::endl;
    std::cout << "get_m expect: [ ";
    for (auto & i : m){
        std::cout<< i << " ";
    }
    std::cout << "] receive: [ ";
    for (auto & i : m){
        std::cout<< i << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "get_x_var expect: " << x_var << " receive: " << measure1.get_x_var() << std::endl;
    std::cout << "get_y_var expect: " << y_var << " receive: " << measure1.get_y_var() << std::endl;
    std::cout << "get_cov expect: " << cov << " receive: " << measure1.get_cov() << std::endl;

    std::cout << "get_r expect: " << 2.45967 << " receive: " << measure1.get_r() << std::endl;
    std::cout << "get_r_error expect: " << 0.469042 << " receive: " << measure1.get_r_error() << std::endl;
    std::cout << "get_r_significance expect: " << 0.190693 << " receive: " << measure1.get_r_significance() << std::endl << std::endl;

    
    Measure2D measure2(x, y, x_var, y_var, cov);

    std::cout << "Testing initializing with separate var and cov" << std::endl;
    std::cout << "get_x expect: " << x << " receive: "<< measure2.get_x() << std::endl;
    std::cout << "get_y expect: " << y << " receive: "<< measure2.get_y() << std::endl;
    std::cout << "get_m expect: [ ";
    for (auto & i : m){
        std::cout<< i << " ";
    }
    std::cout << "] receive: [ ";
    for (auto & i : m){
        std::cout<< i << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "get_x_var expect: " << x_var << " receive: " << measure2.get_x_var() << std::endl;
    std::cout << "get_y_var expect: " << y_var << " receive: " << measure2.get_y_var() << std::endl;
    std::cout << "get_cov expect: " << cov << " receive: " << measure2.get_cov() << std::endl;

    std::cout << "get_r expect: " << 2.45967 << " receive: " << measure2.get_r() << std::endl;
    std::cout << "get_r_error expect: " << 0.469042 << " receive: " << measure2.get_r_error() << std::endl;
    std::cout << "get_r_significance expect: " << 0.190693 << " receive: " << measure2.get_r_significance() << std::endl;


    return 0;
}