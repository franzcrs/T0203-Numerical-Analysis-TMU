//  
//  main.cpp
//  
//  数値解析特論
//  課題6-2
//  
//  Version: 0.0
//  Created by Franz Chuquirachi (@franzcrs) on 2022/05/31
//  Copyright © 2022. All rights reserved.
//  

#include <math.h>
#include <stdio.h>

/**
 @brief Function that find the root of a non-linear equation defined as h(x) = -x^3 + 4x^2 + 5sin^3(3x) - 4. Program exits when either of tolerance or max iterations are surpassed, whatever happens first.
 @param init_value initial guess of the x for which f(x) is 0
 @param delta tolerance for convergence. Its an small relative difference between consequent results of x that defines the convergence moment.
 @param max_iterations numbers of iterations for which the program stops. Safety measure to stop the iterations in case there is no convergence after some time. In case program doesn't converge try another initial value.
 */
void first_order_newton_method(double init_value, double delta, int max_iterations){
    printf("---- Beginning of First Order Newton Method ----\n\n");
    double x = init_value;
    double x_prev = 0;
    char i = 0;
    for (i = 0; i < max_iterations; i++){
        x_prev = x;
        // X update: x = x - (h(x)/h'(x))
        x = x - (-x*x*x + 4*x*x + 5*sin(3*x)*sin(3*x)*sin(3*x) - 4) / (-3*x*x + 8*x+ 15*sin(3*x)*sin(3*x)*cos(3*x)*3);
        // Convergence method: |x - x_prev|/|x_prev|
        if (fabs(x - x_prev) / fabs(x_prev) < delta){
            printf("Root value converged!\n");
            printf("＞ x = %.3f\n\n", x);
            break;
        }
    }
    if (i == max_iterations){
        printf("Root value could not converge in the defined number of iterations\n\n");
    }
    printf("---- End of First Order Newton Method ----\n\n");
}

int main() {
    first_order_newton_method(5, 0.0001, 45);
    return 0;
}
