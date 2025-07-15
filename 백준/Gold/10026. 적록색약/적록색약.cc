#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

/*
* 같은 색상이 상하좌우로 인접한 경우, 색상의 차이를 느끼지 못하는 경우는 같은 색상취급
* 적록색약은 R과 G가 같은 구역, 일반인은 구분 됨
*/

char map[102][102];
int visited[102][102];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0,-1, 0 };

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N; cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			char ch;
			cin >> ch;
			map[i][j] = ch;
		}
	}

	queue<pair<int, int>> q;
	int areaCnt = 0;

	// 일반인
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			if (visited[y][x] != 0)
				continue;

			q.push(make_pair(x, y));
			visited[y][x] = 1;
			++areaCnt;
			while (!q.empty()) {
				pair<int, int> cur = q.front();
				q.pop();
				for (int i = 0; i < 4; ++i) {
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];
					if (nx >= N || ny >= N || nx < 0 || ny < 0) continue; // 범위밖제외
					if (visited[ny][nx] == 1) continue; // 방문한 장소 제외
					if (map[cur.second][cur.first] != map[ny][nx]) continue; // 다른장소 제외
					q.push(make_pair(nx, ny));
					visited[ny][nx] = 1;
				}
			}
		}
	}
	cout << areaCnt << " ";

	// 적록색약
	areaCnt = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			visited[i][j] = 0;
			if (map[i][j] == 'G')
				map[i][j] = 'R';
		}
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			if (visited[y][x] != 0)
				continue;

			q.push(make_pair(x, y));
			visited[y][x] = 1;
			++areaCnt;
			while (!q.empty()) {
				pair<int, int> cur = q.front();
				q.pop();
				for (int i = 0; i < 4; ++i) {
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];
					if (nx >= N || ny >= N || nx < 0 || ny < 0) continue; // 범위밖제외
					if (visited[ny][nx] == 1) continue; // 방문한 장소 제외
					if (map[cur.second][cur.first] != map[ny][nx]) continue; // 다른장소 제외
					q.push(make_pair(nx, ny));
					visited[ny][nx] = 1;
				}
			}
		}
	}
	cout << areaCnt;
}