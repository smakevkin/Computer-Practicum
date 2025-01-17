#include <iostream>
#include <regex>
#include "calc.hpp"

using namespace std;

void parse(double& a, char& op, double& b, const string& str) {
    regex re(R"((\d+(?:\.\d+)?)\s*([\+\-\*/])\s*(\d+(?:\.\d+)?))");
    smatch match;

    if (regex_match(str, match, re)) {
        a = stod(match[1]);
        op = match.str(2)[0];
        b = stod(match[3]);
    } else {
        throw runtime_error("Введено выражение не по формату!");
    }
}

int main() {
    Calculator calculator;
    double a, b;
    char op;
    string input;

    cout << "Это простой калькулятор"<< endl;
    cout << "Для выхода введите 0+0" << endl << endl;
    while (true){
        cout << "Введите выражение вида 'число операция число': ";
        cin >> input;
        if (input=="0+0"){break;}

        try {
            parse(a, op, b, input);
            double result = calculator.calculate(a, op, b);
            cout << "Результат: " << result << endl;
        } catch (const exception& e) {
            cerr << "Ошибка: " << e.what() << endl;
        }
    }

    return 0;
}