//  
//  main.cpp
//  
//  数値解析特論
//  課題6-1
//  
//  Version: 0.0
//  Created by Franz Chuquirachi (@franzcrs) on 2022/05/31
//  Copyright © 2022. All rights reserved.
//  

#include "auto_diff.h"

double f(double x){
    // f(x) = x^3 - 2x^2 + 4x + 1
    return x*x*x - 2*x*x + 4*x + 1;
}
double df(double x){
    // df = 3x^2 - 4x + 4
    return 3*x*x - 4*x + 4;
}

double g(double x){
    // g(x) = sin^2(x) + log(x)
    return sin(x)*sin(x) + log(x);
}
double dg(double x){
    // dg = 2sin(x)cos(x) + 1/x
    return 2*sin(x)*cos(x) + (1/x);
}

int main() {
    double x = 2;
    auto_diff a = auto_diff(f(x), df(x));
    auto_diff b = auto_diff(g(x), dg(x));
    printf("Value of function f and f' when x = %.0f\n", x);
    a.print();
    printf("(in autodiff format)\n\n");
    printf("Value of function g and g' when x = %.0f\n", x);
    b.print();
    printf("(in autodiff format)\n\n");
    return 0;
}
