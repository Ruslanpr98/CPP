#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string to_low(string s) {
    string result;
    for (auto i: s) {
        result += tolower(i); 
    }
    return result;
}
int main() {
    int N;
    string s;
    vector<string> nums;
    cin >> N;
    for (auto i = 0; i < N; i++) {
        cin >> s;
        nums.push_back(s);
    }
    sort(begin(nums), end(nums), [](string& a, string& b) {
        return (to_low(a) < to_low(b));
    });
    for (auto& i: nums) {
        cout << i << " ";
    }
}