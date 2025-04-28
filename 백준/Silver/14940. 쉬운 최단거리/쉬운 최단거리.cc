#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int map[1001][1001] = { 0 };
int board[1001][1001] = { 0 };

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, m, tmp;
	cin >> n >> m;

	
	queue<pair<int, int>> q;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> tmp;
			map[y][x] = tmp;
			if (tmp == 2) {
				q.push(make_pair(x, y));
				board[y][x] = 0;
			}
			else if (tmp == 0) {
				board[y][x] = 0;
			}
			else {
				board[y][x] = -1;
			}
		}
	}

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (map[ny][nx] == 0) continue;
			if (board[ny][nx] >= 0) continue;

			q.push(make_pair(nx, ny));
			board[ny][nx] = board[cur.second][cur.first] + 1;
		}
	}

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			cout << board[y][x] << " ";
		}
		cout << "\n";
	}
}