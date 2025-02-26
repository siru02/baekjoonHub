#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); //stdio와 iostream은 다른 스트림을 사용하므로 이를 통합하여 지연시간 감소
	cin.tie(0); // 입력전 버퍼를 flush하는 작업 제거

	stack<int> st;
	int cnt;
	cin >> cnt;

	int num;

	for (int i = 0; i < cnt; i++){
		//cout << "i:" << i << "\n";
		string str;
		cin >> str;
		//cout << "[" << str << "]" << '\n';
		if (str.compare("push") == 0){
			cin >> num;
			st.push(num);
			//cout << "push: " << num << "\n";
		}
		else if (str.compare("pop") == 0){
			if (st.empty() == 0) {
				cout << st.top() << "\n";
				st.pop();
			}
			else
				cout << "-1\n";
		}
		else if (str.compare("top") == 0){
			if (st.empty() == 0)
				cout << st.top() << "\n";
			else
				cout << "-1\n";
			//cout << "top\n";
		}
		else if (str.compare("empty") == 0){
			cout << st.empty() << "\n";
			//cout << "empty\n";
		}
		else if (str.compare("size") == 0) {
			cout << st.size() << "\n";
			//cout << "size\n";
		}
	}
}