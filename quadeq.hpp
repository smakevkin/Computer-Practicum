#ifndef QUADEQ_HPP
#define QUADEQ_HPP
using namespace std;

class QuadraticEquationSolver {
public:
    static tuple<bool,double,double,double> parseEquation(string& equation);
    static tuple<bool,double,double> solveQuadEq(tuple<bool,double,double,double> coefs);
    static void quadEqTermin();
};

#endif 
