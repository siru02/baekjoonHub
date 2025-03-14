#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int board[1001][1001] = { 0 }; //토마토유무를 확인할 보드 입력
int day[1001][1001] = { 0 }; //날짜를 기입
int n, m;

/*
bfs는 큐에 push하고 pop하면서 동작한다
bfs의 이 성질을 응용한다
-> 시작점 모두를 큐에 넣고 bfs를 시작한다
-> visited에 기록할 때는 이전에 방문한 곳의 day값을 기준으로 기록한다
*/

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
queue<pair<int, int> > q;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;
	
	int num;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			board[i][j] = num;
		}
	}

	/*
	1. 이중 for문으로 보드를 순회한다
	2. 1이 있으면 그 점들을 queue에 넣는다 -> bfs는 너비우선이라는 것을 기억하자 같은 depth의 원소들만이 queue에 동시에 존재한다
	3. bfs를 수행하면서 방문한 곳에 거리만큼 날짜를 기입한다
	*/

	//이중포문으로 맵 순회하며 시작점들을 queue에 넣는다
	int startPointCnt = 0;
	bool visitFlag = false;
	for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
			if (board[y][x] == 1) {
				q.push(make_pair(y, x));
				day[y][x] = 1; //날짜 표시
			}
		}
	}

	int maxDate = 1;
	//bfs순회
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];

			if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue; //맵범위 체크
			if (board[ny][nx] == -1) continue; // 토마토가 없는 맵이면
			if (day[ny][nx] > 0) continue; //이미 방문한 장소이면 두번 방문하지 않는다
			int date = day[cur.first][cur.second] + 1;
			day[ny][nx] = date; // 이전 노드의 depth보다 1 증가하여 기록
			q.push(make_pair(ny, nx)); //큐에 삽입
			if (maxDate < date)
				maxDate = date;
		}
	}

	for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
			if (day[y][x] == 0 && board[y][x] != -1) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << maxDate - 1;
}