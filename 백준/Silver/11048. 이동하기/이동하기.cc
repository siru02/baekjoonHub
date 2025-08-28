#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

/*
* dp: 테이블 설정 -> 점화식 세우기 -> 초기값 찾기
*/

int N, M; // (x, y) 왼쪽 위가 (1,1), 오른쪽 아래가 (N, M)
int dx[3] = { 1, 0, 1 };
int dy[3] = { 0, 1, 1 };
int map[1002][1002];
int table[1002][1002];

int main() 
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M;
	for (int r = 1; r <= N; ++r) {
		for (int c = 1; c <= M; ++c) {
			cin >> map[r][c];
		}
	}

	// (1, 1)에서 (N, M)으로 이동할 때, 가져올 수 있는 사탕 개수의 최대를 출력
	// 1. 백트래킹(dfs), 2. dp: 각 좌표마다 최대로 얻을 수 있는 사탕의 개수를 저장
	/*
	* dp: table[r][c] = map[r][c] + max{(r-1,c), (r, c-1), (r-1, c-1)}
	*/
	table[1][1] = map[1][1];
	for (int r = 1; r <= N; ++r) {
		for (int c = 1; c <= M; ++c) {
			if (table[r + 1][c] < table[r][c] + map[r + 1][c]) {
				table[r + 1][c] = table[r][c] + map[r + 1][c];
			}
			if (table[r][c + 1] < table[r][c] + map[r][c + 1]) {
				table[r][c + 1] = table[r][c] + map[r][c + 1];
			}
			if (table[r + 1][c + 1] < table[r][c] + map[r + 1][c + 1]) {
				table[r + 1][c + 1] = table[r][c] + map[r + 1][c + 1];
			}
		}
	}
	cout << table[N][M];
}