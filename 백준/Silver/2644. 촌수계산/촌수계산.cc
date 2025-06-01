#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
/*
1. board에는 부모자식 관계를 인접행렬 형태로 사용
2. queue에는 입력받은 x,y 중 아무거나 넣는다
-> board는 대칭구조의 관계 그래프이므로 어느 쪽에서 시작해도 같은 결과가 나오기 때문
3. 인접행렬의 한 행(열)을 순회하며 관계가 있는 경우 visited[]에 x와의 거리를 갱신하고, 큐에 추가
*/

int board[102][102]; // 입력받을 보드
int visited[102] = { 0 };

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n; cin >> n; //사람의 수
	int num1, num2; cin >> num1 >> num2; //num1과 num2사이의 관계를 구해야한다
	int m; cin >> m; // 관계 개수

	//빈곳 -1로 초기화
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			board[i][j] = -1;
	}

	// 여기서부턴 부모 자식의 관계
	for (int i = 0; i < m; ++i) {
		int tmp1, tmp2; cin >> tmp1 >> tmp2;
		board[tmp1][tmp2] = 1; //부모자식 관계
		board[tmp2][tmp1] = 1;
	}

	queue<int> q;
	q.push(num1);
	int cur;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int i = 1; i <= n; ++i) {
			if (board[cur][i] == 1) { //관계가 존재한다면
				if (visited[i] == 0) { // 방문하지 않은 노드라면 바로 갱신
					//bfs의 특성상 나중에 방문하는 것은 더 큰 숫자를 가지고 방문하므로
					visited[i] = visited[cur] + 1;
					q.push(i);
				}
			}
		}
	}
	cout << ((visited[num2] == 0) ? -1 : visited[num2]);
}