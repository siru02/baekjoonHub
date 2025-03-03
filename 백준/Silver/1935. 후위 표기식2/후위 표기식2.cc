#include <iostream>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include <deque>
#include <map>

using namespace std;
stack<double> st;

double calculate(char ch) {
	double num1 = st.top();
	st.pop();
	double num2 = st.top();
	st.pop();
	if (ch == '+')
		return num1 + num2;
	else if (ch == '-')
		return num2 - num1;
	else if (ch == '*')
		return num1 * num2;
	else if (ch == '/')
		return num2 / num1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	map<char, double> matchMap; // <알파벳, 실제 값> 꼴로 저장되는 map자료형

	string str;
	int cnt;
	double input;

	cin >> cnt;
	cin >> str; // ABC*+DE/- 와 같은 문자열

	//cout << "str: " << str << "\n";
	for (int i = 0; i < cnt; i++) {
		cin >> input;
		matchMap['A' + i] = input; //map자료형은 map[key] = value로 초기화
		//cout << "matchMap[" << 'A' + i << "]: " << matchMap['A' + i] << "\n";
	}

	// 우선순위는 알파벳 < 덧셈 뺄셈 < 곱셈 나눗셈
	for (int ch : str) {
		if (ch >= 'A' && ch <= 'Z') { //알파벳이라면
			st.push(matchMap[ch]);
			//cout << "push " << matchMap[ch] << "\n";
		}
		else
			st.push(calculate(ch));
		//cout << "ch: " << ch << ", top: " << st.top() << "\n";
	}
	cout << fixed;
	cout.precision(2);
	cout << st.top();
	return 0;
}