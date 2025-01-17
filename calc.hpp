#ifndef CALC_HPP
#define CALC_HPP

class Operation {
public:
    virtual double execute(double a, double b) = 0;
    virtual ~Operation() = default;
};

class Addition : public Operation {
public:
    double execute(double a, double b) override;
};

class Subtraction : public Operation {
public:
    double execute(double a, double b) override;
};

class Multiplication : public Operation {
public:
    double execute(double a, double b) override;
};

class Division : public Operation {
public:
    double execute(double a, double b) override;
};

class OperationFactory {
public:
    static Operation* createOperation(char op);
};

class OperationAdapter {
private:
    Operation* operation;
public:
    OperationAdapter(char op);
    double execute(double a, double b);
};

class Calculator {
public:
    double calculate(double a, char op, double b);
};

#endif // CALC_HPP