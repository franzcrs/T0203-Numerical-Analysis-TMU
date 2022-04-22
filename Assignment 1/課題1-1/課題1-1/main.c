//  
//  main.c
//  
//  数値解析特論
//  課題1-1
//  
//  Version: 0.0
//  Created by Franz Chuquirachi (@franzcrs) on 2022/04/18
//  Copyright © 2022. All rights reserved.
//  

#include <stdio.h>

void three_by_three_matrix_product(double a[3][3], double b[3][3], double c[3][3]){
    for(char i = 0; i<3; i++){
        for(char j = 0; j<3; j++){
            for(char k = 0; k<3; k++){
                c[i][j] = c[i][j] + a[i][k]*b[k][j];
            }
        }
    }
}

int main() {
    double a[3][3] = {1,2,3,4,5,6,7,8,9}; //GIVEN INFORMATION
    double b[3][3] = {9,8,7,6,5,4,3,2,1}; //GIVEN INFORMATION
    double c[3][3] = {0}; //OUTPUT
    three_by_three_matrix_product(a, b, c);
    printf("3 by 3 matrices product:\n");
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            printf("c[%d][%d] = %.2f\n", i, j, c[i][j]);
        }
    }
    return 0;
}
