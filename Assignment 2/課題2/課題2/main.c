//  
//  main.c
//  
//  数値解析特論
//  課題２
//  
//  Version: 0.1
//  Created by Franz Chuquirachi (@franzcrs) on 2022/05/02
//  Copyright © 2022. All rights reserved.
//  

#include <stdio.h>
//#include <string.h>

void print_augm_matrix(double a[5][5], double b[5][1], int cols, int rows){
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            printf("%.0f ", a[i][j]);
        }
        printf("| %.0f\n", b[i][0]);
    }
    printf("(aprox. integer)\n");
}

void pivoting(double a[5][5], double b[5][1], int cols, int rows, char current_col){
    double max = 0;
    char pivot_row = 0;
//    char actual_zeros[6] = "00000";
//    char elimination_complete_zeros[6] = "00000";
    
    // Finding pivot row
    printf("\nFinding pivot in column number %d:\n", current_col+1);
//    strcpy(actual_zeros, "00000");
//    strcpy(elimination_complete_zeros, "00000");
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
//        if (a[i][current_col] == 0){
//            actual_zeros[i] = '1';
//        }
    }
    
    if (pivot_row != 0){
        printf("＞Pivot row in column %d: %d\n", current_col+1, pivot_row+1);
    }
    else {
        printf("＞The top most row has already the highest value\n");
    }
    /*
    for (char index = current_col+1; index<cols; index++){
        elimination_complete_zeros[index] = '1';
    }
    printf("* Expected indexes of zeros after forward elimination: %s\n",elimination_complete_zeros);
    printf("* Actual indexes of zeros: %s\n",actual_zeros);
    if (strcmp(actual_zeros, elimination_complete_zeros)!=0){
        printf("* Column number %d still have non-zeros values\n", current_col+1);
        printf("\n************************\n");
    }
    else{
        printf("* This column has every possible value turned to zero\n");
        printf("\n************************\n");
    }
    */
    
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
        double temp_b = b[current_col][0];
        b[current_col][0] = b[pivot_row][0];
        b[pivot_row][0] = temp_b;
        printf("＞Rows exhanged\n");
    }
    
    printf("\nInspecting matrices\n");
    print_augm_matrix(a, b, cols, rows);
    printf("\n************************\n");
}

void forward_elimination(double a[5][5], double b[5][1], int cols, int rows, char current_col) {
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

void gaussian_elimination(double a[5][5], double b[5][1], int cols, int rows, double x[5][1]) {
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
        printf("%.2f ", x[i][0]);
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
    double b[5][1] = {
        1,
        -1,
        -3,
        5,
        2 }; //GIVEN INFORMATION
    int columns = 5;
    int rows = 5;
    double x[5][1] = {0}; // SOLUTION VECTOR
    
    printf("\nAugmented Matrix of the System of linear eq:\n\n");
    print_augm_matrix(a, b, columns, rows);
    printf("\n************************\n");
    
    gaussian_elimination(a, b, columns, rows, x);
    return 0;
}
