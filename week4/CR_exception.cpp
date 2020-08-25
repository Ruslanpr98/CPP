#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

class Rational {
public:
    Rational() {
        m_num = 0;
        m_denom = 1;
    }

    Rational(int numerator, int denominator) {
        if (denominator == 0) {
            throw invalid_argument("invalid argument");
        }
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
    if (q == 0) {
        throw domain_error("domain_error");
    }
    return Rational(p,q);
}

istream& operator >> (istream& stream, Rational& r) { //возвращать будем ссылку на поток
    int p, q;
    if (stream >> p && stream.ignore(256, '/') && stream >> q) {
        r = { p, q };
    }
    return stream;
}
 
ostream& operator << (ostream& stream, const Rational& r) {
    stream << r.Numerator() << "/" << r.Denominator();
    return stream;
}

bool operator<(Rational a, Rational b) {
    return ((double)a.Numerator() / (double)a.Denominator()) < ((double)b.Numerator() / (double)b.Denominator());
}

bool operator>(Rational a, Rational b) {
    return ((double)a.Numerator() / (double)a.Denominator()) > ((double)b.Numerator() / (double)b.Denominator());
}

// Вставьте сюда реализацию operator / для класса Rational

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
