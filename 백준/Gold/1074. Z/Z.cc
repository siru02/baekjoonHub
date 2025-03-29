#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, r, c;
long long cnt = 0;

/*
1. 2^n 크기의 맵을 4등분한다
2. 1번째 depth에서는 맵을 4등분하여 z모양으로 탐색
3. 2번째 dpeth에서는 4등분한 맵을 다시 4등분하여 2^(n/2)인 정사각형을 탐색
4. 반복
*/

// 2^n * 2^n 배열에서 (x, y)를 방문하는 순서를 반환
void recursive(int n, int x, int y)
{
	if (n-- == 0)
		return;

	long long len = 1 << n;

	if (r < y + len && c < x + len) { //2사분면
		recursive(n, x, y);
	}
	else if (r < y + len && c >= x + len) { //1사분면
		cnt += len * len;
		recursive(n, x + len, y);
	}
	else if (r >= y + len && c < x + len) { //3사분면
		cnt += len * len * 2;
		recursive(n, x, y + len);
	}
	else { //4사분면
		cnt += len * len * 3;
		recursive(n, x + len, y + len);
	}
}


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> r >> c;
	recursive(n, 0, 0);
	cout << cnt;
}