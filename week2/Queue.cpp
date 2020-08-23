#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int command_count;
    string command;
    int N;
    int i = 0;
    int j;
    int queue;
    vector<bool> worried;
    int worry;
    int n;
    int count_worry;
    cin >> command_count;
    while (i <= command_count) {
    cin >> command;
    if (command == "COME") {
        cin >> N;
        n = worried.size();
        worried.resize(N+n);
    }
    if (command == "WORRY") {
        cin >> j;
        worried[j] = true;
    }
    if (command == "QUIET") {
        cin >> j;
        worried[j] = false;
    }
    if (command == "WORRY_COUNT") {
        if (worried.size() == 0) {
            worry = 0;
        }
        for (auto a: worried) {
            if (a == true) {
                count_worry++;
            }
        }
        worry = count_worry;
        cout << worry << endl;
    }
    i++;
    }   
}
