#include <iostream>
#include <windows.h>
#include "complex.hpp"
#include "quadeq.hpp"

using namespace std;
int main() {
    SetConsoleOutputCP(CP_UTF8);
    string mode = "3";
    cout << "Программа выполняет функции: калькулятор комплексных чисел, решение квадратных уравнений. Чтобы программма завершилась напишите 0\n";
    while (mode!="0"){
        mode = "3";
        while (mode != "1" && mode != "2" && mode != "0") {
            cout << "Напиши нужный модуль (1 - арифметика комплексных чисел, 2 - квадратные уравнения): ";
            cin >> mode;
            if (mode != "0" && mode != "1" && mode != "2" ) {
                cout << "kys\n";
            }
        }
        cout << endl;
        switch (stoi(mode))
        {
        case 0:
            break;
        case 1:
            Calculator::complexCalculatorTermin();
            break;
        case 2:
            QuadraticEquationSolver::quadEqTermin();
            break;
        default:
            break;
        }
    }
    cout << "Программа завершилась.\n";
}