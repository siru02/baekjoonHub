#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int dl[6] = { 0, 1, 0, -1, 0, 0 };
int dr[6] = { 1, 0, -1, 0, 0, 0 };
int dc[6] = { 0, 0,0 ,0 ,1, -1 };

char map[31][31][31];
int board[31][31][31];

int L, R, C;

typedef struct point {
	int l, r, c;
}point;

void bfs(queue<point> &q) {
	while (!q.empty()) {
		point cur = q.front();
		q.pop();
		for (int i = 0; i < 6; ++i) {
			int nl = cur.l + dl[i];
			int nr = cur.r + dr[i];
			int nc = cur.c + dc[i];
			if (nl >= L || nr >= R || nc >= C || nl < 0 || nr < 0 || nc < 0) continue;
			if (map[nl][nr][nc] == '#' || board[nl][nr][nc] != 0) continue;
			if (map[nl][nr][nc] == 'E') {
				cout << "Escaped in " << board[cur.l][cur.r][cur.c] << " minute(s).\n";
				return;
			}
			q.push({ nl, nr, nc });
			board[nl][nr][nc] = board[cur.l][cur.r][cur.c] + 1; // 이동거리 1 증가
		}
	}
	cout << "Trapped!\n";
}

int main() 
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	while (1) {
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0)
			return 0;
		queue<point> q;
		for (int l = 0; l < L; ++l) {
			for (int r = 0; r < R; ++r) {
				for (int c = 0; c < C; ++c) {
					cin >> map[l][r][c];
					board[l][r][c] = 0;
					if (map[l][r][c] == 'S') {
						q.push({l, r, c});
						board[l][r][c] = 1;
					}
				}
			}
		}
		bfs(q);
	}
}