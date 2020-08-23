#include <iostream>

using namespace std;
int main(){
    string s;
    cin >> s;
    int counter = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'f') {
            counter += 1;
            
            if (counter == 2) {
                cout << i << endl;
                return 0;
            }
        }
    }
    if (counter == 1) {
                cout << -1 << endl;
                return 0;
    }
    if (counter == 0) {
                cout << -2;
                return 0;
    }
    return 0;
}