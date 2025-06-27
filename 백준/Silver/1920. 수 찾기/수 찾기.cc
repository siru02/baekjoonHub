#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

/*
* 1. A를 정렬
* 2. B의 원소를 순회하며 A를 이분탐색
*/

vector<int> A;
int N, M;

bool Check(int idx, int b) {
	if (b > A[idx])
		return true;
	return false;
}

// b가 A안에 있는지 이분탐색을 수행한다
bool memberIsInA(int b) {
	int lo = -1;
	int hi = N;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (A[mid] == b)
			return true;
		if (Check(mid, b)) { // b > A[idx] -> 오른쪽탐색해야함
			lo = mid;
		}
		else {
			hi = mid;
		}
	}
	return (lo >= 0 && A[lo] == b) || (hi < N && A[hi] == b); //lo와 lo+1에 대한 비교는 아직 수행하지 않았으므로
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> a;
		A.push_back(a);
	}
	sort(A.begin(), A.end());
	cin >> M;
	for (int i = 0; i < M; ++i) {
		int b; cin >> b;
		if (memberIsInA(b)) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}
}