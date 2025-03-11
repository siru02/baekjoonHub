#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	bool flag = true;
	int cnt; cin >> cnt;

	for (int i = 0; i < cnt; i++) {
		stack<char> st;
		string str;	 cin >> str;
		for (char ch : str) {
			//cout << "current ch: " << ch << "\n";
			if (ch == '(')
				st.push(ch);
			else if (st.empty() == false) {
				st.pop();
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag && st.empty() == true)
			cout << "YES\n";
		else
			cout << "NO\n";
		flag = true;
	}
}