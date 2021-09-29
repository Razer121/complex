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

Complex& Complex::operator+=(double right) {
    real += right;
    return *this;
}
Complex& Complex::operator-=(double right) {
    real -= right;
    return *this;
}    
Complex& Complex::operator*=(double right) {
    real *= right;
    imagine *= right;
    return *this;
}        
Complex& Complex::operator/=(double right) {
    real /= right;
    imagine /= right;
    return *this;
}    

Complex Complex::operator+(const Complex& right) const {
    return Complex(real + right.real, imagine + right.imagine);
}
Complex Complex::operator-(const Complex& right) const {
    return Complex(real - right.real, imagine - right.imagine);;
}
Complex Complex::operator*(const Complex& right) const {
    return Complex(real * right.real - imagine * right.imagine, 
                    real * right.imagine + imagine * right.real);
}
Complex Complex::operator/(const Complex& right) const {
    double tmp_real = (real * right.real + imagine * right.imagine) / 
                            (pow(right.real, 2) + pow(right.imagine, 2));
    double tmp_imagine = (right.real * imagine - real * right.imagine) /
                            (pow(right.real, 2) + pow(right.imagine, 2));
    return Complex(tmp_real, tmp_imagine);
}

Complex Complex::operator+(double right) const{
    return Complex(real + right, imagine);
}
Complex Complex::operator-(double right) const{
    return Complex(real - right, imagine);
}
Complex Complex::operator*(double right) const{
    return Complex(real * right, imagine * right);
}
Complex Complex::operator/(double right) const{
    return Complex(real / right, imagine / right);
}

Complex Complex::operator+() const{
    return Complex(real, imagine);
}
Complex Complex::operator-() const{
    return Complex(real * -1, imagine * -1);
}

bool Complex::operator==(const Complex& right) const{
    return (real == right.real && imagine == right.imagine);
}
bool Complex::operator!=(const Complex& right) const{
    return real != right.real || imagine != right.imagine;
}

Complex& Complex::operator=(const Complex& right) {
    real = right.real;
    imagine = right.imagine;
    return *this;
}

double Complex::Abs() const {
    return sqrt(pow(real, 2) + pow(imagine, 2));
}

Complex operator+(double left, const Complex& right) {
    return Complex(right.real + left, right.imagine);
}
Complex operator-(double left, const Complex& right) {
    return Complex(left - right.real, right.imagine * (-1));
}
Complex operator*(double left, const Complex& right) {
    return Complex(left * right.real, left * right.imagine);
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