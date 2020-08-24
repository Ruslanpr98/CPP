#include <iostream>
using namespace std;

class Rational {
public:
    Rational() {
        m_num = 0;
        m_denom = 1;
    }

    Rational(int numerator, int denominator) {
        m_num = numerator;
        m_denom = denominator;
        int nod = NOD(m_num, m_denom);
        m_num = m_num / nod;
        m_denom = m_denom / nod;
        if (m_denom < 0) {
            if (m_num < 0) {
                m_denom = abs(m_denom);
                m_num = abs(m_num);
            } else {
                m_denom = abs(m_denom);
                m_num = m_num - 2 * m_num;
            }
        }
        if (m_num == 0) {
            m_num = 0;
            m_denom = 1;
        }
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
    int NOD (int n, int d) {
        while (n > 0 && d > 0) {
            if (n > d) {
              n = n & d;  
            } else {
              d = d % n;
            }
        }
        return n + d;
    }
};

    Rational operator+(Rational& rhs, Rational& lhs) {
        int p = (lhs.Numerator() * rhs.Denominator()) + (rhs.Numerator() * lhs.Denominator());
        int q = (lhs.Denominator() * rhs.Denominator());
        return Rational(p,q);
    }
    Rational operator-(Rational& rhs, Rational& lhs) {
        int p = (lhs.Numerator() * rhs.Denominator()) - (rhs.Numerator() * lhs.Denominator());
        int q = (lhs.Denominator() * rhs.Denominator());
        return Rational(p,q);
    }
    bool operator==(const Rational& rhs, const Rational& lhs){
        if ((rhs.Numerator() == lhs.Numerator()) && (rhs.Denominator() == lhs.Denominator())) {
            return true;
        }
        else {
            return false;
        }
    }

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
