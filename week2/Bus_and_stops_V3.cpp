#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <string>

using namespace std;



int main() {
    int Q;
    map <set<string>, int> stops;
    string stop;
    int num;
    cin >> Q;
    for (Q; Q > 0; Q--) {
        set<string> stop_set;
        cin >> num;
        for (auto c = 0; c < num; ++c) {
            cin >> stop;
            stop_set.insert(stop);
        }
        if (stops.count(stop_set)) {
            cout << "Already exists for " << stops[stop_set] << endl;
        }
        else {
            stops[stop_set];
            auto new_value = stops.size();
            stops[stop_set] = new_value;
            cout << "New bus " << stops[stop_set] << endl;
        }
    }
    return 0;
}