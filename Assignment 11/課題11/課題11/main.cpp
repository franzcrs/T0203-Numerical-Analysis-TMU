//  
//  main.cpp
//  
//  数値解析特論
//  課題11
//  
//  Version: 0.0
//  Created by Franz Chuquirachi (@franzcrs) on 2022/07/04
//  Copyright © 2022. All rights reserved.
//  

#include <math.h>
#include <stdio.h>

/**
 @brief Derivative of the unkown function y: y' = dy/dt = 2/sqrt(5-4*sin(3*y))
 */
double f(double t, double y){
    return 2/sqrt(5 - 4*sin(3*y));
}

double runge_kutta(double t_eval, double initial_t, double initial_y, double step_h){
    printf("---- Beginning of Runge-Kutta Method ----\n\n");
    double y_i_1 = initial_y;
    for (double t_i = initial_t; t_i <= t_eval; t_i+=step_h){
        double k1 = f(t_i, y_i_1);
        double k2 = f(t_i+step_h/2, y_i_1+step_h*k1/2);
        double k3 = f(t_i+step_h/2, y_i_1+step_h*k2/2);
        double k4 = f(t_i+step_h, y_i_1+step_h*k3);
        y_i_1 += (step_h/6)*( k1 + 2*k2 + 2*k3 + k4 );
    }
    printf("---- End of Runge-Kutta Method ----\n\n");
    return y_i_1;
}

int main() {
    double t_0 = 0;
    double y_0 = 1;
    double t_to_eval = 3;
    double h = 0.01;
    printf("\nSolving y for t = %.2f\n\n", t_to_eval);
    double y = runge_kutta(t_to_eval, t_0, y_0, h);
    printf("Solved y(%.2f)\n", t_to_eval);
    printf("＞Result: %.4f\n\n", y);
    return 0;
}
