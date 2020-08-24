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

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}
