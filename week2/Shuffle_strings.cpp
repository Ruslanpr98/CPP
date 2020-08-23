#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> MoveStrings(vector<string>& source, vector<string>& destination) {
    for (auto i = 0; i < source.size(); ++i) {
        destination.push_back(source[i]);
    }
    source.clear();
    return destination;
}
// int main(){
//     vector<string> source = {"a","b","c"};
//     vector<string> destination = {"d"};
//     MoveStrings(source,destination);
//     for (auto i = 0; i <= destination.size(); ++i) {
//         cout << "Hello" << endl;
//     }
//     return 0;
// }