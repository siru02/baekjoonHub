#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

/*
* 수빈이는 N에 위치
* 동생은 k에 위치
* 수빈이는 걷거나 순간이동
* 걷기 : x + 1
* 순간이동 : x * 2
* 수빈이가 동생을 찾을 수 있는 가장 빠른 시간
*/

/* 알고리즘
* 1차원 배열로 board를 생성
* 1차원 배열로 visited 생성
* visited에는 수빈이가 각 좌표에 도달하는데 걸린 최단시간을 기록
* 방문 경로를 기억하고 출력해야한다
* prevSite에 현재 노드에 방문하기 직전 노드를 기록해둔다
*/

int visited[100001] = { 0 };
int prevSite[100001] = { 0 };
int N, K;

void bfs() {
	queue<int> q;
	q.push(N);
	visited[N] = 1; // 시작점에 도달하는데 걸린 시간을 1초라고 가정

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		// 앞으로 이동
		int nx = cur + 1;
		if (nx <= 100000) { // 올바른 범위 안에서만 수행
			if (visited[nx] == 0) { // 방문한 좌표가 처음 방문한 좌표인 경우에만 큐에 넣는다
				q.push(nx);
				visited[nx] = visited[cur] + 1;
				prevSite[nx] = cur;
			}
		}

		// 뒤로 이동
		nx = cur - 1;
		if (nx >= 0) { // 올바른 범위 안에서만 수행
			if (visited[nx] == 0) { // 방문한 좌표가 처음 방문한 좌표인 경우에만 큐에 넣는다
				q.push(nx);
				visited[nx] = visited[cur] + 1;
				prevSite[nx] = cur;
			}
		}

		// 순간이동
		nx = cur * 2;
		if (nx <= 100000) { // 올바른 범위 안에서만 수행
			if (visited[nx] == 0) { // 방문한 좌표가 처음 방문한 좌표인 경우에만 큐에 넣는다
				q.push(nx);
				visited[nx] = visited[cur] + 1;
				prevSite[nx] = cur;
			}
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> K;
	bfs();
	cout << visited[K] - 1 << "\n";

	vector<int> path;
	int cur = K;
	while (cur != N) {
		path.push_back(cur);
		cur = prevSite[cur];
	}
	path.push_back(N);
	reverse(path.begin(), path.end());
	for (int x : path)
		cout << x << " ";
}