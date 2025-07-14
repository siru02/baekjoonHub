#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
* K개의 랜선을 잘라서, N개 이상의 랜선을 만든다
* 최적화 문제 -> N개이상 만들 수 있는 랜선의 최대 길이를 구하기
* 결정문제 -> 랜선의 길이가 X일 때 랜선이 N개 이상인지 아닌지
*/

int LAN[10002];

// length 기준으로 자를 때, N개보다 많이 만드는게 가능한지 체크하는 함수
bool checkAvailable(int length, int N, int K) {
	int cnt = 0;
	for (int i = 0; i < K; ++i) {
		cnt += LAN[i] / length;
	}
	if (cnt >= N)
		return true;
	return false;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int K, N; cin >> K >> N;
	for (int i = 0; i < K; ++i) {
		cin >> LAN[i];
	}
	sort(LAN, LAN + K);

	// binary search
	long long hi = LAN[K - 1]; //가장 긴 랜선의 길이
	long long lo = 1;
	long long lan = 1;
	while (lo <= hi) {
		long long mid = (lo + hi) / 2;
		if (checkAvailable(mid, N, K)) { // mid길이로 N개이상 생성이 가능한 경우
			lan = mid;
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}
	cout << lan;
}