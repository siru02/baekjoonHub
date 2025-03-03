#include <iostream>
#include <stack>
#include <algorithm>
#pragma once(disable:4996)

using namespace std;

stack<int> st;

int main() 
{
	cin.tie(0); //입출력 스트림동기화 분리
	ios::sync_with_stdio(0); // stdio와 iostream입출력 스트림하나로 통일

	int n, num = 2;
	st.push(1); //1이상을 입력받으므로 1은 항상 입력되어있다고 가정
	string str = "+\n";

	cin >> n;

	//초기 스택은 비어있다
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;

		if (st.empty() == true && num <= n) {
			st.push(num++); //스택에 넣는 숫자는 오름차순으로 올라가므로
			str += "+\n";
		}
		while (st.top() != input && num <= n) { //여기서 에러
			st.push(num++); //스택에 넣는 숫자는 오름차순으로 올라가므로
			str += "+\n";
		}
		if (st.top() == input) { //위 while문에서 순회를 돌며 push하는 동작은 num <= n까지
			st.pop();
			str += "-\n";
		}
		else { //input과 일치하는 값이 스택의 top에 있지 않으면 올바르지 않음
			cout << "NO";
			return 0;
		}
	}
	cout << str;
}