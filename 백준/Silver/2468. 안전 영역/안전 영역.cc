#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

/*
* 비가 오면 h 높이 이하의 지역은 물에 잠긴다
* 물에 잠기지 않고, 격리되어 생성되는 영역이 몇개인지 구하라
1. map에 입력받은 각 도시별 고도를 기록
2. board에 h높이 이하의 지역을 물에 잠겼다고 기록
3. board를 순회하며, 물에 잠기지 않은 지역이 있다면 큐에 넣고, bfs를 통해 방문표시
4. bfs를 1회 끝마치면 1개의 구획이 생긴것으로 판단
5. board를 순회하며 물에 잠기지 않고, 방문하지 않은 지역을 큐에 넣고 bfs순회
*/

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int map[102][102];
int visited[102][102];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	// 입력부
	int N; cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> map[i][j];
		}
	}

	int maxSpaceCnt = 1; // 0mm가 오는 경우

	// 모든 높이에 대해서 테스트를 수행해야한다
	for (int height = 1; height < 100; ++height) {
		int spaceCnt = 0;
		queue<pair<int, int>> q;

		for (int y = 1; y <= N; ++y) {
			for (int x = 1; x <= N; ++x) {
				visited[y][x] = 0;
			}
		}

		// map을 순회하면서 잠기지 않는 시작점을 찾아 bfs수행
		for (int y = 1; y <= N; ++y) {
			for (int x = 1; x <= N; ++x) {
				if (map[y][x] > height && visited[y][x] == 0) {
					visited[y][x] = 1;
					q.push(make_pair(x, y));
					spaceCnt += 1;
					while (!q.empty()) {
						pair<int, int> cur = q.front();
						q.pop();
						for (int i = 0; i < 4; ++i) {
							int nx = cur.first + dx[i];
							int ny = cur.second + dy[i];
							if (map[ny][nx] > height && visited[ny][nx] == 0) {
								visited[ny][nx] = 1;
								q.push(make_pair(nx, ny));
							}
						}
					}
				}
			}
		}
		maxSpaceCnt = maxSpaceCnt > spaceCnt ? maxSpaceCnt : spaceCnt;
	}

	cout << maxSpaceCnt;
}