#include <iostream>
#include "complex.hpp"
#include "quadeq.hpp"

enum Mode{
    exet = 0,
    complexcalcul = 1,
    qeSolver = 2,
    incorecct = 3,
};


using namespace std;
int main() {
    Mode mode = Mode::incorecct;
    cout << "Программа выполняет функции: калькулятор комплексных чисел, решение квадратных уравнений. Чтобы программма завершилась напишите 0\n";
    while (mode!=Mode::exet){
        mode = Mode::incorecct;
        while (mode != Mode::complexcalcul && mode != Mode::qeSolver && mode != Mode::exet) {
            cout << "Напиши нужный модуль (1 - арифметика комплексных чисел, 2 - квадратные уравнения): ";
            int temp;
            cin >> temp;
            mode = static_cast<Mode>(temp);
            if (mode != Mode::exet && mode != Mode::complexcalcul && mode != Mode::qeSolver ) {
                cout << "kys\n";
            }
        }
        cout << endl;
        switch (mode)
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