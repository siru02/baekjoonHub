#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <sstream>
using namespace std;

void parsing(deque<int>& dq) {
	string input, num; cin >> input;
	int len = input.length();

	if (len <= 2) return;
	input = input.substr(1, len - 2); //길이보다 2개 짧게 잘라서 양 끝의 []제거

	stringstream ss(input);
	while (getline(ss, num, ','))
		dq.push_back(stoi(num));
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	//D는 첫 번째 수를 버리기, 비어있는데 D쓰면 에러
	//R은 배열의 수의 순서를 뒤집기

	int T; cin >> T;
	bool error = false;
	for (int i = 0; i < T; i++) {
		string P; cin >> P;
		int len; cin >> len;
		deque<int> dq;
		parsing(dq);

		bool flag = true; // true이면 정방향

		// RDD처리
		for (char ch : P) {
			if (ch == 'R')
				flag = !flag;
			else if (dq.empty()) {
				cout << "error\n";
				error = true;
				break;
			}
			else if (flag == true) {
				dq.pop_front();
			}
			else if (flag == false) {
				dq.pop_back();
			}
		}

		//에러처리
		if (error) {
			error = false;
			continue;
		}

		cout << "[";
		if (flag) {
			for (size_t i = 0; i < dq.size(); i++) {
				cout << dq[i];
				if (i < dq.size() - 1) cout << ",";
			}
		}
		else {
			for (size_t i = dq.size(); i > 0; i--) {
				cout << dq[i - 1];
				if (i > 1) cout << ",";
			}
		}
		cout << "]\n";
	}
}