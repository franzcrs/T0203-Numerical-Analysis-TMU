//  
//  main.cpp
//  
//  数値解析特論
//  課題3-2
//  
//  Version: 0.0
//  Created by Franz Chuquirachi (@franzcrs) on 2022/05/09
//  Copyright © 2022. All rights reserved.
//  

#include <iostream>
#include "complex.h"

void print_augm_matrix(double a[5][5], Complex b[5][1], int cols, int rows){
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            printf("%.0f ", a[i][j]);
        }
        printf("| ");
        b[i][0].print(0);
    }
    printf("(aprox. integer)\n");
}

void pivoting(double a[5][5], Complex b[5][1], int cols, int rows, char current_col){
    double max = 0;
    char pivot_row = 0;
    
    // Finding pivot row
    printf("\nFinding pivot in column number %d:\n", current_col+1);
    for(char i = current_col; i<rows; i++){
        if (i==current_col){
            max = a[i][current_col];
            pivot_row = i;
        }
        else{
            if (a[i][current_col]>max){
                max = a[i][current_col];
                pivot_row = i;
            }
        }
    }
    
    if (pivot_row != 0){
        printf("＞Pivot row in column %d: %d\n", current_col+1, pivot_row+1);
    }
    else {
        printf("＞The top most row has already the highest value\n");
    }
    
    // Exchanging rows
    printf("\nExchanging rows:\n");
    if (pivot_row == 0) {
        printf("＞No exchange occured since the found pivot row is the first\n");
    }
    else {
        for (char j=0; j<cols; j++){
            double temp_a = a[current_col][j];
            a[current_col][j] = a[pivot_row][j];
            a[pivot_row][j] = temp_a;
        }
        Complex temp_b = b[current_col][0];
        b[current_col][0] = b[pivot_row][0];
        b[pivot_row][0] = temp_b;
        printf("＞Rows exhanged\n");
    }
    
    printf("\nInspecting matrices\n");
    print_augm_matrix(a, b, cols, rows);
    printf("\n************************\n");
}

void forward_elimination(double a[5][5], Complex b[5][1], int cols, int rows, char current_col) {
    printf("\nForward elimination began\n");
    for (char i=current_col+1; i<rows; i++){
        if (a[i][current_col] != 0){
            double factor = (-1)*a[i][current_col]/a[current_col][current_col];
            for (char j=0; j<cols; j++){
                a[i][j] = factor * a[current_col][j] + a[i][j];
            }
            b[i][0] = factor * b[current_col][0] + b[i][0];
        }
    }
    printf("\nInspecting matrices\n");
    print_augm_matrix(a, b, cols, rows);
    printf("\n************************\n");
}

void gaussian_elimination(double a[5][5], Complex b[5][1], int cols, int rows, Complex x[5][1]) {
    printf("---- Beginning of Gaussian elimination ----\n");
    for (char col = 0; col<cols-1; col++){
        pivoting(a, b, cols, rows, col);
        forward_elimination(a, b, cols, rows, col);
    }
    printf("\nSolving the System of linear equations:\n");
    for (int i=rows-1; i>=0; i--){
        x[i][0] = b[i][0];
        for (int j=cols-1; j>i; j--){
            x[i][0] = x[i][0] - a[i][j]*x[j][0];
        }
        x[i][0] = x[i][0]/a[i][i];
    }
    printf("\nSolution vector:\n＞ ");
    for (int i=0; i<cols; i++){
        x[i][0].print(2);
    }
    printf("\n\n---- End of Gaussian elimination ----\n\n");
}

int main() {
    double a[5][5] = {
        1, 0, 3,-1,0,
        0,-3,-1, 1,6,
        2, 5, 0, 0,5,
        3, 1,-2, 2,0,
        2,-5, 1, 3,3 }; //GIVEN INFORMATION
    Complex b[5][1] = {
        Complex(1,-2),
        Complex(-1),
        Complex(-3, 1),
        Complex(5),
        Complex(2) }; //GIVEN INFORMATION
    int columns = 5;
    int rows = 5;
    Complex x[5][1] = {Complex()}; // SOLUTION VECTOR
    
    printf("\nAugmented Matrix of the System of linear eq:\n\n");
    print_augm_matrix(a, b, columns, rows);
    printf("\n************************\n");
    
    gaussian_elimination(a, b, columns, rows, x);
    return 0;
}
