#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int map[1001][1001] = { 0 }; //map[y][x]
int board[1001][1001] = { 0 };
int cnt[2] = { 0,0 };

int isUniform(int len, pair<int, int> start) {
	int color = map[start.second][start.first];
	for (int y = 0; y < len; ++y) {
		for (int x = 0; x < len; ++x) {
			if (map[start.second + y][start.first + x] != color)
				return false;
		}
	}
	cnt[color]++;
	return true;
}

// 인자로 시작점과 한 변의 길이를 받는다
void recursive(int half, pair<int, int> start) { // start.first = x, start.second = y
	if (isUniform(half, start))
		return;

	half = half / 2;
	recursive(half, make_pair(start.first, start.second));                          // 왼쪽 위
	recursive(half, make_pair(start.first + half, start.second));                  // 오른쪽 위
	recursive(half, make_pair(start.first, start.second + half));                  // 왼쪽 아래
	recursive(half, make_pair(start.first + half, start.second + half));
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n; cin >> n;
	int tmp;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			cin >> tmp;
			map[y][x] = tmp;
		}
	}

	pair<int, int> start = make_pair(0, 0);
	recursive(n, start);
	cout << cnt[0] << "\n" << cnt[1];
}