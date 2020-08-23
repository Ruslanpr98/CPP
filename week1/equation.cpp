#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double a;
    double b;
    double c;
    double x1,x2;
    cin >> a >> b >> c;
    double D = pow(b,2) - 4 *a*c;
    if (a == 0 && b == 0) {
        return 0;
    }
    if (a == 0) {
        x1 = -c/b;
        cout << x1;
        return 0;
    }
    if (b == 0) {
        if ((-c/a) > 0) {
            x1 = -sqrt(-(c/a));
            x2 = sqrt(-(c/a));
            cout << x1 << " " << x2;
            return 0;
        }
        
    }
    if (c == 0) {
        x1 = 0;
        x2 = -b/a;
        cout << x1 << " " << x2;
        return 0;
    }
    if (D > 0) {
        x1 = (-b + sqrt(D))/(2*a);
        x2 = (-b - sqrt(D))/(2*a);
        cout << x1 << " " <<  x2;
        return 0;
    }
    if (D == 0) {
        x1 = -b/(2*a);
        x2 = x1;
        cout << x1;
        return 0;
    }
    if (D < 0) {
        return 0;
    }
    return 0;  
}