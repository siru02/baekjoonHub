#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

/*
11722번
dp푸는법
1. 테이블 설정 : i번째 인덱스를 마지막원소로 하는 감소하는 가장 긴 부분수열의 길이
2. 점화식 구하기 : table[i]는 j < i인 j에서 if (A[i] < A[j])이면, A[i]를 table[j]뒤에 붙일 수 있으므로
if (A[i] < A[j]) { table[i] = table[i] > table[j] + 1 ? table[i] : table[j] + 1; }
3. 초기값 구하기 : table[0] = 1;
*/

// 10 30 20 12 11 10 20 9의 경우

vector<int> A(2000); // 입력받을 수열
vector<int> table(2000); // 테이블

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n; cin >> n;
	int tmp;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		A[i] = tmp;
		table[i] = 1;
	}
	//table[0] = 1; //초기값
	for (int i = 1; i < n; ++i) { //i번째 원소를 table[i - 1]뒤에 붙인다
		//15 14 13 12 15 10
		for (int j = 0; j < i; ++j) {
			// table[j]와 table[i]를 비교한다
			if (A[i] < A[j]) { //A[j]가 A[i]보다 크다면 A[i]를 table[j]뒤에 붙일 수 있으므로
// i를 마지막 원소로 하는 부분수열의 길이와 j를 마지막 원소로 하는 부분수열에 A[i]를 붙인 부분수열의 길이 비교
				if (table[i] < table[j] + 1) 
					table[i] = table[j] + 1;
			}
		}
	}
	cout << *max_element(table.begin(), table.end());
}