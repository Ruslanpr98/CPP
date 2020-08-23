#include <iostream> 
#include <string>
#include <algorithm>


using namespace std;



struct Specialization {
    string spec;
    explicit Specialization(string new_spec) {
        spec = new_spec;
    }
};


struct Course {
    string course;
    explicit Course(string new_course) {
        course = new_course;
    }
};

struct Week {
    string week;
    explicit Week(string new_week) {
        week = new_week;
    }

};

struct LectureTitle {
  string specialization;
  string course;
  string week;
  LectureTitle(Specialization s, Course c, Week w) {
      specialization = s.spec;
      course = c.course;
      week = w.week;
  }
};

int main() {
    LectureTitle title(Specialization("C++"), Course("White belt"), Week("4th"));
}

