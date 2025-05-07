#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

/*
* (x1, y1) ~ (x2, y2)가지의 합
1. 테이블 정의 : (0, 0)부터 (x, y)까지의 합
2. 점화식 : 
	table[y][x] = table[y - 1][x] + table[y][x - 1] - table[y - 1][x - 1] + val;
3. 초기항: table[0][0] = 0

출력부: 그림을 그려보자
*/

int table[1025][1025];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N, M; cin >> N >> M;

	int val;
	for (int y = 1; y <= N; ++y) {
		for (int x = 1; x <= N; ++x) {
			cin >> val;
			table[y][x] = table[y - 1][x] + table[y][x - 1] - table[y - 1][x - 1] + val;
		}
	}

	for (int cnt = 0; cnt < M; ++cnt) {
		int x1, x2, y1, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		int result = table[y2][x2] - table[y1 - 1][x2] - table[y2][x1 - 1] + table[y1 - 1][x1 - 1];
		cout << result << "\n";
	}

}