#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string map[26];
int board[26][26] = { 0 };
int houseIdx = 0;
vector<int> houseNum;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int bfs(int x, int y, int n) {
	int cnt = 1; // 단지별 사람 수
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	board[y][x] = houseIdx;
	
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (map[ny][nx] == '0') continue;
			if (board[ny][nx] != 0) continue;

			q.push(make_pair(ny, nx));
			board[ny][nx] = houseIdx;
			cnt++;
		}
	}
	return cnt;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	string tmp;
	int n;
	getline(cin, tmp);
	n = stoi(tmp);
	for (int i = 0; i < n; i++) {
		getline(cin, tmp);
		map[i] = tmp;
	}
	
	//bfs
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (map[y][x] == '1' && board[y][x] == 0) {
				houseIdx++;
				houseNum.push_back(bfs(x, y, n));
			}
		}
	}
	cout << houseIdx << "\n";
	sort(houseNum.begin(), houseNum.end());
	for (int i = 0; i < houseIdx; i++) {
		cout << houseNum[i] << "\n";
	}
}