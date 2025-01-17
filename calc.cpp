#include "calc.hpp"


double Addition::execute(double a, double b) {
    return a + b; 
}

double Subtraction::execute(double a, double b)  {
    return a - b; 
}

double Multiplication::execute(double a, double b)  {
    return a * b; 
}

double Division::execute(double a, double b)  {
    if (b == 0) {
        throw "Деление на 0!"; 
    }
    return a / b; 
}

// фабрика операций(fabric)
Operation* OperationFactory::createOperation(char op) {
    switch (op) {
        case '+': return new Addition(); 
        case '-': return new Subtraction(); 
        case '*': return new Multiplication(); 
        case '/': return new Division(); 
        default: throw "Неправильная операция!"; 
    }
}

// адаптер для операций(adapter)
OperationAdapter::OperationAdapter(char op) {
    operation = OperationFactory::createOperation(op);
}

double OperationAdapter::execute(double a, double b) {
    return operation->execute(a, b); 
}

//класс калькулятора)
double Calculator::calculate(double a, char op, double b) {
    OperationAdapter adapter(op); 
    return adapter.execute(a, b); 
}