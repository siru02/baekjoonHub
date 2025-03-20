#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int map[101][101] = { 0 };
int board[101][101] = { 0 };

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	string str;
	for (int y = 0; y < m; y++) {
		cin >> str;
		for (int x = 0; x < n; x++) {
			map[y][x] = str[x];
			//cout << map[y][x];
		}
		//cout << "\n";
	}

	int blue = 0;
	int white = 0;
	for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
			int cnt = 1;
			if (map[y][x] == 'W' && board[y][x] == 0) {
				//W에 대한 bfs
				queue<pair<int, int>> q;
				q.push(make_pair(y, x));
				board[y][x] = 1;
				//cout << "white start: " << x << ", " << y << "\n";
				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();
					for (int i = 0; i < 4; i++) {
						int ny = cur.first + dy[i];
						int nx = cur.second + dx[i];

						if (ny >= m || nx >= n || nx < 0 || ny < 0) continue;
						if (board[ny][nx] != 0) continue;
						if (map[ny][nx] != 'W') continue;

						q.push(make_pair(ny, nx));
						board[ny][nx] = 1;
						cnt++;
					}
				}
				white += cnt * cnt;
				//cout << "white: " << white << "\n";
			}
			else if (map[y][x] == 'B' && board[y][x] == 0) {
				//B에 대한 bfs
				queue<pair<int, int>> q;
				q.push(make_pair(y, x));
				board[y][x] = 1;

				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();
					for (int i = 0; i < 4; i++) {
						int ny = cur.first + dy[i];
						int nx = cur.second + dx[i];

						if (ny >= m || nx >= n || nx < 0 || ny < 0) continue;
						if (board[ny][nx] != 0) continue;
						if (map[ny][nx] != 'B') continue;

						q.push(make_pair(ny, nx));
						board[ny][nx] = 1;
						cnt++;
					}
				}
				blue += cnt * cnt;
				//cout << "blue: " << blue << "\n";
			}
		}
	}
	cout << white << " " << blue;
}