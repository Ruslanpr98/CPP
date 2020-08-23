#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>


using namespace std;


int main() {
    ifstream input("input.txt");
    string lines;
    int N; 
    int M;
    input >> N >> M; 
    input.ignore(1); 
    for (int n = N; n > 0; --n) {
        for (int m = M; m > 1; --m) {
            getline(input, lines, ',');
            cout << setw(10) << lines << " ";
        }  
        getline(input, lines);
        cout << setw(10) << lines << endl;
        
    }
    return 0;
}