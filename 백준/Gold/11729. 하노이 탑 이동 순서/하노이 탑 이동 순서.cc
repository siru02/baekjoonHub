#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

// 원판 n개를 a번 기둥에서 b번 기둥으로 옮기는 방법을 출력하는 함수
void recursive(int a, int b, int n)
{
	if (n == 1) {
		cout << a << " " << b << "\n";
		return;
	}

	int c = 6 - a - b;

	recursive(a, c, n - 1); //n-1개를 a에서 c로 옮기고
	cout << a << " " << b << "\n"; // n번째를 b로 옮긴다
	recursive(c, b, n - 1); // n-1개를 c에서 b로 옮긴다
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	cout << (1 << n) - 1 << "\n";
	recursive(1, 3, n);
}