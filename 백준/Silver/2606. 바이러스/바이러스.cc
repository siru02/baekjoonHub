#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int board[101] = { 0 };
int graph[101][101] = { 0 };

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int comCnt, pairCnt;
	cin >> comCnt >> pairCnt;

	int start, end;
	for (int i = 0; i < pairCnt; i++){
		cin >> start >> end;
		graph[start][end] = 1;
		graph[end][start] = 1;
	}

	queue<int> q;
	q.push(1);
	board[1] = 1;

	int ans = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 1; i < 101; ++i) {
			if (graph[cur][i] == 1 && board[i] == 0) {
				board[i] = 1;
				ans++;
				q.push(i);
			}
		}
	}
	cout << ans;
}
