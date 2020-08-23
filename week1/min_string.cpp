#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string a;
    string b;
    string c;
    cin >> a;
    cin >> b;
    cin >> c;
    string min;
    if (a <= b && a <= c) {
        min = a;
    }
    else if (b <= a && b <= c) {
        min = b;
    }
    else {
        min = c;
    }
    cout << min; 
    return 0;
}
   