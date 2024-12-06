#include <iostream>
#include <regex>
#include "complex.hpp"

using namespace std;

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(real * other.real - imag * other.imag,
                    real * other.imag + imag * other.real);
}//https://www.webmath.ru/poleznoe/formules_16_9.php

Complex Complex::operator/(const Complex& other) const {
    double delitel = other.real * other.real + other.imag * other.imag;
    if (delitel == 0) {
        throw runtime_error("Числа невозможно разделить.");
    }
    double realPart = (real*other.real + imag*other.imag) / delitel;
    double imagPart = (other.real*imag-real*other.imag) / delitel;
    return Complex(realPart, imagPart);
}//https://www.webmath.ru/poleznoe/formules_16_10.php

    
Complex Complex::parse(const std::string& str) {
    regex re("^([-+]?[0-9]+\\.?[0-9]*)([+-]?[0-9]+\\.?[0-9]*i)?$");
    smatch match;

    if (regex_match(str, match, re)) {
        double realPart = 0, imagPart = 0;

        if (!match[1].str().empty()) {
            realPart = stod(match[1].str());
        }

        if (!match[2].str().empty()) {
            string imagStr = match[2].str();
            if (imagStr == "i" || imagStr == "+i") {
                imagPart = 1;
            } else if (imagStr == "-i") {
                imagPart = -1;
            } else {
                imagPart = stod(imagStr.substr(0, imagStr.size() - 1));  // Убираем 'i'
            }
        }

        return Complex(realPart, imagPart);
    } else {
        throw runtime_error("Неверный формат комплексного числа");
    }
}



void Calculator::complexCalculatorTermin(){
    string input1, input2;
    char operation;

    cout << "Введите первое комплексное число (формат: a+bi, a-i, a+i или просто a): ";
    cin >> input1;
    Complex num1 = Complex::parse(input1);

    cout << "Введите второе комплексное число (формат: a+bi, a-i, a+i или просто a): ";
    cin >> input2;
    Complex num2 = Complex::parse(input2);

    cout << "Введите операцию (+, -, *, /, m для модуля первого числа): ";
    cin >> operation;

    Calculator::performOperation(num1, num2, operation);
};

void Calculator::performOperation(const Complex& num1, const Complex& num2, char operation) {
    try {
        Complex result;
        switch (operation) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                result = num1 / num2;
                break;
            default:
                cout << "Некорректная операция!" << endl;
                return;
        }

        cout << "Результат: ";
        result.print();
        cout << endl;
        cout << endl;
    } catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
};