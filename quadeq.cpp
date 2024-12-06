#include <cmath>
#include <tuple>
#include <regex>
#include <iostream>
#include "quadeq.hpp"

using namespace std;


tuple<bool,double,double,double> QuadraticEquationSolver::parseEquation(string& equation){
    regex pattern("([+-]?\\d*)x2([+-]?\\d*)x([+-]?\\d*)=0");
    smatch matches;
    double a=1.0,b=1.0,c=1.0;


    bool check =regex_match(equation, matches, pattern);
    if (check) {
        if (matches[1].str() != "" && matches[1].str() != "+" && matches[1].str() != "-") {
            a = stod(matches[1].str());
        } else if (matches[1].str() == "-") {
            a = -1.0;
        }
        if (matches[2].str() != "" && matches[2].str() != "+" && matches[2].str() != "-") {
            b = stod(matches[2].str());
        } else if (matches[2].str() == "-") {
            b = -1.0;
        }
        if (matches[3].str() != "") {
            c = stod(matches[3].str());
        }
    } else {
        return {false, 0.0, 0.0, 0.0};
    }
    return {true, a, b, c};
}

tuple<bool,double,double> QuadraticEquationSolver::solveQuadEq(tuple<bool,double,double,double> coefs){
    double discriminant,a,b,c;
    a=get<1>(coefs);
    b=get<2>(coefs);
    c=get<3>(coefs);
    discriminant = pow(b, 2) - 4 * a * c;
    
    double x1, x2;
    if (a!=0){
        if (discriminant>=0){
            x1=(-b+sqrt(discriminant))/(2*a);
            x2=(-b-sqrt(discriminant))/(2*a);
            return {true,x1,x2};
        }else{
            cout << "Дискриминант меньше 0\n";
        }
    }
    else{
        cout << "Коэфицент a равен нулю, найти корни невозможно.\n";
    };
    return {false,0.0,0.0};
};

void QuadraticEquationSolver::quadEqTermin(){
    cout << "Введите квадратное уравнение в формате(ax2+bx+c=0)";
    
    string quadEq;
    cin >> quadEq;

    tuple<bool,double,double,double> coef;
    coef = QuadraticEquationSolver::parseEquation(quadEq);

    if (get<0>(coef)==true){
        tuple<bool,double,double> solutionQuadEq = QuadraticEquationSolver::solveQuadEq(coef);
        if (get<0>(solutionQuadEq)==true){
            double x1,x2;
            x1=get<1>(solutionQuadEq);
            x2=get<2>(solutionQuadEq);

            cout << "Корни квадратного уравнения: x1=" << x1 << " x2=" << x2 << endl;
        }
    } else{
        cout << "Не удалось получить коэфиценты уравнения.\n";
        return;
    }
}