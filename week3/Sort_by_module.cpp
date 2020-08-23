#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main() {
    int N;
    int digits;
    vector<int> nums;
    vector<int> sorted_nums;
    cin >> N;
    for (auto i = 0; i < N; i++) {
        cin >> digits;
        nums.push_back(digits);
    }
    sort(begin(nums), end(nums), [](const int& a, const int& b) {
        return (abs(a) < abs(b));
    });
    for (auto& i: nums) {
        cout << i << " ";
    }
}