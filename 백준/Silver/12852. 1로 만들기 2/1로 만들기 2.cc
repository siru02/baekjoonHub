#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

/*
* 정수 X에 사용할 수 있는 연산
* X가 3으로 나누어 떨어지면, 3으로 나눈다
* X가 2로 나누어 떨어지면, 2로 나눈다
* 1을 뺀다
* 위 연산으로 N을 1로 만들 때 사용하는 연산 횟수의 최소값과 연산을 거치는 숫자를 출력

1. 테이블
	<i를 1로 만드는데 필요한 횟수, 이전에 사용한 연산의 방법>
2. 점화식
	
3. 초기값
*/

pair<int, int> table[3000004]; //<횟수, 방법>

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N; cin >> N;
	int num = 1;
	while (N >= num) {
		if (table[num * 3].first > table[num].first + 1 || table[num * 3].first == 0) {
			table[num * 3].first = table[num].first + 1;
			table[num * 3].second = 3;
		}
		if (table[num * 2].first > table[num].first + 1 || table[num * 2].first == 0) {
			table[num * 2].first = table[num].first + 1;
			table[num * 2].second = 2;
		}
		if (table[num + 1].first > table[num].first + 1 || table[num + 1].first == 0) {
			table[num + 1].first = table[num].first + 1;
			table[num + 1].second = 1;
		}
		++num;
	}
	cout << table[N].first << "\n";
	pair<int, int> cur;

	while (1) {
		cout << N << " ";
		cur = table[N];
		if (N == 1)
			break;
		if (cur.second == 3) {
			N /= 3;
		}
		else if (cur.second == 2) {
			N /= 2;
		}
		else if (cur.second == 1) {
			N -= 1;
		}
	}
}