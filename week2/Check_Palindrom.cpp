#include <iostream>
#include <vector>

using namespace std;

bool isPalindrom(string word){
    for (auto i = 0; i < word.size()/2; ++i) {
        if (word[i] != word[word.size() - i - 1]) {
            return false;
        }
    }
    return true;
}
vector<string> PalindromFilter(vector<string> words, int minLength) {
    vector<string> filtered;
    for (auto i = 0; i < words.size(); ++i) {
        if (isPalindrom(words[i]) && words[i].size() >= minLength) {
            filtered.push_back(words[i]);
        }
    }
    return filtered;
}
