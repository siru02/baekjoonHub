#include <iostream>
#include <string>
#include <utility>
#include <queue>
#include <algorithm>
#include <array>

using namespace std;

int board[101][101][101] = { 0 };
int map[101][101][101] = { 0 };

int dx[6] = { 1, 0, 0, -1, 0, 0 };
int dy[6] = { 0, 1, 0, 0, 0, -1 };
int dz[6] = { 0, 0, 1, 0, -1, 0 };

queue<array<int, 3>> q; // q에는 현재 (z, y, x)좌표를 넣어야한다

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n, h, tmp, tomatoFullCnt, tomatoCnt = 0, date = 1;
	cin >> m >> n >> h; // x y z
	tomatoFullCnt = m * n * h;
	for (int z = 0; z < h; z++) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				cin >> tmp;
				board[z][y][x] = tmp;
				if (tmp == -1)
					tomatoFullCnt--;
				else if (tmp == 1)
					tomatoCnt++;
			}
		}
	}
	
	//cout << "board\n";
	for (int z = 0; z < h; z++) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				if (board[z][y][x] == 1) {
					array<int, 3> cur = { z, y, x }; //시작점을 발견하면 array 형을 이용해 동적으로 변수 생성
					q.push(cur); // cur에 값을 넣는다
					map[z][y][x] = 1; //첫날이므로 1로 기입한다
				}
				//cout << board[z][y][x] << " ";
			}
			//cout << "\n";
		}
	}

	while (!q.empty()) {
		array<int, 3> cur = q.front();
		q.pop();
		
		//cout << "cur: " << cur[2] << ", " << cur[1] << ", " << cur[0] << "\n";

		for (int i = 0; i < 6; i++) {
			int nz = cur[0] + dz[i];
			int ny = cur[1] + dy[i];
			int nx = cur[2] + dx[i];

			if (nz < 0 || ny < 0 || nx < 0 || nz >= h || ny >= n || nx >= m) continue; // 맵 범위 밖이면 continue;
			if (board[nz][ny][nx] == -1) continue; // 토마토가 들어있지 않은 칸이면 큐에 넣지 않는다
			if (map[nz][ny][nx] != 0) continue; // 이미 토마토가 익은 지점이라면 큐에 넣지 않는다

			array<int, 3> temp = { nz, ny, nx };
			q.push(temp);
			tomatoCnt++;
			map[nz][ny][nx] = map[cur[0]][cur[1]][cur[2]] + 1; //이전 좌표의 값 + 1로 칠하여 큐에 넣는다
			if (map[nz][ny][nx] > date)
				date = map[nz][ny][nx];
		}
	}
	//cout << tomatoCnt << " vs " << tomatoFullCnt << "\n";
	if (tomatoCnt == tomatoFullCnt) {
		cout << date - 1;
	}
	else
		cout << -1;
}