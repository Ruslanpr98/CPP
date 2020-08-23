#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;


int main() {
    int Q;
    map <vector<string>, int> route;
    int route_num;
    string stop; 
    cin >> Q;
    for (Q; Q > 0; Q--) {
        vector<string> v;
        cin >> route_num;
        for (auto c = 0; c < route_num; c++){
            cin >> stop;
            v.push_back(stop);
        }
        if (route.count(v)){
            cout << "Already exists for " << route[v] << endl;
        }
        else {
            route[v];
            auto new_value = route.size();
            route[v] = new_value;
            cout << "New bus " << route[v] << endl;
        }
    }
    return 0;
}
        