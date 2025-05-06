#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

/*
1. 배추가 심어진 장소를 map에 체크
2. map을 순회하며 배추가 심어진 장소가 있으면 bfs를 수행 -> 단 이미 체크한 장소라면 board에 체크하여 제외
*/

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int map[51][51];
int board[51][51];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int t; cin >> t;

	for (int cnt = 0; cnt < t; ++cnt) {
		int m, n, k; cin >> m >> n >> k; //가로, 세로, 배추 심어진 위치의 개수
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				map[i][j] = 0;
				board[i][j] = 0;
			}
		}
		int x, y;
		int wormCnt = 0;
		for (int i = 0; i < k; ++i) {
			cin >> x >> y;
			map[y][x] = 1;
		}
		
		//bfs
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (map[i][j] != 1 || board[i][j] != 0) continue; //배추가 아니거나, 체크한 배추면 제외
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				board[i][j] = 1;
				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();
					for (int k = 0; k < 4; ++k) {
						int ny = cur.first + dy[k];
						int nx = cur.second + dx[k];
						if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
						if (map[ny][nx] != 1 || board[ny][nx] != 0) continue;
						board[ny][nx] = 1;
						q.push(make_pair(ny, nx));
					}
				}
				++wormCnt;
			}
		}
		cout << wormCnt << "\n";
	}
}