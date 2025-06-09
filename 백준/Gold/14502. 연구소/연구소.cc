//bfs
/*
 * 큐(queue)를 생성한다.
 * 시작 좌표(또는 노드)를 큐에 넣고, 방문 표시를 한다.
 * 큐가 빌 때까지 다음을 반복한다:
 *   - 큐의 front에서 원소를 pop한다.
 *   - 현재 위치를 기준으로 인접한 탐색 가능한 지점들을 확인한다.
 *   - 아직 방문하지 않은 지점을 큐에 넣고, 방문 표시를 한다.
 * BFS에서는 큐에 넣는 시점에 방문했다고 간주한다.
 */
// dfs
/*
 * 스택(stack)을 생성한다.
 * 시작 좌표(또는 노드)를 스택에 넣고, 방문 표시를 한다.
 * 스택이 빌 때까지 다음을 반복한다:
 *   - 스택의 top 원소를 pop한다.
 *   - 현재 위치를 기준으로 인접한 지점들을 확인한다.
 *   - 인접한 지점 중 방문하지 않은 지점이 있다면 스택에 넣고, 방문 표시를 한다.
 * DFS는 스택을 통해 한 방향으로 깊게 들어간 후, 더 이상 갈 곳이 없으면 되돌아온다.
 */

#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;
/*
* 연구소에서 바이러스가 유출되어, 확산을 막기위해 벽을 세우려고 한다
* 연구소는 빈 칸, 벽으로 이루어져 있다
* 바이러스는 상하좌우로 인접한 빈 칸으로 퍼져나갈 수 있다
* 새로 세울 수 있는 벽의 개수는3개이며, 꼭 3개를 세워야한다
* 0은 빈칸, 1은 벽, 2는 바이러스
* 벽 3개를 세운 뒤, 바이러스가 퍼질 수 없는 곳을 안전영역이라고 한다
* 안전영역의 최대를 구하는 프로그램을 구하라
*/
/*
* bfs를 사용한다 -> 바이러스는 같은 시점에 동시에 퍼져나가므로
* 빈 칸중에서 3개를 선정하여 벽을 세우고, bfs를 수행하여 안전영역을 구한다
* 벽을 세울 3개의 위치를 어떻게 순회할지가 관건
*/

int lab[10][10]; //연구실
int visited[10][10]; //각 bfs에서 바이러스가 퍼졌는지 확인하기 위한 변수
vector<pair<int, int>> emptyArea; // 초기 빈 영역들을 저장
vector<pair<int, int>> virusArea; // 초기 바이러스 영역을 저장
pair<int, int> wall[3];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int N, M;

// 현재 wall기준으로 bfs를 수행하여 safeArea의 사이즈를 구한다
int calSafeAreaSize() {
	// 초기세팅
	for (int y = 0; y < 10; ++y) {
		for (int x = 0; x < 10; ++x)
			visited[y][x] = 0; // 바이러스가 퍼진것을 기록할 변수
	}
	for (int i = 0; i < 3; ++i) {
		int x = wall[i].first;
		int y = wall[i].second;
		lab[y][x] = 1; //벽으로 설정
	}

	// bfs
	queue<pair<int, int>> q;
	for (auto start : virusArea) {
		q.push(start);
		visited[start.second][start.first] = 1;
	}

	while (!q.empty()) {
		pair<int, int> cur;
		cur = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i]; 
			if (nx < 1 || nx > M || ny < 1 || ny > N) continue; //범위체크
			if (lab[ny][nx] != 0) continue; // 빈 공간인지 체크
			if (visited[ny][nx] != 0) continue; //lab에 바이러스가 퍼진걸 직접 마킹할 수 없으므로 visited에 방문표기로 확인
			q.push(make_pair(nx, ny));
			visited[ny][nx] = 1; //방문표기를 해야, 빈 공간에 바이러스가 퍼졌음을 알 수있음
		}
		
	}

	// lab 순회하면서 safeArea측정
	int safeAreaSize = 0;
	for (int y = 1; y <= N; ++y) {
		for (int x = 1; x <= M; ++x) {
			if (lab[y][x] == 0 && visited[y][x] == 0)
				safeAreaSize += 1;
		}
	}

	// 벽으로 설정한 부분 다시 되돌리기
	for (int i = 0; i < 3; ++i) {
		int x = wall[i].first;
		int y = wall[i].second;
		lab[y][x] = 0; //벽으로 설정한 부분 되돌리기
	}

	return safeAreaSize;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M; //세로, 가로

	for (int y = 1; y <= N; ++y) {
		for (int x = 1; x <= M; ++x) {
			cin >> lab[y][x];
			if (lab[y][x] == 0)
				emptyArea.push_back(make_pair(x, y));
			else if (lab[y][x] == 2)
				virusArea.push_back(make_pair(x, y));
		}
	}

	// 알고리즘
	int firstVirusCnt = virusArea.size();
	int firstEmptyAreaCnt = emptyArea.size();
	int maxSafeAreaSize = 0;

	// emptyarea를 순회하며 벽을 세울 3개의 공간을 선정
	for (int i = 0; i < firstEmptyAreaCnt; ++i) {
		wall[0] = emptyArea[i];
		for (int j = i + 1; j < firstEmptyAreaCnt; ++j) {
			wall[1] = emptyArea[j];
			for (int k = j + 1; k < firstEmptyAreaCnt; ++k) {
				wall[2] = emptyArea[k];

				// bfs로 safe한 영역의 사이즈를 계산
				int safeAreaSize = calSafeAreaSize();
				if (safeAreaSize > maxSafeAreaSize)
					maxSafeAreaSize = safeAreaSize;
			}
		}
	}
	cout << maxSafeAreaSize;
}

