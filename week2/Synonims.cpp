#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <map>

using namespace std;


// auto check_word(string s, const map<string, set<string>>& m) {

// }

int main() {
    string word1, word2;
    string word_check;
    string ch_word1, ch_word2;
    map <string, set<string>> syns; 
    int Q;
    set<string> words;
    string command;
    cin >> Q;
    for (Q; Q > 0; Q--) {
        cin >> command;
        if (command == "ADD") {
            cin >> word1 >> word2;
            syns[word1].insert(word2);
            syns[word2].insert(word1);
        }
        if (command == "COUNT") {
            cin >> word_check;
            if (syns.count(word_check)) {
                cout << syns[word_check].size() << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
        if (command == "CHECK") {
            cin >> ch_word1 >> ch_word2;
            if ((syns.count(ch_word2) || syns.count(ch_word1)) && (syns[ch_word1].count(ch_word2))) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }

        }
    }
    return 0;
}