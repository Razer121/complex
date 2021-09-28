#include "complex.h"

#include <iostream>
#include <cmath>

using namespace std::literals;

Complex::Complex() = default;

Complex::Complex(const Complex& complex)
    :real(complex.real), imagine(complex.imagine) {}

Complex::Complex(double real, double imagine) 
: real(real), imagine(imagine) {}

Complex& Complex::operator+=(const Complex& right) {
    real += right.real;
    imagine += right.imagine;
    return *this;
}

Complex& Complex::operator-=(const Complex& right) {
    real -= right.real;
    imagine -= right.imagine;
    return *this;
}

Complex& Complex::operator*=(const Complex& right) {
    real = real * right.real - imagine * right.imagine;
    imagine = real * right.imagine + imagine * right.real;
    return *this;
}

Complex& Complex::operator/=(const Complex& right) {
    real = (real * right.real + imagine * right.imagine) / 
    (pow(right.real, 2) + pow(right.imagine, 2));

    imagine = (right.real * imagine - real * right.imagine) /
    (pow(right.real, 2) + pow(right.imagine, 2));
    return *this;
}

Complex& Complex::operator+=(const double& right) {
    real += right;
    return *this;
}
Complex& Complex::operator-=(const double& right) {
    real -= right;
    return *this;
}    
Complex& Complex::operator*=(const double& right) {
    real *= right;
    imagine *= right;
    return *this;
}        
Complex& Complex::operator/=(const double& right) {
    real /= right;
    imagine /= right;
    return *this;
}    

Complex operator+(Complex left, Complex right) {
    return left += right;
}

Complex operator-(Complex left, Complex right) {
    return left -= right;
}

Complex operator*(Complex left, Complex right) {
    return left *= right;
}

Complex operator/(Complex left, Complex right) {
    return left /= right;
}

Complex operator+(Complex left, double right) {
    return left += right;
}

Complex operator-(Complex left, double right) {
    return left -= right;
}

Complex operator*(Complex left, double right) {
    return left *= right;
}

Complex operator/(Complex left, double right) {
    return left /= right;
}


Complex operator+(double left, Complex right) {
    return right += left;
}

Complex operator-(double left, Complex right) {
    right -= left;
    right *= -1;
    return right;
}

Complex operator*(double left, Complex right) {
    return right *= left;
}

Complex& Complex::operator=(const Complex& right) {
    real = right.real;
    imagine = right.imagine;
    return *this;
}

Complex operator+(Complex complex) {
    return complex;
}

Complex operator-(Complex complex) {
    complex.real *= -1;
    complex.imagine *= -1;
    return complex;
}

bool operator==(const Complex& left, const Complex& right) {
    return (left.real == right.real && left.imagine == right.imagine);
}

bool operator!=(const Complex& left, const Complex& right) {
    return left.real != right.real || left.imagine != right.imagine;
}

double Complex::Abs() const {
    return sqrt(pow(real, 2) + pow(imagine, 2));
}

std::istream& operator>>(std::istream& is, Complex& complex) {
    double real = NAN;
    double imagine = NAN;
    std::cout << "Введите действительную часть:"s;
    is >> real;
    std::cout << "Введите мнимую часть:"s;
    is >> imagine;
    complex = Complex{real, imagine};
    return is;
}

std::ostream& operator<<(std::ostream& os, const Complex& complex) {
    os << complex.real;
    if(complex.imagine > 0) {
        os << " + "s << complex.imagine;
    }
    else {
        os << " - "s << std::abs(complex.imagine);
    }
    return os;
}