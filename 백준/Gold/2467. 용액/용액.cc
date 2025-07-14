#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
* 두 개의 서로 다른 용액을 혼합하여 특성값이 0에 가까운 용액을 만들어내는 두 용액을 찾아라
* 1. solution 배열을 정렬한다
* 2. 하나의 용액을 선정 N * 나머지 용액을 이분탐색 log N
*/

int solution[100002];
int minDiff = 2147483647;
int s1, s2;

// abs(diff)가 0에 가까우면 s1, s2를 갱신
void upperBoundBinarySearch(int targetIdx, int N) {
	int lo = targetIdx + 1;
	int hi = N - 1;
	while (lo <= hi) { // ==지점까지 탐색해야한다
		int mid = (lo + hi) / 2;
		int diff = solution[targetIdx] + solution[mid];

		if (abs(diff) < minDiff) {
			minDiff = abs(diff);
			s1 = targetIdx;
			s2 = mid;
		}

		if (diff == 0) {
			return;
		}
		else if (diff > 0) { // 차이가 양수인 경우에는 적어도 오른쪽 양수중에는 비교대상이 없음
			hi = mid - 1;
		}
		else { // 차이가 음수인 경우에는 적어도 왼쪽 음수중에는 비교대상이 더 없음
			lo = mid + 1;
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N; cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> solution[i];
	sort(solution, solution + N);

	for (int i = 0; i < N; ++i) {
		upperBoundBinarySearch(i, N);
	}
	cout << solution[s1] << " " << solution[s2];
}