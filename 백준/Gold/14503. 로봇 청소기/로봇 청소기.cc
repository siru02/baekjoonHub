#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

/*
* 로봇 청소기와 방의 상태가 주어졌을 때, 청소하는 영역의 개수를 구하라
* 로봇 청소기가 있는 방은 N x M 크기의 직사각형
* 각각의 칸은 벽 또는 빈 칸
* 청소기는 바라보는 방향이 있으며, 각 칸은 (r, c)로 표현
* 빈 칸은 청소되지 않은 상태
*/

// 북동남서 = {0, 1, 2, 3} // 시계방향
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int map[52][52]; //빈 방인지, 벽인지 구분
int visited[52][52]; // 청소완료한 방인지 구분

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	// 입력부
	int N, M; cin >> N >> M;
	int y, x, d; cin >> y >> x >> d;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j]; // 0인경우 청소되지 않은 빈칸, 1은 벽
			visited[i][j] = 0;
		}
	}

	int cnt = 0;

	pair<int, int> cur = make_pair(x, y);
	while (1) {
		int routine = 1; //청소 루틴1
		if (visited[cur.second][cur.first] == 0) {
			visited[cur.second][cur.first] = 1;
			++cnt;
		}
		//cout << "cur: " << cur.first << ", " << cur.second << "\n";

		routine = 2; // 주변 4칸에 청소되지 않은 빈 칸이 없는 경우
		// 4개 방향체크
		for (int i = 0; i < 4; ++i) {
			int nx = dx[i] + cur.first;
			int ny = dy[i] + cur.second;
			//cout << "nx, ny: " << nx << ", " << ny << "\n";
			if (nx < 0 || ny < 0 || ny >= N || nx >= M) continue; // 범위 밖 예외처리
			if (map[ny][nx] == 1) continue; // 벽인경우
			if (visited[ny][nx] == 0) { //주변 4칸 중 청소되지 않은 빈 칸이 있다면
				routine = 3; // 3번 루틴으로 설정
				break;
			}
		}

		if (routine == 2) { // 청소되지 않은 빈 칸이 없는 경우
			int tempD = (d + 2) % 4; // 후진방향
			int nx = dx[tempD] + cur.first;
			int ny = dy[tempD] + cur.second;
			if (nx >= 0 && ny >= 0 && ny < N && nx < M) { //범위 체크
				if (map[ny][nx] == 0) {//뒤가 벽이 아니라면
					cur = make_pair(nx, ny); // 후진
				}
				else
					break;
			}
		}
		else if (routine == 3) { // 청소되지 않은 빈 칸이 있는 경우
			for (int i = 0; i < 4; ++i) {
				d = (d + 3) % 4; // 반시계 방향으로 90도 회전
				int nx = dx[d] + cur.first;
				int ny = dy[d] + cur.second;

				// 범위안에 청소되지 않은 빈칸이 있는경우
				if (nx >= 0 && ny >= 0 && ny < N && nx < M) {
					if (map[ny][nx] == 0 && visited[ny][nx] == 0) {
						cur = make_pair(nx, ny); // 아리스는 해당위치로 이동
						break;
					}
				}
			}
		}
	}
	cout << cnt;
	/*
	cout << "\n clean map\n";

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
	*/
}