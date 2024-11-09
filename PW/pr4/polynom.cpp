#include "polynom.h"

void Polynomial::calculateCoefficientsFromRoots() {
    Array coeff(degree + 1);
    coeff.setAt(0, coefficients.get(0));  // Коэффициент при старшей степени x^N
    number leading = coefficients.get(0);
    // Обратное вычисление коэффициентов (от n - 1 до 0)
    for (unsigned i = 1; i <= degree; i++) {
        number temp(1, 0);
        for (unsigned j = 0; j < i; j++) {
            temp *= roots.get(j);
        }
        coeff.setAt(i, leading * temp);
        leading *= roots.get(i - 1) * -1;
    }

    coefficients = coeff;
}

Polynomial::Polynomial() : degree(0), coefficients(1), roots(0) {
    coefficients.setAt(0, number{});  // p(x) = 0
}

Polynomial::Polynomial(int deg, number coeff) : degree(deg), roots(deg), coefficients(deg + 1) {
    std::cout << "Введите корни полинома: " << std::endl;
    number temp;
    for (unsigned i = 0; i < degree; ++i) {
        std::cin >> temp;
        roots.setAt(i, temp);
    }
    coefficients.setAt(0, coeff);
    calculateCoefficientsFromRoots();  // Вычисление коэффициентов на основе корней
}

Polynomial::Polynomial(number cf, Array rts) : degree(rts.size()), coefficients(rts.size() + 1){
    roots = rts;
    coefficients.setAt(0, cf);
    calculateCoefficientsFromRoots();
}
void Polynomial::printPolynomialWithCoefficients() const {
    for (int i = 0; i < degree; i++) {
        number coeff = coefficients.get(i);
        std::cout << (coeff >= number{} && i > 0 ? "+" : "") << "(" << coeff << ")" << "x^" << degree - i;
    }
    std::cout << (coefficients.get(degree) >= number{} && degree != 0 ? "+" : "") << "(" << coefficients.get(degree) << ")";
    std::cout << std::endl;
}

// Функция для вывода полинома в виде корней
void Polynomial::printPolynomialWithRoots() const {
    if (degree == 0) {
        std::cout << "0" << std::endl;
        return;
    }

    std::cout << "P(x) = " << coefficients.get(0) << " * (x - (" << roots.get(0) << "))";
    for (unsigned i = 1; i < roots.size(); ++i) {
        std::cout << " * (x - (" << roots.get(i) << "))";
    }
    std::cout << std::endl;
}

// Вычисление значения полинома при заданном x
number Polynomial::evaluate(number x) const {
    number result{};
    for (int i = degree; i >= 0; --i) {
        result = result * x + coefficients.get(i);
    }
    return result;
}

// Получение значения корня по индексу
number Polynomial::getRoot(unsigned index) const {
    if (index < roots.size()) {
        return roots.get(index);
    }
    return number{};
}

// Получение коэффициента по индексу
number Polynomial::getCoeff(unsigned i) const {
    if (i < coefficients.size()) {
        return coefficients.get(i);
    }
    return number{};
}

void Polynomial::setHigherCoeff(number n) {
    if (!degree) return;
    coefficients.setAt(0, n);
    calculateCoefficientsFromRoots();
}
void Polynomial::setRoot(unsigned i, number n) {
    if (i >= roots.size()) return;
    roots.setAt(i, n);
    calculateCoefficientsFromRoots();
}

void Polynomial::resizeRoots(unsigned newSize) {
    degree = newSize;
    roots.resize(newSize);
    calculateCoefficientsFromRoots();
}

std::string Polynomial::StringRepresentWithCoeff() const {
    std::string out;
    for (int i = 0; i < degree; i++) {
        number coeff = coefficients.get(i);
        out += (coeff >= number{} && i > 0 ? "+" : "");
        out += "(";
        out += coeff.string();
        out += ")x^";
        out += std::to_string(degree - i);
    }
    out += (coefficients.get(degree) >= number{} && degree != 0 ? "+" : "");
    out += "(";
    out += coefficients.get(degree).string();
    out += ")";
    return out;
}

std::string Polynomial::StringRepresentWithRoots() const {
    if (degree == 0) {
        return "0";
    }
    std::string out;
    out += "P(x) = ";
    out += coefficients.get(0).string();
    out += " * (x - (";
    out += roots.get(0).string();
    out += "))";
    for (unsigned i = 1; i < roots.size(); ++i) {
        out += " * (x - (";
        out += roots.get(i).string();
        out += "))";
    }
    return out;
}
