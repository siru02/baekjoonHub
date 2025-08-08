#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

/*
* 정수 삼각형을 아래의 있는 수를 선택해서 내려가며, 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램
* 아래층을 선택할 때는 대각선 왼쪽 또는 대각선 오른쪽의 것만 선택 가능
*/

/*
1. 테이블 설정 -> table[i][j]는 해당 위치에 올 수 있는 최대값
2. 점화식 설정 -> table[i][j] = max{(table[i-1][j], table[i-1][j+1]) ...}
3. 초기값 설정
*/

int triangle[502][502];
int table[502][502];

//(i, j)인덱스의 table에 값을 채운다
void setTable(int i, int j) {
	int leftPrev = 0;
	if (j > 0)
		leftPrev = table[i - 1][j - 1];

	int rightPrev = 0;
	if (j < i)
		rightPrev = table[i - 1][j];
	table[i][j] = max(leftPrev, rightPrev) + triangle[i][j];
}

int main() 
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	// 입력부 O(N logN)
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			cin >> triangle[i][j];
		}
	}
	
	table[0][0] = triangle[0][0]; // 초기값설정
	// 각 index에 위치할 수 있는 최대값을 설정한다
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			setTable(i, j);
		}
	}

	int maxVal = 0;
	for (int i = 0; i < n; ++i) {
		if (maxVal < table[n - 1][i])
			maxVal = table[n -1][i];
	}
	cout << maxVal;
}