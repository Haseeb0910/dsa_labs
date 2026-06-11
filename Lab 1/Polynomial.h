#ifndef POLY_H
#define POLY_H

#include <iostream>
using namespace std;

class Polynomial
{
protected:
    int *poly;
    int size;
    int capacity;

public:
    Polynomial(int s);
    Polynomial(const Polynomial &other);
    ~Polynomial();
    void resize(int pow);
    void addTerm(int coefficient, int power);
    int getDegree();
    int getCoefficient(int power);
    int operator()(int value);
    Polynomial operator+(const Polynomial &other);
    Polynomial operator-(const Polynomial &other);
    Polynomial operator*(const Polynomial &other);
    Polynomial& operator=(const Polynomial &other);
    Polynomial derivative();
    Polynomial antiDerivative();
    Polynomial& addToCoefficient(int coefficient, int power);
    Polynomial& setCoefficient(int coefficient, int power);
    void clear();
    friend ostream &operator<<(ostream &out, const Polynomial &p);
};

#endif