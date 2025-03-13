#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <list>

using namespace std;

int graph[1001][1001] = {0}; //인접행렬로 각 행과 열은 정점의 번호를 가리킨다
int checkDfs[1001] = {0};
int checkBfs[1001] = {0};
int n,m,v; //정점, 간선, 탐색을 시작할 정점의 번호

//깊이우선탐색
void dfs(int cur)
{
	if (checkDfs[cur] == 1) //방문한 노드라면
		return ;
	cout << cur << " "; //방문하지 않은 노드라면 출력
	for (int i = 1; i <= n; i++) {
		if (graph[cur][i] == 1){
			checkDfs[cur] = 1;
			dfs(i);
		}
	}
}

void bfs(int cur)
{
	queue<int> q;
	q.push(cur); //1번노드를 방문할것이므로
	checkBfs[cur] = 1;

	while (!q.empty()) {
		cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int i = 1; i <= n; i++) {
			if (checkBfs[i] == 1) //방문한노드라면
				continue;
			if (graph[cur][i] == 1) { //방문하지 않았고,연결된 노드이면
				checkBfs[i] = 1; //방문체크
				q.push(i); //방문한 노드 삽입
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> v;

	for (int i = 0; i < m; i++){
		int start,end;
		cin >> start >> end;
		graph[start][end] = 1;
		graph[end][start] = 1;
	}
	dfs(v);
	cout << "\n";
	bfs(v);
}