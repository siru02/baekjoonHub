#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

/*
1. 테이블 설정
	n일까지 일을 했을 때 벌 수 있는 최대 금액
2. 점화식
	An = max{A1 ~ A(n-1) + P[i]}
	// 각 날별 최대 금액에 하루의 금액만 더해보면 된다
	// 이유는 일을 여러번 더 할 수 있는 경우였다면 뒤의 A(i)의 경우에 포함될 것이기 때문
3. 초기값 설정
	table[1] = 0
*/

int table[1500002]; // n일까지 일해서 벌 수 있는 최대 금액
int P[1500002]; // i일의 보수
int T[1500002]; // i일의 일을 수행하는데 걸리는 기간

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N;	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> T[i] >> P[i];
	}

	table[0] = 0;

	for (int i = 1; i <= N; ++i) {
		// 오늘까지 최대 수익을 다음날에도 이어갈 수 있도록 유지
		table[i] = max(table[i], table[i - 1]);

		int endDay = i + T[i] - 1;
		if (endDay <= N) {
			table[endDay] = max(table[endDay], table[i - 1] + P[i]);
		}
	}
	cout << *max_element(table, table + N + 1);
}