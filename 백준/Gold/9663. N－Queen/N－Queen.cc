#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
NxN 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제
-> 백트래킹의 현재 상태에서 가능한 모든 후보군을 따라 들어가며 탐색하는 성질을 이용
1. 맵을 설정
2. 맵에 퀸들을 놓으면서 현재 자리에 놓을 수 있는지 검사
3. 놓을 수 없으면 돌아가기
*/

int map[16][16] = { 0 };
int cnt = 0;

// 십자 방향 검사
bool checkCross(int nx, int ny, int n) {
	// y 축 검사
	for (int i = 0; i < ny; i++) {
		//if (i == ny) continue;
		if (map[i][nx] == 1)
			return false;
	}
	return true;
}

// X 방향 검사
bool checkX(int nx, int ny, int n) {
	for (int i = 1; i < n; i++) {
		// 왼쪽 위
		if (nx - i >= 0 && ny - i >= 0) {
			if (map[ny - i][nx - i] == 1)
				return false;
		}

		// 오른쪽 위
		if (nx + i < n && ny - i >= 0) {
			if (map[ny - i][nx + i] == 1)
				return false;
		}
	}
	return true;
}

bool checkAvailability(int nx, int ny, int n) {
	return checkCross(nx, ny, n) && checkX(nx, ny, n);
}

// (x + 1, y) 부터 검토 수행
void recursive(int y, int n) {

	if (y == n) {// n개의 말을 두었으면
		++cnt;
		return;
	}
	for (int x = 0; x < n; x++) {
		// (x, y)가 둘 수 있는 장소인지 확인하고 재귀로 타고 들어간다
		if (checkAvailability(x, y, n)) {
			map[y][x] = 1;
			//cout << "(" << nx << ", " << ny << ") ";
			recursive(y + 1, n); //다음 행부터 탐색해도 충분하므로 y를 증가시킨다
			map[y][x] = 0;
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	recursive(0, n);
	cout << cnt;
}