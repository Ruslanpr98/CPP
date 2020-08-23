#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int num = 0; 
    //int bin = 0;
    //int r = 1;
    vector<int> binary;
    cin >> num; 
    while(num)
    {
        binary.push_back(num%2);
        num = num/2;
        //r = r*10;
    }
    while (!binary.empty() && binary[binary.size() - 1] == 0) {
        binary.pop_back();
    }
    reverse(binary.begin(),binary.end());
    for (auto i = binary.begin(); i != binary.end(); i++) {
        cout << *i;
    }
    return 0;
}
    
