//  
//  main.cpp
//
//  数値解析特論
//  課題3-1
//  
//  Version: 0.0
//  Created by Franz Chuquirachi (@franzcrs) on 2022/05/09
//  Copyright © 2022. All rights reserved.
//  

#include <iostream>
#include "complex.h"

int main() {
    std::cout <<
    "-------------------------\n"
    "Solve: 3x^3 - x*y^2 + 3y -1\n"
    "Given: x = 2 + 5i and y = -1 + 2i\n\n";
    
    Complex x(2,5); // GIVEN DATA
    Complex y(-1,2); // GIVEN DATA
    Complex result; // SOLUTION VARIABLE
    
    std::cout << "Solving...\n";
    
    result = 3*x*x*x - x*y*y + 3*y - 1;
    std::cout << "＞Result: ";
    result.print();
    std::cout << "-------------------------\n";
    
    return 0;
}
