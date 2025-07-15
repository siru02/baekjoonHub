#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
* 나무높이를 배열에 저장 후 정렬 N logN
* 자를 높이 h를 정해야한다 -> lo = 1, hi = 제일 높은 나무로 설정하여 이분탐색을 수행
* 집에 가져가는 높이 height설정 -> sum을 구한다
* -> 현재 height에서 집에 가져갈 수 있다면 현재 height미만은 탐색할필요없으므로 lo = height로
* -> 현재 height에서 집에 가져갈 수 없다면 
*/

long long tree[1000002];
long long N, M;
long long maxCuttingHeight = -1;

// 절단기로 잘랐을 때, 가져가는 높이가 M이상인지 확인
bool parametricCheck(long long cuttingHeight) {
	long long sum = 0;
	for (int i = 0; i < N; ++i) {
		if (tree[i] <= cuttingHeight) {
			continue;
		}
		sum += (tree[i] - cuttingHeight);
	}
	//cout << "sum[" << cuttingHeight << "]: " << sum << "\n";
	return sum >= M;
}

void parametricSearch() {
	long long lo = 0, hi = tree[N - 1];
	while (lo <= hi) {
		// 중간지점에서 가능하다면 lo = cuttingHeight로 설정
		long long cuttingHeight = (lo + hi) / 2; // 다음번에 자르기 시도할 높이
		if (parametricCheck(cuttingHeight)) {
			lo = cuttingHeight + 1;
			maxCuttingHeight = cuttingHeight;
		}
		else { //자르기 불가능한경우
			hi = cuttingHeight - 1; // 이게 왜 -1이냐
		}
	}
	return ;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> tree[i];
	}
	sort(tree, tree + N);
	parametricSearch();
	cout << maxCuttingHeight;
}