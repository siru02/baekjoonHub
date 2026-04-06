#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>
using namespace std;

/*
* 명령어 D S L R
* 레지스터에는 0~10000미만의 정수
* n의 네 자릿수를 d1, d2, d3, d4
* D : n을 두 배로 바꾼다
* S : n-1
* L : n의 각 자릿수르 ㄹ왼편으로 회전 -> d2 d3 d4 d1
* R : n의 각 자릿수를 오른편으로 회전 -> d4 d1 d2 d3
* A와 B에 대하여 A를 B로 바꾸는 최소한의 명령어를 생성하는 프로그램
*/

/*
* RxC 보드
* 보드의 각 칸에는 대문자 알파벳
* 좌측 상단 칸에는 말이 있음
* 말은 상하좌우 인접한 네 칸 중 한 칸으로 이동
* 새로 이동한 칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 적혀있는 알파벳과는 달라야한다
* 좌측 상단에서 시작해서 말이 최대 몇 칸을 지날 수 있는지 구해라
*/

int R, C;
int maxDepth = 1; // 말이 최대로 지날 수 있는 칸의 수


char board[21][21] = { 0 }; // 입력받은 보드판
int visited[21][21] = { 0 };// 보드판에 대한 방문 기록을 저장할 맵
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
char visitedStr[50];

// 현재 좌표에 해당하는 문자와 일치하는 문자가 있는지 검사
bool isAvailableBlock(int nx, int ny, int depth) {
	if (visited[nx][ny] != 0) return false;
	char ch = board[nx][ny];
	for (int i = 0; i < depth; ++i) {
		if (ch == visitedStr[i])
			return false;
	}
	return true;
}

// dfs 백트래킹을 통해 푼다, xy는 현재 좌표, depth는 깊이
void dfs(int x, int y, int depth) {
	if (isAvailableBlock(x, y, depth) == false) 
		return;

	//cout << "cur(x,y) : (" << x << ", " << y << ")"<< depth + 1 << "\n";

	// (x, y)방문 성공시 방문 표시
	visited[x][y] = 1;
	visitedStr[depth] = board[x][y];
	visitedStr[depth + 1] = '\0';
	if (depth + 1 > maxDepth) maxDepth = depth + 1;

	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx <= 0 || ny <= 0 || nx > R || ny > C) continue;

		//cout << "cur(nx,ny) : " << nx << ", " << ny << "\n";
		dfs(nx, ny, depth + 1);
	}

	// dfs 종료시 방문표시 삭제
	visited[x][y] = 0;
	visitedStr[depth] = '\0';
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> R >> C;
	for (int r = 1; r <= R; ++r) {
		for (int c = 1; c <= C; ++c) {
			cin >> board[r][c];
		}
	}

	dfs(1, 1, 0);


	cout << maxDepth;
}