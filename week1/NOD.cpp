#include <iostream>

using namespace std;

int main(){
    int A;
    int B;
    cin >> A;
    cin >> B;
    while (A > 0 && B > 0) {
        if (A > B) {
            A = A % B;
        }
        else {
            B = B % A;
        }
    }
    cout << A + B;
}