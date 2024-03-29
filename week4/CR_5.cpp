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

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
