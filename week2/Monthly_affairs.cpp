#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    int Q;
    vector<int> days_in_month = {31,28,31,30,31,30,31,31,30,31,30,31};
    vector<vector<string>> task_for_day;
    int index_of_month = 0;
    task_for_day.resize(days_in_month[index_of_month], {});
    
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        string command;
        string task;
        int day;
        cin >> command;
        if (command == "ADD") {
            cin >> day >> task;
            task_for_day[day - 1].push_back(task);
        }
        if (command == "DUMP") {
            cin >> day;
            cout << task_for_day[day - 1].size();
            for (auto i: task_for_day[day - 1]) {
                cout << " " << i;
            }
            cout << endl;
        }
        if (command == "NEXT") {
            
            index_of_month++;
            if (index_of_month > 11) {
                index_of_month = 0;
            }
            vector<vector<string>> next_month_task_for_day = task_for_day;
            int len_task_for_day = task_for_day.size();
            int new_len_task_for_day = days_in_month[index_of_month];
            task_for_day.resize(new_len_task_for_day);
            const int last_day = new_len_task_for_day - 1;
            if (len_task_for_day > new_len_task_for_day) {
                for (new_len_task_for_day; len_task_for_day > new_len_task_for_day; new_len_task_for_day++) {
                    task_for_day[last_day].insert(end(task_for_day[last_day]), begin(next_month_task_for_day[new_len_task_for_day]), end(next_month_task_for_day[new_len_task_for_day]));
                }
            }
            next_month_task_for_day.clear();
        }
    }
}
