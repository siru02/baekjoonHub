#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
  	cin.tie(0);

	list<char> editor;
	string str;
	getline(cin, str);
	int cmdCnt;
	cin >> cmdCnt;

	for (char tmp : str) {
		editor.push_back(tmp);
	}
	list<char>::iterator cursor = editor.end();
	
	char ch;
	for (int i = 0; i < cmdCnt; i++) {
		cin >> ch;
		if (ch == 'L'){
			if (editor.begin() != cursor) //현재커서가 첫번째 원소를 가리키지 않으면
				--cursor;
		}
		else if (ch == 'D') {
			if (editor.end() != cursor) //현재커서가 마지막 원소를 가리키지 않으면
				++cursor;
		}
		else if (ch == 'B') {
			if (editor.begin() != cursor) //현재커서가 첫번째 원소를 가리키고 있지않으면
				cursor = editor.erase(--cursor); //리스트의 왼쪽의 원소를 삭제
		}
		else if (ch == 'P') {
			cin >> ch;
			editor.insert(cursor, ch); //현재 이터레이터 위치에 삽입
		}
	}
	for (char tmp: editor)
		cout << tmp;
}