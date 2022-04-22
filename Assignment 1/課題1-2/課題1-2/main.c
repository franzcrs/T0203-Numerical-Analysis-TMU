//  
//  main.c
//  
//  数値解析特論
//  課題1-2
//  
//  Version: 0.0
//  Created by Franz Chuquirachi (@franzcrs) on 2022/04/19
//  Copyright © 2022. All rights reserved.
//  

#include <stdio.h>

double matrix_inf_norm(double a[3][3]){
    double max = 0;
    double sum_per_row[3] = {0};
    for(char i = 0; i<3; i++){
        for(char j = 0; j<3; j++){
            sum_per_row[i] = sum_per_row[i] + a[i][j];
            if(i==0){
                max = sum_per_row[i];
            }
            else if (sum_per_row[i]>max){
                max = sum_per_row[i];
            }
        }
    }
    return max;
}

int main() {
    double a[3][3] = {1,2,3,4,5,6,7,8,9}; //GIVEN INFORMATION
    double inf_norm = matrix_inf_norm(a); //OUTPUT
    printf("Matrix:\n");
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            printf("a[%d][%d] = %.2f\n", i, j, a[i][j]);
        }
    }
    printf("Infinity norm: %0.2f\n", inf_norm);
    return 0;
}
