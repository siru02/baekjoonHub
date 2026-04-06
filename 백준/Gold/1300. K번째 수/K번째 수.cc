#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>
using namespace std;

/*
* NxN 배열 A를 만들었음
* 배열에 들어있는 수 A[i][j] = i * j 이다.
* 일차원 배열 B에 넣고 정렬했을 때, B[k]를 구하라
* 배열 a와 b의 인덱스는 1부터 시작한다
*/

/*
1 2 3 4 5
2 4 6 8 10
3 6 9 12 15
4 8 12 16 20
5 10 15 20 25
*/
// 1 2 2 3 3 4 4 4 5 5 6 6 8 8 9 10 10 12 12 15 15 16 20 25

/*
* B나 A를 선언할 필요가 없다 -> 이분탐색으로 k번째가 무엇인지 찾으면 되기 때문
* x이하인 원소의 개수가 몇개인지 탐색하는 이분탐색 필요
* i행에서 x이하인 원소의 개수 = min(x / i, N)개
*/

long long N; // 10000 이하
long long k; // 찾고자 하는 인덱스

// 현재 인덱스보다 작은 수가 몇개인지 반환
long long parametric(long long curIdx) {
	long long cnt = 0;
	for (long long i = 1; i <= N; ++i) {
		cnt += min(curIdx / i, N); //현재 행에서 k보다 작거나 같은 원소의 개수는 k/행번호 혹은 N개 이므로
	}
	return cnt;
}

// 이분탐색으로 k개 
// upper 현재 인덱스의 수보다 k개를 초과하는 
// lower 현재 인덱스의 수보다 k개 이상인
long long parametricSearch() {
	long long lo = 0;
	long long hi = N * N + 1;
	while (lo + 1 < hi) {
		long long mid = lo + (hi - lo) / 2;
		long long cnt = parametric(mid); //mid번째 수보다 작은 숫자의 개수를 반환

		// k가 cnt개수보다 크거나 같으면 -> 더 많은 수를 탐색해야한다
		if (cnt < k) {
			lo = mid;
		}
		else {
			hi = mid;
		}
	}
	return hi;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> k;

	cout << parametricSearch();
}