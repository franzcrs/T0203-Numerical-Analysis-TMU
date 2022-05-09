//  
//  complexClass.h
//  
//  *Describe purpose*
//  
//  Version: 0.0
//  Written using Swift 5.0
//  Created by Franz Chuquirachi (@franzcrs) on 2022/05/09
//  Copyright © 2022. All rights reserved.
//  

#ifndef complexClass_h
#define complexClass_h

#include <cmath>

class Complex {
    
public:
    
    double re;
    double im;
    
    Complex(double real = 0, double imaginary = 0) {
        re = real;
        im = imaginary;
    }
    
    void print(){
        printf("%0.2f ", re);
        if(im < 0) {
            printf("- %0.2fi\n", abs(im));
        }
        else {
            printf("+ %0.2fi\n", im);
        }
    }
};

Complex operator+(Complex a, Complex b) {
    Complex r;
    r.re = a.re + b.re;
    r.im = a.im + b.im;
    return r;
}

Complex operator-(Complex a, Complex b) {
    Complex r;
    r.re = a.re - b.re;
    r.im = a.im - b.im;
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

Complex operator*(double scalar, Complex a) {
    Complex r;
    r.re = scalar * a.re;
    r.im = scalar * a.im;
    return r;
}

Complex operator/(Complex a, Complex b) {
    Complex r;
    r.re = (a.re * b.re + a.im * b.im)/(b.re*b.re + b.im*b.im);
    r.im = (a.im * b.re - a.re * b.im)/(b.re*b.re + b.im*b.im);
    return r;
}

#endif /* complexClass_h */
