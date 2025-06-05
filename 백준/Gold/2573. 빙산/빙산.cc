#include <iostream>
#include <queue>
#include <utility>
#include <stack>
#include <algorithm>

using namespace std;
/*
* 빙산을 map[y][x]에 높이로 표현
* 바다와 접해있는 칸 1개마다 높이가 1씩 줄어든다
* 빙산이 2개의 덩어리로 나뉘어지는데 걸리는 최소 시간출력, 나뉘지 않으면 0 출력
1. map전체를 순회하며 빙산에 위치하면 접한 바다개수만큼 높이를 낮춘다
2. map전체를 순회하며 빙산이 있으면 큐에 넣고 bfs수행, visited에 방문표기를 한다
3. 2와 같은 루프에서 남은 map을 순회하는데 방문하지 않은 빙산이 발견되면, 2개이상으로 쪼개진 것이므로 종료
*/

int map[302][302];
int seaCnt[302][302];
int visited[302][302];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	// 입력부
	int N, M; cin >> N >> M;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> map[y][x];
		}
	}

	int time = 0;
	while (1) {
		++time;
		// 인접한 바다 개수 구하기
		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < M; ++x) {
				if (map[y][x] != 0) {
					seaCnt[y][x] = 0;
					for (int i = 0; i < 4; ++i) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue; // 범위조건 체크
						if (map[ny][nx] == 0)
							++seaCnt[y][x];
					}
				}
			}
		}

		// 빙하 녹이기
		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < M; ++x) {
				visited[y][x] = 0;
				map[y][x] -= seaCnt[y][x];
				if (map[y][x] < 0)
					map[y][x] = 0;
			}
		}

		// bfs로 분리된 빙하 count
		int cnt = 0;
		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < M; ++x) {
				if (map[y][x] > 0 && visited[y][x] == 0) { //방문하지 않은 빙산이라면
					++cnt;
					queue<pair<int, int>> q;
					q.push(make_pair(x, y));
					visited[y][x] = 1;
					while (!q.empty()) {
						pair<int, int> cur = q.front();
						q.pop();
						for (int i = 0; i < 4; ++i) {
							int nx = cur.first + dx[i];
							int ny = cur.second + dy[i];

							if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue; //범위체크
							if (map[ny][nx] == 0) continue; // 빙산이 아니라면 패스
							if (visited[ny][nx] == 1) continue; //방문한곳이면 패스
							q.push(make_pair(nx, ny));
							visited[ny][nx] = 1;
						}
					}
				}
			}
		}

		/*//test output
		cout << "map\n";
		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < M; ++x) {
				cout << map[y][x] << " ";
			}
			cout << "\n";
		}
		cout << "visited\n";
		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < M; ++x) {
				cout << visited[y][x] << " ";
			}
			cout << "\n";
		}*/

		if (cnt >= 2) {
			cout << time;// << "cnt: " << cnt;
			break;
		}
		else if (cnt == 0) {
			cout << 0;
			break;
		}
	}
}