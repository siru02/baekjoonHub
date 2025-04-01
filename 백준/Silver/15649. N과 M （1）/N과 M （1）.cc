#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
1~n까지의 숫자중 m개를 선택해서 만들 수 있는 수열을 모두 구해야한다.
1. 1부터 시작해서 재귀로 depth가 m일 때까지 탐색한다
2. 각 재귀로 depth가 깊어질때마다 arr[idx]에 현재 숫자를 넣으며, 재귀 탈출 후에는 다음 숫자를 집어넣도록 한다
*/

int n, m;
int arr[8] = { 0 };
int available[8] = { 1, 2, 3,4,5,6,7,8 };

void recursive(int prev, int depth)
{
	// 재귀 탈출조건
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	bool flag = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < depth; j++) {
			if (arr[j] == i) {
				flag = true;
				break;
			}
		}
		if (flag) {
			flag = false;
			continue;
		}
		arr[depth] = i;
		recursive(i, depth + 1);
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	
	recursive(0, 0);
}
