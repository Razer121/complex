#ifndef huawei-projects/complex
#define huawei-projects/complex

#include <iostream>

struct Complex {
    double real = 0;
    double imagine = 0;

    Complex();
    Complex(const Complex& complex);
    Complex(double real, double imagine);

    Complex& operator+=(const Complex& right);
    Complex& operator-=(const Complex& right);
    Complex& operator*=(const Complex& right);
    Complex& operator/=(const Complex& right);

    Complex& operator+=(const double& right);
    Complex& operator-=(const double& right);
    Complex& operator*=(const double& right);
    Complex& operator/=(const double& right);

    Complex& operator=(const Complex& right);

    double Abs() const;

    ~Complex() {}
};

// Unary plus and minus

Complex operator+(Complex complex);
Complex operator-(Complex complex);

// Binary arithmetic operations

Complex operator+(Complex left, Complex right);
Complex operator-(Complex left, Complex right);
Complex operator*(Complex left, Complex right);
Complex operator/(Complex left, Complex right);

Complex operator+(Complex left, double right);
Complex operator-(Complex left, double right);
Complex operator*(Complex left, double right);
Complex operator/(Complex left, double right);

Complex operator+(double left, Complex right);
Complex operator-(double left, Complex right);
Complex operator*(double left, Complex right);

// Comparison operators

bool operator==(const Complex& left, const Complex& right);
bool operator!=(const Complex& left, const Complex& right);

// input output operations

std::ostream& operator<<(std::ostream& os, const Complex& complex);
std::istream& operator>>(std::istream& is, Complex& complex);


#include "complex.cpp"

#endif