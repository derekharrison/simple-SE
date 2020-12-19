/*
 * complex.hpp
 *
 *  Created on: Dec 19, 2020
 *      Author: d-w-h
 */

#ifndef COMPLEX_HPP_
#define COMPLEX_HPP_

class Complex {
public:
    double a;
    double b;
    Complex(double a, double b);
    Complex operator+(const Complex& m);
    Complex operator*(const Complex& m);
};

#endif /* COMPLEX_HPP_ */
