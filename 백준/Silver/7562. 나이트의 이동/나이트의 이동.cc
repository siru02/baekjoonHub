#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

/*
bfs의 원리
1. 첫 방문 노드를 queue에 넣는다
2. 방문가능한 모든 방향으로 다음 노드를 찾는다
3. 다음 노드가 조건에 맞지 않으면 continue;
4. 다음 노드에 방문하려는데 방문하지 않았거나, 가중치가 낮으면 방문표시하고 q에 삽입
5. 큐가 빌때까지 반복
*/

int map[301][301] = { 0 }; //입력받을 맵

int dx[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

void setMap(int I)
{
	for (int y = 0; y < I; ++y)
		for (int x = 0; x < I; ++x)
			map[y][x] = 21474836;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		queue<pair<int, int>> q;
		int I;
		cin >> I;
		setMap(I);
		int x, y;
		cin >> x >> y;
		pair<int, int> start = make_pair(x, y);
		q.push(start);
		map[y][x] = 0;

		cin >> x >> y;
		pair<int, int> end = make_pair(x, y);
		
		while (!q.empty()) {
			pair<int, int> cur = q.front();
			q.pop();

			for (int j = 0; j < 8; ++j) {
				int nx = cur.first + dx[j];
				int ny = cur.second + dy[j];

				if (nx >= I || ny >= I || nx < 0 || ny < 0) continue;

				if (map[ny][nx] > map[cur.second][cur.first] + 1) {
					map[ny][nx] = map[cur.second][cur.first] + 1;
					q.push({ nx, ny });
				}
			}
		}
		int num = map[end.second][end.first];
		cout << num << "\n";
	}
}