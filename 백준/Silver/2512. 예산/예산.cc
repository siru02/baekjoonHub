#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

/*
* 정해진 총액 이하에서 가능한 최대의 총 예산
* 모든 요청 가능 -> 요청 금액 그대로 배정
* 모든 요청x -> 특정한 정수 상한액을 계산하여 그 이상인 예산 요청에는 상한액 배정
*/

int N, M;
int budget[10002];

bool parametricCheck(int mid) {
	int sum = 0;
	for (int i = 0; i < N; ++i) {
		if (budget[i] > mid) {
			sum += mid;
		}
		else {
			sum += budget[i];
		}
	}
	return sum <= M;
}

int lowerBound() {
	int lo = -1; int hi = budget[N - 1] + 1;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (parametricCheck(mid)) { // 조건 만족
			lo = mid;
		}
		else { //조건 불만족시에는 hi를 감소시킨다
			hi = mid;
		}
	}
	return lo; //lo와 hi는 1개 차이나는 지점까지 탐색하므로
	// lo는 조건을 만족하는 가장 큰 인덱스
	// hi는 조건을 만족하지 않는 가장 작은 인덱스
}


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> budget[i];
	cin >> M;
	sort(budget, budget + N);
	cout << lowerBound();
}