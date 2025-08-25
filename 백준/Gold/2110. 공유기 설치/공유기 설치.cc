#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

/*
* C개의 공유기를 N개의 집에 설치해서, 가장 인접한 두 공유기 사이의 거리를 최대로
* 공유기를 임의로 설치해서 가장 인접한 두 공유기 사이의 거리를 최대로
* 인접한 두 공유기는 한집간 거리가 아니라 여러 집 사이의 거리가 될 수 있음
*/

/*
* 1. N개의 집의 좌표를 정렬한다
* 2. parametricSearch로 -1 ~ 1000000001 사이를 탐색
* 3. parametricCheck로 mid에 해당하는 거리로 C개 이상의 공유기가 설치 가능한지 체크
*/

int N, C; // 집의개수, 공유기 개수
int house[200002];

// mid간격이상으로 C개의 공유기 배치가 가능한지 체크
bool parametricCheck(int mid) {
	int cnt = 1; //공유기는 최소 2개 이상이므로 1로 초기화해도 문제 없음
	int prev = house[0];
	int cur = house[1];
	for (int i = 1; i < N; ++i) {
		cur = house[i];
		if (cur - prev >= mid) { // 현재집과 이전 공유기집 사이의 거리가 mid이상이면
			++cnt; // 공유기 설치
			prev = cur; // 기록
			if (cnt >= C)
				return true;
		}
	}
	return false;
}

int parametricSearch() {
	int lo = -1; // 공유기 간 최소 거리
	int hi = 1000000001; // 공유기 간 최대 거리
	
	// mid이상의 간격으로 공유기가 C개 배치 가능한지 확인
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		//cout << "mid: " << mid << "\n";
		if (parametricCheck(mid)) { //dist[mid]간격으로 C개의 공유기 배치가 가능하면
			lo = mid; // lo이하간격으로는 배치가 가능함
		}
		else { // mid간격으로 C개의 공유기 배치가 불가능하면
			hi = mid; // hi이상 간격으로는 배치가 불가능함
		}
	}
	return lo; //lo이하에서 배치 가능, hi이상은 C개 배치 불가
}

// N + NlogN + N + (parametric)
int main() 
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> C;
	for (int i = 0; i < N; ++i) {
		cin >> house[i]; // 각 집의 좌표를 저장
	}
	sort(house, house + N); // NlogN

	cout << parametricSearch();
}