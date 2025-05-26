#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

// 뗄 수 있는 스티커 점수의 합 최대
// 2n개 스티커중에서 점수의 합이 최대가 되면서 서로 변을 공유하지않는 스티커 집합
/*
1. 테이블 설정
	table[i][n]은 n번 인덱스에서, i행 원소를 선택해서 얻을 수 있는 점수의 최대
	
2. 점화식 // 현재 시점에서 미래를 예측하는 방향으로 작성해야한다
	table[i][n]은 하기 원소중 최대를 선정
	1. table[!i][n-1] + input[i][n] // 이전 열까지 합 + 현재
	2. table[i][n-2] + input[i][n] // 전전열까지의 합 + 현재
	3. table[!i][n-2] + input[i][n] // 전전열까지의 합 + 현재
	

3. 초기값 설정
	table[0][1] = input[0][1];
	table[1][1] = input[1][1];
	
*/

int input[2][100002];
int table[2][100002];


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int T;	cin >> T;
	for (int t = 0; t < T; ++t) {
		for (int i = 0; i < 100002; ++i) {
			input[0][i] = 0;
			input[1][i] = 0;
			table[0][i] = 0;
			table[0][i] = 0;
		}
	// 각 케이스에 대한 실행부
		int n; cin >> n; // 정수 n
		
		// 입력부
		for (int i = 1; i <= n; ++i) {
			cin >> input[0][i];
		}
		for (int i = 1; i <= n; ++i) {
			cin >> input[1][i];
		}

		// dp연산파트
		table[0][1] = input[0][1];
		table[1][1] = input[1][1];
		for (int i = 1; i <= n; ++i) {
			for (int row = 0; row < 2; ++row) {
				int case1 = table[!row][i - 1] + input[row][i];
				int case2 = table[row][i - 2] + input[row][i];
				int case3 = table[!row][i - 2] + input[row][i];
				int max = case1 > case2 ? case1 : case2;
				max = max > case3 ? max : case3;
				//1. table[!i][n - 1] + input[i][n] // 이전열까지 합 + 현재
				//2. table[i][n - 2] + input[i][n] // 전전열까지의 합 + 현재
				//3. table[!i][n - 2] + input[i][n] // 전전열까지의 합 + 현재
				table[row][i] = max;
			}
		}

		/*cout << "test: ";
		for (int i = 0; i <= n; ++i) {
			cout << "(" << table[0][i] << "," << table[1][i] << ") ";
		}*/
		//cout << "\n";
		cout << (table[0][n] > table[1][n] ? table[0][n] : table[1][n]) << "\n";

	}
}