#include "complexn.h"

std::ostream& operator<< (std::ostream& out, const Complex& num) {
	return out << num.re << ((num.im >= 0) ? "+" : "") << num.im << 'i';
}

std::istream& operator>> (std::istream& in, Complex& num) {
	in >> num.re >> num.im;
	return in;
}

bool operator< (const Complex& left, const Complex& right) {
	double leftM = sqrt( left.im * left.im + left.re * left.re);
	double rightM = sqrt(right.im * right.im + right.re * right.re);
	return leftM < rightM;
}

bool operator> (const Complex& left, const Complex& right) {
	double leftM = sqrt(left.im * left.im + left.re * left.re);
	double rightM = sqrt(right.im * right.im + right.re * right.re);
	return leftM > rightM;
}

Complex operator+ (const Complex& left, const Complex& right) {
	Complex out;
	out.im = left.im + right.im;
	out.re = left.re + right.re;
	return out;
}

Complex& operator+= (Complex& left, const Complex& right) {
	left.im += right.im;
	left.re += right.re;
	return left;
}

Complex operator- (const Complex& left, const Complex& right) {
	Complex out;
	out.im = left.im - right.im;
	out.re = left.re - right.re;
	return out;
}

Complex::Complex() {
	this->im = 0;
	this->re = 0;
}

Complex::Complex(double re, double im) {
	this->re = re;
	this->im = im;
}

Complex operator/ (const Complex& left, const unsigned int num) {
	Complex res;
	res.re = left.re / num;
	res.im = left.im / num;
	return res;
}


Complex operator* (const Complex& left, const Complex& right) {
	Complex res;
	res.re = left.re * right.re - left.im * right.im;
	res.im = left.re * right.im + left.im * right.re;
	return res;
}

Complex& operator/= (Complex& left, const unsigned int num) {
	left.im /= num;
	left.re /= num;
	return left;
}

Complex Complex::sqrt() const {
	Complex res;
	res.re = std::sqrt((this->re + this->abs()) / 2);
	res.im = std::sqrt((this->abs() - this->re) / 2);
	res.im *= (this->im < 0) ? -1 : 1;
	return res;
}

double Complex::abs() const {
	return std::sqrt(re * re + im * im);
}

bool operator >= (const Complex& left, const Complex& right) {
	return left.abs() >= right.abs();
}

Complex operator* (const Complex& left, const int& right) {
	Complex out(left);
	out.im *= right;
	out.re *= right;
	return out;
}

Complex& operator*= (Complex& left, const Complex& right) {
	left = left * right;
	return left;
}

Complex sqrt(const Complex& num) {
	return num.sqrt();
}

Complex::Complex(std::string str) {
    std::stringstream ss(str);
    ss >> re;
    ss >> im;
}

std::string Complex::string() const {
    std::string out, buf;
    std::stringstream ss;
    ss << re;
    ss >> buf;
    out += buf;
    out += (im >= 0 ? "+" : "");
    ss.clear();
    ss << im;
    ss >> buf;
    out += buf;
    out += "i";
    return out;
}
