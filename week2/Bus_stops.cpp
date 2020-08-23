#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
 
void Show_all(const map<string, vector<string>>& m) { 
    if (m.size() == 0) cout << "No buses" << endl; 
    else { 
        for (const auto& i : m) { 
            cout << "Bus " << i.first << ":"; 
            for (const auto& d : i.second) { 
                cout << " " << d; 
            }
            cout << endl;
        }
    }
}
void Bus_for_Stop(const string& s, const map<string, vector<string>>& b, const vector<string>& busm) { 
    int k = 0; 
    vector<string> v;
    for (const auto& i : b) { 
        for (const auto& n : i.second) { 
            if (n == s) {  
                v.push_back(i.first); 
                k++; 
            }
        }
    }
    if (k > 0) { 
        for (const auto& w : busm) { 
            for (auto z : v) { 
                if (z == w) { 
                    cout << w << " "; 
                } 
            }
        }
    }
    else if (k == 0) cout << "No stop"; 
    cout << endl;
}
void Stop_for_bus(const string& s, const map<string, vector<string>>& b, const vector<string>& busm) {
    int l = 0; 
    for (auto i : b) { 
        if (i.first == s) { 
            for (auto m : i.second) { 
                cout << "Stop " << m << ":"; 
                int l2 = 0; 
                vector<string> v;
                for (auto r : b) { 
                    for (auto n : r.second) { 
                        
                        if (n == m && r.first != s) {
                            v.push_back(r.first); 
                            l2++;
                        }
                    }
                }
                if (l2 == 0) cout << " no interchange";
                else if (l2 > 0) {
                    for (const auto& w : busm) { 
                        for (auto z : v) {
                            if (z == w) { 
                                cout << " "  << w; 
                            } 
                        }
                    }
                }
                cout << endl; 
            }
            l++; 
        }
    }
    if (l == 0) cout << "No bus" << endl; 
}
int main()
{
    int Q;
    cin >> Q; 
    string comand, bus, stop;
    map<string, vector<string>> bsmap; 
    vector<string> busm;
    int stop_count;
    for (auto k = 0; k < Q; ++k) { 
        cin >> comand; 
        if (comand == "NEW_BUS") { 
            cin >> bus >> stop_count; 
            busm.push_back(bus);
            for (stop_count; stop_count > 0; stop_count--) { 
                cin >> stop; 
                bsmap[bus].push_back(stop); 
            }
        }
        else if (comand == "BUSES_FOR_STOP") {
            cin >> stop;
            Bus_for_Stop(stop, bsmap, busm); 
        }
        else if (comand == "STOPS_FOR_BUS") {
            cin >> bus;
            Stop_for_bus(bus, bsmap, busm);
        }
        else if (comand == "ALL_BUSES") {
            Show_all(bsmap);
        }
    }
    return 0;
}
