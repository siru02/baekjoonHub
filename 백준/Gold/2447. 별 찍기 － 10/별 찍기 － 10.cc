#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/*
1. n은 3의 거듭제곱 형식으로 입력된다
2. 현재 회차에서 '*'은 다음 depth의 출력결과물과 같다
3. 출력 모양은
	***
	* *
	***
4. 한 회차에서 가운데 빈 블락을 제외한 나머지 블락의 모양은 같으므로 하나만 재귀를 돌려서 얻고 그걸 나눠서 찍는다
*/

char canvas[6561][6562];
int n;

// 오버플로우 발생
void	recursive(int curBlockSize, int x, int y) {
	if (curBlockSize == 1) {
		canvas[y][x] = '*';
		return;
	}
	int nextBlockSize = curBlockSize / 3;
	for (int dy = 0; dy < 3; dy++) {
		for (int dx = 0; dx < 3; dx++) {
			// 가운데 부분은 공백으로 채움
			if (dy == 1 && dx == 1) {
				for (int i = 0; i < nextBlockSize; i++)
					for (int j = 0; j < nextBlockSize; j++)
						canvas[y + dy * nextBlockSize + i][x + dx * nextBlockSize + j] = ' ';
			}
			else
				recursive(nextBlockSize, x + dx * nextBlockSize, y + dy * nextBlockSize);
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;

	recursive(n, 0, 0);
	for (int i = 0; i < n; i++) {
		cout << canvas[i] << "\n";
	}
}