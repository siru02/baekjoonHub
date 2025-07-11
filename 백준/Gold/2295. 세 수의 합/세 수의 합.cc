#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
* N개의 수로 이루어진 집합 U
* U[x] + U[y] + U[z] = U[k]인 x, y, z, k를 찾아라
* 1. U[x] + U[y] = two인 vector를 생성 -> N^2
* 2. two + U[z] = U[k]가 존재하는지 탐색 -> N^2(two + U[z]) * log N(U를 바이너리 서칭)
* 3. N^2 + N^2 * log N = N^2 * logN
*/

vector<int> U;
int maxVal = -2147483648;

// 이상이면 참 반환
bool checkLower(int mid, int target, vector<int> &two) {
	if (target >= two[mid])
		return true;
	return false;
}

/*// U에 target값이 존재하는지 lowerBound탐색
// binarySearch가 아닌 범위탐색이므로 타겟을 찾았는지는 모름
int lowerBound(int target, int N) {
	int lo = -1;
	int hi = N;

	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;

		if (checkLower(mid, target)) {
			lo = mid;
		}
		else {
			hi = mid;
		}
	}
	return hi; //hi는 lowerBound에서 >=를 만족하는 첫 원소의 idx를 반환
}*/

// binary 탐색으로 값이 존재하면 처리
void binarySearch(int target, vector<int> &two, int u) {
	int lo = -1;
	int hi = two.size();

	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;

		if (two[mid] == target) {
			if (two[mid] > maxVal)
				maxVal = u;
			return;
		}
		if (checkLower(mid, target, two)) {
			lo = mid;
		}
		else {
			hi = mid;
		}
	}
	return;
}

vector<int> two;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N; cin >> N;
	U.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> U[i];
	}
	sort(U.begin(), U.end()); // N * logN

	// x + y로 A 생성 -> N^2
	for (int i = 0; i < N; ++i) {
		for (int j = i; j < N; ++j) {
			two.push_back(U[i] + U[j]);
		}
	}
	sort(two.begin(), two.end());

	// two + z = k 비교 -> N^2 * log N -> two의 실제 크기가 N^2이므로 N^3이됨
	// two의 크기가 N^2이므로 A를 이진탐색해야한다
	for (int i = N - 1; i >= 0; --i) {
		for (int j = 0; j < i; ++j) {
			binarySearch(U[i] - U[j], two, U[i]);
		}
	}
	cout << maxVal;
}