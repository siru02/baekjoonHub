#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

/*
* table: k개의 정삼각형을 만들기 위해필요한 대포알의 개수
*/

int triangle[800];
int table[150];
int N;
int dp[300001];

void setTriangle() {
	triangle[0] = 1; // 1 3 6 10
	table[0] = 1;
	int i = 1;
	int cnt = 0;
	for (; i < 800; ++i) {
		triangle[i] = triangle[i - 1] + (i + 1);
		table[i] = table[i - 1] + triangle[i];
		if (table[i] >= N) // 초과한 경우에 탈출, 같은 경우는 뺼 수 있으므로 제외
			break;
	}
}

int main() 
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	setTriangle();
	//dp로 k개의 대포알로 생성가능한 정사면체의 최소 개수를 저장
	dp[0] = 0;
	dp[1] = 1;
	for (int idx = 2; idx <= N; ++idx) {
		int prev = 0;
		dp[idx] = 2147483647;
		for (; table[prev] <= idx; ++prev) {
			if (dp[idx] > dp[idx - table[prev]] + 1) {
				dp[idx] = dp[idx - table[prev]] + 1;
			}
			if (table[prev] == idx)
				dp[idx] = 1;
		}
		//cout << idx << ": " << dp[idx] << "\n";
	}
	cout << dp[N];
}