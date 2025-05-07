#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

/*
* 이웃한 집과 색이 달라야한다
1. 테이블 : RGB 3가지 색상으로 칠했을 때의 최소 비용
2. 점화식 : 이전 집과 다른 색으로 칠했을 떄의 최소 비용
		table[0][i] = min(table[1][i - 1], table[2][i - 1]) + R; //R로 채색하는 경우
		table[1][i] = min(table[0][i - 1], table[2][i - 1]) + G; //G로 채색하는 경우
		table[2][i] = min(table[0][i - 1], table[1][i - 1]) + B; //B로 채색하는 경우
3. 초기항
		table[0][0] = 0; table[1][0] = 0; table[2][0] = 0;
*/

int table[3][1001]; //0은 현재 집이 R로 칠했을 때의 최소 비용, 1은 현재 집이 G로 칠했을 때의 최소 비용, B는 현재집이 B로 칠해졌을 때의 최소 비용

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N, R, G, B;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> R >> G >> B; // i번 집을 RGB각각의 색으로 칠하는데 필요한 비용
		table[0][i] = min(table[1][i - 1], table[2][i - 1]) + R; //R로 채색하는 경우
		table[1][i] = min(table[0][i - 1], table[2][i - 1]) + G; //G로 채색하는 경우
		table[2][i] = min(table[0][i - 1], table[1][i - 1]) + B; //B로 채색하는 경우
	}
	cout << min(min(table[0][N], table[1][N]), table[2][N]);
}