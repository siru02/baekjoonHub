#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

/*
* 첫째 줄에 강호가 S층에서 G층으로 가기 위해 눌러야 하는 버튼의 수의 최솟값을 출력한다.
* 만약, 엘리베이터로 이동할 수 없을 때는 "use the stairs"를 출력한다.
* 회사는 각 층별로 1차원 배열로 구현하고, U와 D 2가지 방향으로만 이동이 가능하다
1. company라는 배열을 선언하여 각 층별로 몇번만에 도달 가능한지 기록한다
2. 강호가 시작하는 company[S]를 0으로 초기화, 나머지는 -1로 초기화
3. 강호가 시작하는 S를 큐에 넣고, bfs를 수행한다
*/

int company[1000002]; // 회사의 각 층에 몇번째로 도달 가능한지 저장하는 배열

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	//입력부
	int F, G, S; // 건물의 높이, 회사의 층수, 강호가 현재 있는 층
	int U, D; // 엘리베이터는 한번에 U층위, D층아래로만 이동 가능하다
	cin >> F >> S >> G >> U >> D;
	
	// 초기화
	for (int i = 0; i <= F; ++i)
		company[i] = -1; // 회사의 모든 층의 초기값을 -1로 초기화
	company[S] = 0; // 시작 지점을 0으로 초기화한다

	queue<int> q;
	q.push(S);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		int upFloor = cur + U; // 위로 올라갈때의 층수
		int downFloor = cur - D; // 아래로 내려갈 때의 층수
		if (upFloor <= F && company[upFloor] == -1) { // upFloor가 주어진 범위 이내
			/*
			company[upFloor] > company[cur] + 1 조건을 추가하지 않은 이유는
			bfs의 특성상 depth가 낮은것부터 시작하므로, 
			이전에 구해둔 company[upFloor]가 company[cur]보다 항상 작을 것이기 때문에
			-1로 초기화되어 방문하지 upFloor에 방문하지 않았던 경우만 갱신한다
			*/
			company[upFloor] = company[cur] + 1;
			q.push(upFloor);
		}
		if (downFloor > 0 && company[downFloor] == -1) { // downFloor가 주어진 범위 이내라면
			company[downFloor] = company[cur] + 1;
			q.push(downFloor);
		}
	}
	
	if (company[G] == -1)
		cout << "use the stairs";
	else
		cout << company[G];
}