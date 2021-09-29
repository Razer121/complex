#ifndef COMPLEX_COMPLEXH
#define COMPLEX_COMPLEXH

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

    Complex& operator+=(double right);
    Complex& operator-=(double right);
    Complex& operator*=(double right);
    Complex& operator/=(double right);

    Complex operator+() const;
    Complex operator-() const;

    Complex operator+(const Complex& right) const;
    Complex operator-(const Complex& right) const;
    Complex operator*(const Complex& right) const;
    Complex operator/(const Complex& right) const;

    Complex operator+(double right) const;
    Complex operator-(double right) const;
    Complex operator*(double right) const;
    Complex operator/(double right) const;

    bool operator==(const Complex& right) const;
    bool operator!=(const Complex& right) const;

    Complex& operator=(const Complex& right);

    double Abs() const;

    ~Complex() {}
};

Complex operator+(double left, const Complex& right);
Complex operator-(double left, const Complex& right);
Complex operator*(double left, const Complex& right);

std::ostream& operator<<(std::ostream& os, const Complex& complex);
std::istream& operator>>(std::istream& is, Complex& complex);

#endif