#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

/*
* 첫째 줄에 입력으로 주어진 M개의 수에 대해서, 
* 각 수가 적힌 숫자 카드를 상근이가 몇 개 가지고 있는지를 공백으로 구분해 출력한다.
* lower_bound를 통해 각 숫자에 맞는 위치를 찾는다
* index를 1씩 증가시키며 card[idx] > num일때까지 cnt증가
*/

int N, M;
vector<int> card;

bool Check(int idx, int num) {
	if (card[idx] >= num)
		return true;
	return false;
}

int upperBoundBinarySearch(int num) {
	int lo = -1;
	int hi = N;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (card[mid] > num)
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}

int lowerBoundBinarySearch(int num) {
	int lo = -1;
	int hi = N;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (Check(mid, num)) { // card[mid] >= num -> 왼쪽 탐색
			hi = mid;
		}
		else { // card[mid] < num -> 오른쪽 탐색
			lo = mid;
		}
	}
	/*
	* 반복문 수행 결과 lo는 card[idx] >= num이 되는 경계가 된다
	* 즉 card[lo] < num, card[hi] >= num인 상황
	*/
	return hi;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N; int num;
	for (int i = 0; i < N; ++i) {
		cin >> num;
		card.push_back(num);
	}
	sort(card.begin(), card.end());

	cin >> M;
	for (int i = 0; i < M; ++i) {
		int m; cin >> m;
		int idx = lowerBoundBinarySearch(m);
		int cnt = 0;
		int left = lowerBoundBinarySearch(m);
		int right = upperBoundBinarySearch(m);
		cout << right - left << ' ';
	}

}