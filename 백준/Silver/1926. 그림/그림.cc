#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int board[501][501] = {0};
int input[501][501];

//상하좌우 순서로 탐색
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	cin >> n >> m;

	//입력받기
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++){
			int num; cin >> num;
			input[x][y] = num;
		}
	}

	// 시작점찾기
	int curX, curY;
	int maxSize = 0, cnt = 0;
	for (curY = 0; curY < n; curY++) {
		for (curX = 0; curX < m; curX++){
			//시작점을 찾은경우
			if (input[curX][curY] == 1 && board[curX][curY] == 0) { //그림에 속하고 방문하지 않은 정점이면
				queue<pair<int, int> > q;
				board[curX][curY] = 1; //방문표시
				q.push(make_pair(curX, curY)); //큐에 삽입
				//bfs
				int size = 1;
				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop(); //이게 그림의 개수와 같아진다
					for (int i = 0; i < 4; i++) {
						int nx = cur.first + dx[i];
						int ny = cur.second + dy[i];
						if (nx < 0 || nx >= m || ny < 0 || ny >= n) //범위 밖이면
							continue;
						if (board[nx][ny] == 1) // 이미 방문한 노드라면
							continue;
						//그림에 속하면
						if (input[nx][ny] == 1) {
							q.push(make_pair(nx, ny));
							size++;
						}
						board[nx][ny]= 1; //방문표시
					}
				}
				maxSize = maxSize > size ? maxSize : size;
				cnt++;
			}
		}
	}
	cout << cnt << "\n" << maxSize;
}