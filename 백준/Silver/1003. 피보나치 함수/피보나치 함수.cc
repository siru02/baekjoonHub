#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

/*
1. 테이블 설정
	n을 입력받았을 때 0 또는 1이 출력되는 횟수
2. 점화식
	table[n] = table[n - 1] + table[n - 2]
3. 초기값 설정
*/

vector<pair<int, int>> table;

int fibo(int n) {
	if (n == 0) { // 이 경우와
		cout << "0";
		return 0;
	}
	else if (n == 1) { // 이 경우가 몇번인지 출력
		cout << "1";
		return 1;
	}
	else {
		return fibo(n - 1) + fibo(n - 2);
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	table.push_back(make_pair(1, 0)); //0이 출력되는 횟수, 1이 출력되는 횟수
	table.push_back(make_pair(0, 1)); // 0이 출력되는 횟수, 1이 출력되는 횟수
	table.push_back(make_pair(1, 1)); // 2 = 0 + 1
	//table.push_back(make_pair()) // 3 = 1 + 2 = 1 + 0 + 1

	pair<int, int> tmp;
	for (int i = 3; i < 42; ++i) {
		tmp.first = table[i - 2].first + table[i - 1].first;
		tmp.second = table[i - 2].second + table[i - 1].second;
		table.push_back(tmp);
	}

	int T; cin >> T;
	for (int i = 0; i < T; ++i) {
		int n; cin >> n;
		cout << table[n].first << " " << table[n].second << "\n";
	}

}