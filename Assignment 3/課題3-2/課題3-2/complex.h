//  
//  complex.h
//  
//  数値解析特論
//  課題3-2
//  
//  Version: 0.0
//  Created by Franz Chuquirachi (@franzcrs) on 2022/05/09
//  Copyright © 2022. All rights reserved.
//  

#ifndef complex_h
#define complex_h

#include <cmath>
#include <iomanip>

class Complex {
    
public:
    
    double re;
    double im;
    
    Complex(double real = 0, double imaginary = 0) {
        re = real;
        im = imaginary;
    }
    
    void print(uint8_t precision = 2){
        bool precision_exceeded = false;
        if (precision>4) {
            precision_exceeded = true;
            precision = 4;
        }
        std::cout << std::setprecision(int(precision)) << std::fixed;
        std::cout << re << " ";
        if(im < 0) {
            std::cout << "- " << abs(im) << "i";
        }
        else {
            std::cout << "+ " << im << "i";
        }
        if (precision_exceeded) {
            std::cout << " (Inquired precision is more than 4. Fixing precision to 4.)";
        }
        std::cout << "\n";
    }
};

Complex operator+(Complex a, Complex b) {
    Complex r;
    r.re = a.re + b.re;
    r.im = a.im + b.im;
    return r;
}

Complex operator+(double real, Complex b) {
    Complex r;
    r.re = real + b.re;
    r.im = b.im;
    return r;
}

Complex operator-(Complex a, Complex b) {
    Complex r;
    r.re = a.re - b.re;
    r.im = a.im - b.im;
    return r;
}

Complex operator-(Complex a, double real) {
    Complex r;
    r.re = a.re - real;
    r.im = a.im;
    return r;
}

Complex operator-(double real, Complex b) {
    Complex r;
    r.re = real - b.re;
    r.im = -b.im;
    return r;
}

Complex operator-(Complex a) {
    Complex r;
    r.re = (-1)*a.re;
    r.im = (-1)*a.im;
    return r;
}

Complex operator*(Complex a, Complex b) {
    Complex r;
    r.re = a.re * b.re - a.im * b.im;
    r.im = a.re * b.im + b.re * a.im;
    return r;
}

Complex operator*(double real, Complex a) {
    Complex r;
    r.re = real * a.re;
    r.im = real * a.im;
    return r;
}

Complex operator/(Complex a, Complex b) {
    Complex r;
    r.re = (a.re * b.re + a.im * b.im)/(b.re*b.re + b.im*b.im);
    r.im = (a.im * b.re - a.re * b.im)/(b.re*b.re + b.im*b.im);
    return r;
}

Complex operator/(Complex a, double real) {
    Complex r;
    r.re = a.re/real;
    r.im = a.im/real;
    return r;
}

#endif /* complex_h */
