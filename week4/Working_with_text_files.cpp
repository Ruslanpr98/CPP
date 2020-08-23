#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>


using namespace std;


int main() {
    ifstream input("input.txt");
    string output;
    while (getline(input, output)) {
        cout << output << endl;
    }
    
}