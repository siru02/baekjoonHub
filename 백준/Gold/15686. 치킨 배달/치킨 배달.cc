#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

/*
1. 도시의 치킨 거리는 모든 집의 치킨거리의 합
2. 치킨거리가 최소가 되도록 해야한다
3. M개를 제외한 치킨집을 모두 폐업시켜야한다
4. 백트래킹으로 구현가능할듯 아니면 치킨집 경우의수를 맵에 채워두고, 이를 이용해서 전부 비교한다
*/

int cityChickenLen = 2147483647;
int map[51][51] = { 0 };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
vector<pair<int, int>> chicken;
int X[13];
int Y[13];
int board[51][51];

// 인자로 치킨집들을 받고, 치킨집들을 시작점으로 bfs를 돌려서 각 집의 치킨거리를 입력한다
int bfs(int m, int n) {
	queue<pair<int, int>> q;
	memset(board, 0x7f, sizeof(board));

	for (int i = 0; i < m; i++) {
		q.push(make_pair(X[i], Y[i]));
		board[Y[i]][X[i]] = 0;
	}

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx >= n || ny >= n || nx < 0 || ny < 0) continue;
			if (board[ny][nx] <= board[cur.second][cur.first] + 1) continue;
			board[ny][nx] = board[cur.second][cur.first] + 1;
			q.push(make_pair(nx, ny));
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1)
				sum += board[i][j];
		}
	}
	return sum;
}

// 많은 치킨집중에서 m개를 선택하는 경우의 조합 백트래킹으로 구현
void recursive(int depth, int start, int m, int n) {
	if (depth == m) {
		int len = bfs(m, n);
		cityChickenLen = min(cityChickenLen, len);
		return;
	}
	for (int i = start; i < chicken.size(); i++) {
		X[depth] = chicken[i].first;
		Y[depth] = chicken[i].second;
		recursive(depth + 1, i + 1, m, n);
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, m, tmp;
	cin >> n >> m;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			cin >> tmp;
			map[y][x] = tmp;
			if (tmp == 2)
				chicken.push_back(make_pair(x, y));
		}
	}
	recursive(0, 0, m, n);
	cout << cityChickenLen;
}