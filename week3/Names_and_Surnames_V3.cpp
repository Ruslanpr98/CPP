#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

using namespace std;
struct Name_Surname {
  string Name;
  string Surname;
};

class Person {
public:
  Person(const string& first_name, const string& last_name, int year) {
    YNS[year] = {first_name, last_name};
    birth_year = year;
  }
  void ChangeFirstName(int year, const string& first_name) {
    if (YNS.count(year) == 0) {
      YNS[year].Surname = "";
    }
    YNS[year].Name = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    if (YNS.count(year) == 0) {
      YNS[year].Name = "";
    }
    YNS[year].Surname = last_name;
  }
  string GetFullName(int year) const {
    if (birth_year != 0 && year < birth_year) return "No person";
    for (const auto& i : YNS) {
        if (year < i.first) return "Incognito"; 
        break; 
    }
    string name = "";
    string surname = "";
        for (auto& i : YNS) {      
            if (i.first <= year && i.second.Surname != "") {
              surname = i.second.Surname;
            }
            if (i.first <= year && i.second.Name != "") {
              name = i.second.Name;
            }
        }
        if (name == "") {
          return surname + " with unknown first name"; 
        }
        else if (surname == "") {
          return name + " with unknown last name"; 
        }
        return name + " " + surname; 
  }
  string GetFullNameWithHistory(int year) const {
    if (birth_year != 0 && year < birth_year) return "No person";
    for (const auto& i : YNS) {
        if (year < i.first) return "Incognito"; 
        break; 
    }
    string Surnames, Names = "";
    string reversed_Surnames, reversed_Names = "";
    vector<string> Surnames_vector;
    vector<string> Names_vector;
    for (const auto& i: YNS) {
      if (i.first <= year && i.second.Surname != "") {
        if (i.second.Surname != Surnames && Surnames != "") {
          Surnames_vector.push_back(Surnames);
        }
        Surnames = i.second.Surname;
      }
      if (i.first <= year && i.second.Name != "") {
        if (i.second.Name != Names && Names != "") {
          Names_vector.push_back(Names);
        }
        Names = i.second.Name;
      }
    }
    if (Surnames_vector.size() > 0) { 
            reversed_Surnames += " (" + Surnames_vector[Surnames_vector.size() - 1]; 
            if (Surnames_vector.size() > 1) {
                for (int i = Surnames_vector.size() - 1; i > 0; --i) {
                    reversed_Surnames += ", " + Surnames_vector[i - 1]; 
                }
            }
            reversed_Surnames += ")"; 
        }
        
        if (Names_vector.size() > 0) {
            reversed_Names += " (" + Names_vector[Names_vector.size() - 1];
            if (Names_vector.size() >1) {
                for (int i = Names_vector.size() - 1; i > 0; --i) {
                    reversed_Names += ", " + Names_vector[i - 1];
                }
            }
            reversed_Names += ")";
        }
        if (Names == "") return Surnames + reversed_Surnames + " with unknown first name";
        else if (Surnames == "") return Names + reversed_Names + " with unknown last name";
        else return Names + reversed_Names + " " + Surnames + reversed_Surnames;

  }
private:
  //int m_year;
  int birth_year;
  map<int, Name_Surname> YNS;
};


int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
