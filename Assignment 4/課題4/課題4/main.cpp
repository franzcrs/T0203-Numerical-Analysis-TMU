//  
//  main.cpp
//  
//  数値解析特論
//  課題4
//  
//  Version: 0.0
//  Created by Franz Chuquirachi (@franzcrs) on 2022/05/16
//  Copyright © 2022. All rights reserved.
//  

#include <iostream>

void print_augm_matrix(double a[5][5], double b[5][1], int cols, int rows){
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            printf("%.0f ", a[i][j]);
        }
        printf("| %.0f\n", b[i][0]);
    }
    printf("(aprox. integer)\n");
}

void successive_over_relaxation(double a[5][5], double b[5][1], int cols, int rows, double w, double x[5][1], double xi[5][1]){
    printf("\n---- Beginning of SOR method ----\n");
    printf("\nVisualization of Solution vector:\n\n");
    do {
        for (char i = 0; i<rows; i++) {
            x[i][0] = x[i][0] + w * (xi[i][0] - x[i][0]);
            printf("%.5f ", x[i][0]);
            xi[i][0] = x[i][0];
        }
        printf("\n");
        for (char i = 0; i<rows; i++) {
            xi[i][0] = b[i][0];
            for (char j = 0; j<cols; j++) {
                if (j != i) {
                    xi[i][0] = xi[i][0] - a[i][j] * xi[j][0];
                }
            }
            xi[i][0] = xi[i][0]/a[i][i];
        }
    } while ((abs(xi[0][0]-x[0][0]) > 0) &&
             (abs(xi[1][0]-x[1][0]) > 0) &&
             (abs(xi[2][0]-x[2][0]) > 0) &&
             (abs(xi[3][0]-x[3][0]) > 0) &&
             (abs(xi[4][0]-x[4][0]) > 0));
    printf("＞ Solution vector converged!");
    printf("\n\n---- End of SOR method ----\n\n");
    printf("\nSolution vector:\n＞ ");
    for (char i = 0; i<rows; i++) {
        printf("%.5f ", x[i][0]);
    }
    printf("\n\n");
    
}

int main() {
    
    double a[5][5] = {
        5, 0, 3,-1,0,
        0,-8,-1, 1,6,
        2, 5, 9, 0,5,
        3, 1,-2, 7,0,
        2,-5, 1, 3,9 }; //GIVEN INFORMATION
    double b[5][1] = {
         1,
        -1,
        -3,
         5,
         2 }; //GIVEN INFORMATION
    int columns = 5;
    int rows = 5;
    double w = 1.2; // SOR METHOD CONVERGENCE RATE
    double x[5][1] = {1,1,1,1,1}; // SOLUTION VECTOR
    double xi[5][1] = {1,1,1,1,1}; // APPROXIMATED SOLUTION
    printf("\nAugmented Matrix of the System of linear eq:\n\n");
    print_augm_matrix(a, b, columns, rows);
    printf("\n************************\n");
    successive_over_relaxation(a, b, columns, rows, w, x, xi);
    return 0;
}
