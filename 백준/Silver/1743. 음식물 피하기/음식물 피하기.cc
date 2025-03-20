#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

int map[101][101] = { 0 };
int board[101][101] = { 0 };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < k; i++) {
		int x, y; cin >> y >> x;
		map[y - 1][x - 1] = 1;
	}

	/*
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cout << map[y][x] << " ";
		}
		cout << "\n";
	}
	*/
	
	int maxSize = 0;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (map[y][x] == 1) {
				queue < pair<int, int>> q;
				q.push(make_pair(y, x));
				board[y][x] = 1;
				
				int size = 1;
				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();
					for (int i = 0; i < 4; i++) {
						int ny = cur.first + dy[i];
						int nx = cur.second + dx[i];
						if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
						if (map[ny][nx] == 0) continue;
						if (board[ny][nx] == 1) continue;
						q.push(make_pair(ny, nx));
						board[ny][nx] = 1;
						size++;
					}
				}
				maxSize = maxSize > size ? maxSize : size;
			}
		}
	}
	cout << maxSize;
}