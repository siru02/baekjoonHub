//bfs
/*
 * 큐(queue)를 생성한다.
 * 시작 좌표(또는 노드)를 큐에 넣고, 방문 표시를 한다.
 * 큐가 빌 때까지 다음을 반복한다:
 *   - 큐의 front에서 원소를 pop한다.
 *   - 현재 위치를 기준으로 인접한 탐색 가능한 지점들을 확인한다.
 *   - 아직 방문하지 않은 지점을 큐에 넣고, 방문 표시를 한다.
 * BFS에서는 큐에 넣는 시점에 방문했다고 간주한다.
 */
// dfs
/*
 * 스택(stack)을 생성한다.
 * 시작 좌표(또는 노드)를 스택에 넣고, 방문 표시를 한다.
 * 스택이 빌 때까지 다음을 반복한다:
 *   - 스택의 top 원소를 pop한다.
 *   - 현재 위치를 기준으로 인접한 지점들을 확인한다.
 *   - 인접한 지점 중 방문하지 않은 지점이 있다면 스택에 넣고, 방문 표시를 한다.
 * DFS는 스택을 통해 한 방향으로 깊게 들어간 후, 더 이상 갈 곳이 없으면 되돌아온다.
 */

#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
#include <stack>
/*
* 각 색종이가 5개씩 존재
* 백트래킹으로 1을 만났을 때, 해당 위치에 큰 색종이부터 대입이 가능한지 확인한다
* 가능하다면해당 위치를 0으로 바꾸고, 다음 1을 만날때까지 dfs를 수행
* 모든 1을 색종이로 가릴 수 없다면 백트래킹
*/

int map[10][10];
int paperCnt[6] = { 0,5,5,5,5,5 }; //색종이 개수
int ans = 2147483647;

using namespace std;

int canAttach(int x, int y, int size) {
	if (x + size > 10 || y + size > 10) //자기자신도 포함해야하므로 >로 비교한다
		// x = 8, size = 2이면 -> 8 9에 시도 == 올바름
		return 0;
	for (int ny = y; ny < y + size; ++ny) {
		for (int nx = x; nx < x + size; ++nx) {
			if (map[ny][nx] != 1)
				return 0;
		}
	}
	return 1;
}

void setPaper(int x, int y, int size, int val) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j)
			map[y + i][x + j] = val;
	}
}

// x,y부터 dfs수행
void dfs(int x, int y, int used) {
	if (y >= 10) { //y탐색이 끝에 다다르면 == 전 탐색이 끝나면
		ans = min(ans, used);
		return;
	}
	if (x >= 10) { //x탐색이 끝에 다다르면
		dfs(0, y + 1, used);
		return;
	}
	
	if (used >= ans) return; //이미 사용개수가 더 크면 중간에 종료하는게 back tracking

	if (map[y][x] == 0)
		dfs(x + 1, y, used);
	else { //1인경우
		for (int size = 5; size >= 1; --size) {
			if (paperCnt[size] > 0 && canAttach(x, y, size)) {
				setPaper(x, y, size, 0);
				paperCnt[size] -= 1;
				dfs(x + size, y, used + 1);
				paperCnt[size] += 1;
				setPaper(x, y, size, 1); //백트래킹상 원래대도 되돌려야 하므로
			}
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j)
			cin >> map[i][j];
	}

	dfs(0, 0, 0);
	cout << (ans == 2147483647 ? -1 : ans) << '\n';
}
