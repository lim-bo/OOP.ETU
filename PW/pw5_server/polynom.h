#pragma once
#include "array.h"
#include "number.h"
#include <iostream>
#include <string>
#include <sstream>

class Polynomial {
    int degree;   // Степень полинома
    Array roots;            //Массив корней
    Array coefficients;    // Массив коэфф
    void calculateCoefficientsFromRoots();
public:
    Polynomial();
    Polynomial(int, number);
    Polynomial(number, Array);
    void printPolynomialWithCoefficients() const;
    std::string StringRepresentWithCoeff() const;
    std::string StringRepresentWithRoots() const;
    void printPolynomialWithRoots() const;
    number evaluate(number) const;
    number getRoot(unsigned) const;
    number getCoeff(unsigned) const;
    void setHigherCoeff(number);
    void setRoot(unsigned, number);
    void resizeRoots(unsigned);
};
