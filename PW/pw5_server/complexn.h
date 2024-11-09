#pragma once
#include <iostream>
#include <math.h>
#include <sstream>
#include <string>

class Complex
{
private:
	double im;
	double re;
public:
	Complex();
	Complex(double, double);
    Complex(std::string);
	Complex sqrt() const;
	double abs() const;
    std::string string() const;

	friend std::ostream& operator << (std::ostream&, const Complex&);
	friend bool operator < (const Complex&, const Complex&);
	friend bool operator > (const Complex&, const Complex&);
	friend bool operator >= (const Complex&, const Complex&);
	friend Complex operator+ (const Complex&, const Complex&);
	friend Complex operator- (const Complex&, const Complex&);
	friend Complex& operator+= (Complex&, const Complex&);
	friend std::istream& operator>> (std::istream&, Complex&);
	friend Complex operator* (const Complex&, const Complex&);
	friend Complex operator/ (const Complex&, const unsigned int);
	friend Complex& operator/= (Complex&, const unsigned int);
	friend Complex& operator*= (Complex&, const Complex&);
	friend Complex operator* (const Complex&, const int&);
};

Complex sqrt(const Complex&);
