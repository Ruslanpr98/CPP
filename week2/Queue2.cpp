#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {

	int queue;
    int worried;
	vector<bool> worry_flag;
	string command;
	int i = 1;
    cin >> queue;
	while (i <= queue){
		int j;
        int N;
        int k;
		cin >> command;

		if (command == "COME"){
			cin >> N;
			k = worry_flag.size();
			worry_flag.resize(N+k);

		}

		if (command=="WORRY") {

			cin >> j;
			worry_flag[j] = true;

		}
		if (command=="QUIET"){
			cin >> j;
			worry_flag[j] = false;

		}


		if (command =="WORRY_COUNT") {
			if (worry_flag.size()==0) {
                worried=0;
            }
			int len = 0;
			for (auto a: worry_flag){
				if (a == true) {
                    len++;
                }
			}
			worried = len;
			cout << worried << endl;

		}
		//else break;
		i++;

	}

	return 0;
}