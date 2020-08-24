#include <iostream>
using namespace std;

class Rational {
public:
    Rational() {
        m_num = 0;
        m_denom = 1;
    }

    Rational(int numerator, int denominator) {
        if (denominator < 0) {
            if (numerator < 0) {
                denominator = abs(denominator);
                numerator = abs(numerator);
            } else {
                denominator = abs(denominator);
                numerator = numerator - 2 * numerator;
            }
        }
        if (numerator == 0) {
            denominator = 1;
        }
        // m_num = numerator;
        // m_denom = denominator;
        int nod = Nod(abs(numerator), abs(denominator));
        m_num = numerator / nod;
        m_denom = denominator / nod;
    }

    int Numerator() const {
        return m_num;
    }

    int Denominator() const {
        return m_denom;
    }

private:
    int m_num;
    int m_denom;

   int Nod(int a, int b) { 
        while (a > 0 && b > 0) {
            if (a > b) {
                a %= b;
            }
            else {
                b %= a;
            }
        } 
        return a + b;
    }
};

bool operator==(Rational a, Rational b) { 
    if ((a.Numerator() == b.Numerator()) && (a.Denominator() == b.Denominator())) {
        return true;
    }
    else {
        return false;
    }
}
Rational operator+(Rational a, Rational b) { 
    int p = (a.Numerator() * b.Denominator()) + (b.Numerator() * a.Denominator());
    int q = a.Denominator() * b.Denominator();
    return Rational(p, q);
}
Rational operator-(Rational a, Rational b) {
    int p = (a.Numerator() * b.Denominator()) - (b.Numerator() * a.Denominator());
    int q = a.Denominator() * b.Denominator();
    return Rational(p, q);
}

Rational operator*(Rational a, Rational b) { 
    int p = (a.Numerator()* b.Numerator());
    int q = (a.Denominator() * b.Denominator());
    return Rational(p,q);
}

Rational operator/(Rational a, Rational b) { 
    int p = (a.Numerator()* b.Denominator());
    int q = (a.Denominator() * b.Numerator());
    return Rational(p,q);
}

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
