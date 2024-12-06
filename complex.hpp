#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // ничего умнее не придумал :c
    void print() const {
        if (real == 0 && imag == 0) {
            cout << "0";
        } else if (real == 0) {
            cout << imag << "i";
        } else if (imag == 0) {
            cout << real;
        } else if (imag > 0) {
            cout << real << " + " << imag << "i";
        } else {
            cout << real << " - " << -imag << "i";
        }
    }

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;
    
    static Complex parse(const string& str);
};

class Calculator {
public:
    static void complexCalculatorTermin();
private:
    static void performOperation(const Complex& num1, const Complex& num2, char operation);
};

#endif 