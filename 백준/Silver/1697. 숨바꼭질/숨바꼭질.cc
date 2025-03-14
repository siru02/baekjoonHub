#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int map[100001] = { 0 };
int n, k;
queue<int> q;

int checkMap(int cur, int nx) {
	if (nx > 100000 || nx < 0) return 0; //범위 밖인경우
	if (map[nx] != 0) return 0;//이미 방문한경우
	map[nx] = map[cur] + 1; //이전 노드 + 1로 칠하기
	q.push(nx); //새 좌표를 큐에 넣기
	return 0;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> k;

	q.push(n);
	map[n] = 1; //현재위치는 1초부터 탐색한다고 가정

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		/*
		바킹독 코드
		for (int next : {cur - 1, cur + 1, cur * 2}) {
			if (next < 0 || next > 100000) continue;// 범위 밖 체크
			if (map[next] != 0) continue; //이미 방문한곳
			map[next] = map[cur] + 1;
			q.push(next);
		}
		*/
		// case1
		int nx = cur + 1;
		if (checkMap(cur, nx) == 1)
			return 0;
		// case2
		nx = cur - 1;
		if (checkMap(cur, nx) == 1)
			return 0;
		// case 3
		nx = cur * 2;
		if (checkMap(cur, nx) == 1)
			return 0;
	}
	cout << map[k] - 1;
}