#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/*
람다식으로 표현하여 x좌표 우선으로 정렬하되, y좌표도 고민
람다식에서 true를 리턴한다는건 순서가 이미 올바르다는 의미
*/

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	string A, B, C;
	cin >> A >> B >> C;

	int a, b, c;
	a = stoi(A);
	b = stoi(B);
	c = stoi(C);
	int num = a + b - c;
	cout << num << "\n" << stoi(A + B) - stoi(C);
}