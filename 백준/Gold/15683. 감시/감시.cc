#include <iostream>
#include <algorithm>

using namespace std;

/*
1. 백트래킹을 이용할것
2. 0행, 1행 ... 순으로 탐색
3. 각 행의 n번 인덱스에 다다르면 다음 행을 탐색
4. 행을 탐색하면서 감시카메라를 만나면 board[y][x]에 감사중인 카메라의 개수를 올려준다
5. 백트래킹으로 반복해서 탐색하면서 끝까지 도달하였을 때, 미감시중인 영역을 출력한다
*/

/*
1. cctv의 좌표만 따로 vector<pair<int, int>> cctvs; 에 저장
2. recursive(int depth)로 depth == cntCctvs 인 경우에 비교
*/

int map[9][9] = { 0 };
int board[9][9] = { 0 };
int n, m;
int area = 2147483647;
int cctvCnt = 0;

void recursive(int x, int y, int depth);

void checkRight(int x, int y) {
	for (int i = x + 1; i < m; ++i) {
		++board[y][i];
		if (map[y][i] == 6)
			break;
	}
}

void removeRight(int x, int y) {
	for (int i = x + 1; i < m; ++i) {
		--board[y][i];
		if (map[y][i] == 6)
			break;
	}
}

void checkLeft(int x, int y) {
	for (int i = x - 1; i >= 0; --i) {
		++board[y][i];
		if (map[y][i] == 6)
			break;
	}
}

void removeLeft(int x, int y) {
	for (int i = x - 1; i >= 0; --i) {
		--board[y][i];
		if (map[y][i] == 6)
			break;
	}
}

void checkUp(int x, int y) {
	for (int i = y + 1; i < n; ++i) {
		++board[i][x];
		if (map[i][x] == 6)
			break;
	}
}

void removeUp(int x, int y) {
	for (int i = y + 1; i < n; ++i) {
		--board[i][x];
		if (map[i][x] == 6)
			break;
	}
}

void checkDown(int x, int y) {
	for (int i = y - 1; i >= 0; --i) {
		++board[i][x];
		if (map[i][x] == 6)
			break;
	}
}

void removeDown(int x, int y) {
	for (int i = y - 1; i >= 0; --i) {
		--board[i][x];
		if (map[i][x] == 6)
			break;
	}
}

void caseOne(int x, int y, int depth) {
	// 다음 depth에서 탐색해야하는 좌표 계산
	int nx = x + 1;
	int ny = y;
	if (nx >= m) {
		nx = 0;
		ny = y + 1;
	}
	//right
	checkRight(x, y);
	recursive(nx, ny, depth + 1); // 다음 좌표에 대해서 recursive함수를 호출
	removeRight(x, y);

	//up
	checkUp(x, y);
	recursive(nx, ny, depth + 1);
	removeUp(x, y);

	//left
	checkLeft(x, y);
	recursive(nx, ny, depth + 1);
	removeLeft(x, y);

	//down
	checkDown(x, y);
	recursive(nx, ny, depth + 1);
	removeDown(x, y);
}

void caseTwo(int x, int y, int depth) {
	// 다음 depth에서 탐색해야하는 좌표 계산
	int nx = x + 1;
	int ny = y;
	if (nx >= m) {
		nx = 0;
		ny = y + 1;
	}
	// right left
	checkRight(x, y);
	checkLeft(x, y);
	recursive(nx, ny, depth + 1);

	removeRight(x, y);
	removeLeft(x, y);

	// up down
	checkUp(x, y);
	checkDown(x, y);
	recursive(nx, ny, depth + 1);

	removeUp(x, y);
	removeDown(x, y);
}

void caseThree(int x, int y, int depth) {
	// 다음 depth에서 탐색해야하는 좌표 계산
	int nx = x + 1;
	int ny = y;
	if (nx >= m) {
		nx = 0;
		ny = y + 1;
	}
	// right up
	checkRight(x, y);
	checkUp(x, y);
	recursive(nx, ny, depth + 1);

	removeRight(x, y);
	removeUp(x, y);

	// up left
	checkUp(x, y);
	checkLeft(x, y);
	recursive(nx, ny, depth + 1);

	removeUp(x, y);
	removeLeft(x, y);

	// left down
	checkLeft(x, y);
	checkDown(x, y);
	recursive(nx, ny, depth + 1);

	removeLeft(x, y);
	removeDown(x, y);

	// down right
	checkDown(x, y);
	checkRight(x, y);
	recursive(nx, ny, depth + 1);

	removeRight(x, y);
	removeDown(x, y);
}

void caseFour(int x, int y, int depth) {
	// 다음 depth에서 탐색해야하는 좌표 계산
	int nx = x + 1;
	int ny = y;
	if (nx >= m) {
		nx = 0;
		ny = y + 1;
	}
	// up 제외
	checkRight(x, y);
	checkLeft(x, y);
	checkDown(x, y);
	recursive(nx, ny, depth + 1);

	removeRight(x, y);
	removeLeft(x, y);
	removeDown(x, y);

	//rignt 제외
	checkUp(x, y);
	checkLeft(x, y);
	checkDown(x, y);
	recursive(nx, ny, depth + 1);

	removeUp(x, y);
	removeLeft(x, y);
	removeDown(x, y);

	// left 제외
	checkUp(x, y);
	checkDown(x, y);
	checkRight(x, y);
	recursive(nx, ny, depth + 1);

	removeRight(x, y);
	removeUp(x, y);
	removeDown(x, y);

	// down 제외
	checkUp(x, y);
	checkLeft(x, y);
	checkRight(x, y);
	recursive(nx, ny, depth + 1);

	removeRight(x, y);
	removeUp(x, y);
	removeLeft(x, y);
}

void caseFive(int x, int y, int depth) {
	// 다음 depth에서 탐색해야하는 좌표 계산
	int nx = x + 1;
	int ny = y;
	if (nx >= m) {
		nx = 0;
		ny = y + 1;
	}
	// 4방향 모두 체크
	checkUp(x, y);
	checkDown(x, y);
	checkLeft(x, y);
	checkRight(x, y);
	recursive(nx, ny, depth + 1); //새로 탐색해야하는 좌표를 인자로 넘긴다

	removeRight(x, y);
	removeUp(x, y);
	removeDown(x, y);
	removeLeft(x, y);
}

void checkMap(int x, int y, int depth) {
	int num = map[y][x];

	if (num == 0)
		return;
	else if (num == 1)
		caseOne(x, y, depth);
	else if (num == 2)
		caseTwo(x, y, depth);
	else if (num == 3)
		caseThree(x, y, depth);
	else if (num == 4)
		caseFour(x, y, depth);
	else if (num == 5)
		caseFive(x, y, depth);
	else if (num == 6)
		++board[y][x];
}

// 갈림길을 발견할때마다 depth 증가
// 새로 탐색해야하는 좌표를 인자로 받는다
void recursive(int x, int y, int depth) {
	if (depth == cctvCnt) {
		int cnt = 0;
		for (int ny = 0; ny < n; ny++) {
			for (int nx = 0; nx < m; nx++) {
				if (map[ny][nx] == 0 && board[ny][nx] == 0)
					cnt++;
			}
		}
		if (cnt < area)
			area = cnt;
		return;
	}

	for (int nx = x; nx < m; nx++) {
		checkMap(nx, y, depth); // 현재 탐색해야하는 좌표부터 인자로 넘긴다
	}

	for (int ny = y + 1; ny < n; ny++) {
		for (int nx = 0; nx < m; nx++) {
			checkMap(nx, ny, depth);
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int tmp;
	cin >> n >> m;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> tmp;
			map[y][x] = tmp;
			if (1 <= tmp && tmp <= 5)
				++cctvCnt;
		}
	}

	recursive(0, 0, 0);
	cout << area;
}