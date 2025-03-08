#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

deque<int> dq;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int cnt, input;

	cin >> cnt;
	string str;
	for (int i = 0; i < cnt; i++) {
		cin >> str;
		if (str == "push_back") {
			cin >> input;
			dq.push_back(input);
		}
		else if (str == "push_front") {
			cin >> input;
			dq.push_front(input);
		}
		else if (str == "front") {
			if (dq.empty())
				cout << -1 << "\n";
			else
				cout << dq.front() << "\n";
		}
		else if (str == "back") {
			if (dq.empty())
				cout << -1 << "\n";
			else
				cout << dq.back() << "\n";
		}
		else if (str == "size") {
			cout << dq.size() << "\n";
		}
		else if (str == "pop_front") {
			if (dq.empty())
				cout << -1 << "\n";
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (str == "pop_back") {
			if (dq.empty())
				cout << -1 << "\n";
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		else if (str == "empty") {
			cout << dq.empty() << "\n";
		}
	}
}