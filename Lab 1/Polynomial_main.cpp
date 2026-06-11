#include <iostream>
#include "Polynomial.h"
using namespace std;

int main()
{
    Polynomial p1(10);
    Polynomial p2(10);
    p1.addTerm(-2, 0);
    p1.addTerm(5, 3);
    p1.addTerm(4, 1);

    p2.addTerm(1, 0);
    p2.addTerm(3, 3);
    p2.addTerm(2, 5); 
    // p.addTerm(5, 4);
    // p.addTerm(6, 7);

    cout <<"P1: " << p1 << endl;
    cout <<"P2: " << p2 << endl;

    cout << endl << "Degree: " << p1.getDegree() << endl;
    cout << "Coefficient: " << p1.getCoefficient(3) << endl;
    cout <<"Evalution Result: " <<  p1(2) << endl;
    Polynomial sum = (p1 + p2);
    cout <<"Sum of Polynomials: " << sum << endl;
    Polynomial diff = (p1 - p2);
    cout <<"Diff of Polynomials: " << diff << endl;
    Polynomial product = (p1 * p2);
    cout <<"Product of Polynomials: " << product << endl;
    Polynomial der = p1.derivative();
    cout <<"Derivative: " <<  der << endl;
    Polynomial antider = der.antiDerivative();
    cout <<"Anti-Derivative: " <<  antider << endl;
    cout <<"New Added Polynomial: " << p1.addToCoefficient(3 , 1) << endl;
    cout <<"New Set Polynomial: " << p1.setCoefficient(3 , 2) << endl;
}