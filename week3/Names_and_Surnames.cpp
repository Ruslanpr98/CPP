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
  string GetFullName(int year) {
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
  string GetFullNameWithHistory(int year) {
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
    reverse(Surnames_vector.begin(), Surnames_vector.end());
    reverse(Names_vector.begin(), Names_vector.end());
    for (auto& i : Surnames_vector) {
      reversed_Surnames += i;
    }
  }
private:
  //int m_year;
  map<int, Name_Surname> YNS;
};


int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  return 0;
}