#include <iostream>
#include "Polynomial.h"
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

Polynomial::Polynomial(int s = 0)
{
    capacity = s;
    size = 0;
    poly = new int[s];
    for (int i = 0; i < capacity; i++)
    {
        poly[i] = 0;
    }
}

Polynomial::Polynomial(const Polynomial &other)
{
    capacity = other.capacity;
    size = other.size;
    poly = new int[capacity];
    for (int i = 0; i < capacity; i++)
    {
        poly[i] = other.poly[i];
    }
}

Polynomial::~Polynomial()
{
    delete[] poly;
}

void Polynomial::resize(int pow)
{
    int newCap = pow * 2;
    int *newPoly = new int[newCap];
    for (int i = 0; i <= size; i++)
    {
        newPoly[i] = poly[i];
    }
    for (int i = size + 1; i < newCap; i++)
    {
        newPoly[i] = 0;
    }
    delete[] poly;
    poly = newPoly;
    capacity = newCap;
}

void Polynomial::addTerm(int coefficient, int power)
{
    if (power >= capacity)
    {
        resize(power);
    }
    poly[power] = coefficient;
    if (power > size)
        size = power;
}

int Polynomial::getDegree()
{
    int deg = size;
    while (deg > 0 && poly[deg] == 0)
        deg--;
    return deg;
}

int Polynomial::getCoefficient(int power)
{
    return poly[power];
}

int Polynomial::operator()(int value)
{
    int ans = 0;
    for (int i = 0; i <= size; i++)
    {
        ans += poly[i] * pow(value, i);
    }
    return ans;
}

Polynomial Polynomial::operator+(const Polynomial &other)
{
    int maxi = max(this->size, other.size);
    Polynomial ans(maxi + 1);
    for (int i = maxi; i >= 0; i--)
    {
        ans.poly[i] = 0;
        if (i <= this->size)
            ans.poly[i] += poly[i];
        if (i <= other.size)
            ans.poly[i] += other.poly[i];
    }
    ans.size = maxi;

    return ans;
}

Polynomial Polynomial::operator-(const Polynomial &other)
{
    int maxi = max(this->size, other.size);
    Polynomial ans(maxi + 1);
 
    for(int i = 0; i < ans.capacity; i++)
    {
        ans.poly[i] = 0;
    }

    for (int i = 0; i <= maxi; i++)
    {
        if (i <= this->size)
            ans.poly[i] += poly[i];
        if (i <= other.size)
            ans.poly[i] -= other.poly[i];
    }
    ans.size = maxi;
    ans.size = ans.getDegree();

    return ans;
}

Polynomial Polynomial::operator*(const Polynomial &other)
{
    int maxi = this->size + other.size;
    Polynomial ans(maxi + 1);
 
    for(int i = 0; i < ans.capacity; i++)
    {
        ans.poly[i] = 0;
    }

    for (int i = 0; i <= this->size; i++)
    {
        if(this->poly[i] != 0)
        {
           for(int j = 0; j <= other.size; j++)
           {
            if(other.poly[j] != 0)
            {
                int power = i + j;
                int coeff = this->poly[i] * other.poly[j];
                ans.poly[power] += coeff;
            }
           }
        }
    }
    ans.size = maxi;
    ans.size = ans.getDegree();

    return ans;
}

Polynomial &Polynomial::operator=(const Polynomial &other)
{
    if (this != &other)
    {
        delete[] poly;
        capacity = other.capacity;
        size = other.size;
        poly = new int[capacity];
        for (int i = 0; i < capacity; i++)
        {
            if (i <= size)
                poly[i] = other.poly[i];
            else
                poly[i] = 0;
        }
    }
    return *this;
}

Polynomial Polynomial::derivative()
{
    if (this->size == 0)
    {
        Polynomial der(1);
        der.poly[0] = 0;
        der.size = 0;
        return der;
    }

    Polynomial der(this->size);
    for (int i = this->size; i > 0; i--)
    {
        der.poly[i - 1] = i * this->poly[i];
    }
    der.size = this->size - 1;
    return der;
}

Polynomial Polynomial::antiDerivative()
{
    Polynomial antider(this->size + 1);

    for (int i = 0; i < antider.capacity; i++)
    {
        antider.poly[i] = 0;
    }

    for (int i = this->size; i >= 0; i--)
    {
        if (this->poly[i] != 0)
            antider.poly[i + 1] = this->poly[i] / (i + 1);
    }
    srand(time(0));
    antider.poly[0] = rand() % 10;
    antider.size = this->size + 1;
    return antider;
}

Polynomial &Polynomial::addToCoefficient(int coefficient, int power)
{
    if (power >= capacity)
        resize(power);
    poly[power] += coefficient;
    if (power > size)
        size = power;
    return *this;
}

Polynomial &Polynomial::setCoefficient(int coefficient, int power)
{
    if (power >= capacity)
        resize(power);
    poly[power] = coefficient;
    if (power > size)
        size = power;
    return *this;
}

void Polynomial::clear()
{
    for (int i = 0; i < size; i++)
    {
        poly[i] = 0;
    }
}

ostream &operator<<(ostream &out, const Polynomial &p)
{
    bool first = true;

    for (int i = p.size; i >= 0; i--)
    {
        if (p.poly[i] != 0)
        {
            if (first)
            {
                out << p.poly[i];
                if (i != 0)
                    out << "x^" << i;
                first = false;
            }
            else
            {
                if (p.poly[i] > 0)
                    out << " + " << p.poly[i];
                else
                    out << " - " << -p.poly[i];

                if (i != 0)
                    out << "x^" << i;
            }
        }
    }

    if (first)
        out << 0;
    return out;
}
