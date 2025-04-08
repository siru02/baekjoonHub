#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
팩토리얼에서 0의 개수를 세는건 10의 배수임을 확인하는것
10 = 2 x 5이므로 5의 개수를 센다
*/

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 5; i <= n; i *= 5) {
		cnt += n / i;
	}
	cout << cnt;
}