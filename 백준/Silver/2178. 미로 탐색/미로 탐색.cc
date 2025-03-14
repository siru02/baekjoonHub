#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int board[101][101] = {0}; //미로맵
int visited[101][101] = {0}; //방문체크용 보드이면 각 지점까지 도달하지못했으면0, 도달가능하면 도달가능한 최소비용을 기록

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void printQ(queue<pair<int, int> > q) {
	pair<int, int > cur;
	cout << "q: ";
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		cout << "(" << cur.first << ", " << cur.second << "), ";
	}
	cout << "\n";
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n,m;
	cin >> n >> m;

	// 미로입력
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			board[i][j] = str[j] - '0';
		}
	}

	// for (int i = 0; i < n; i++) {
	// 	cout << "\n";
	// 	for (int j = 0; j < m; j++) {
	// 		cout << board[i][j];
	// 	}
	// }

	//큐생성
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	visited[0][0] = 1;
	/*
	1. 시작지점(0, 0)에 방문체크, 가중치1 부여
	2. bfs시작하여 방문가능하면 cur노드의 가중치 + 1과 이전 값을 비교하여 갱신
	*/
	// bfs
	while (!q.empty()) {
		pair<int, int> cur = q.front(); //현재노드
		q.pop();

		//cout << "cur: (" << cur.first << ", " << cur.second << ") : " << visited[cur.first][cur.second] << "\n";

		for (int i = 0; i < 4; i++) {
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) //맵범위체크
				continue;
			if (board[ny][nx] == 0) //방문가능한 길인지 체크
				continue;

			// 경로비용계산
			int curLen = visited[cur.first][cur.second] + 1; //이전 노드의 가중치 + 1로 갱신
			if (visited[ny][nx] == 0) { //방문하지 않은 노드라면
				visited[ny][nx] = curLen; // 방문체크를 할 때 이전에 방문한 노드+1로
				q.push(make_pair(ny, nx)); // 해당 좌표를 다시 queue에 push한다
			}
			else if (visited[ny][nx] > curLen) // 이미 방문한 노드이고, 가중치가 더 작은 경로라면
			{
				visited[ny][nx] = curLen; // 방문체크를 할 때 이전에 방문한 노드+1로
				q.push(make_pair(ny, nx)); // 해당 좌표를 다시 queue에 push한다
			}
		}
		//printQ(q);
	}
	cout << visited[n - 1][m - 1];
}