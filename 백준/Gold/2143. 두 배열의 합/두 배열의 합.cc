#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
#include <bitset>

using namespace std;
/*
* A의 부 배열과 B의 부 배열의 합을 더해서 T가 되는 모든 부 배열 쌍의 개수를 구하시오
* sumA + sumB = T인 쌍을 구하라
* sumA, sumB와 같은 부분합 리스트를 생성해야한다
* sumA 배열과 sumB 배열을 구하고 이를 정렬
* 투포인터 혹은 이분탐색을 통해 합이 T인 지점을 찾음
*/

int T, n, m;
int A[1002];
int B[1002];
int sumA[500502];
int sumB[500502];
int N, M;

// 부분합 계산하는 함수
void partialSum() {
    N = 0; //부분합 인덱스
    for (int st = 0; st < n; ++st) {
        int sum = 0;
        for (int ed = st; ed < n; ++ed) {
            sum += A[ed];
            sumA[N] = sum;
            ++N;
        }
    }
    sort(sumA, sumA + N);

    M = 0; //부분합 인덱스
    for (int st = 0; st < m; ++st) {
        int sum = 0;
        for (int ed = st; ed < m; ++ed) {
            sum += B[ed];
            sumB[M] = sum;
            ++M;
        }
    }
    sort(sumB, sumB + M);

    //for (int i = 0; i < N; ++i) {
    //    cout << sumA[i] << " ";
    //}
    //cout << "\n";
    //for (int i = 0; i < M; ++i) {
    //    cout << sumB[i] << " ";
    //}
}

// hi는 target과 값이 일치하는 시작 인덱스
int lowerBound(int* arr, int len, int target) {
    int lo = -1, hi = len;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (arr[mid] >= target) {
            hi = mid;
        }
        else {
            lo = mid;
        }
    }
    return hi;
}

int upperBound(int* arr, int len, int target) {
    int lo = -1, hi = len;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (arr[mid] > target) {
            hi = mid;
        }
        else {
            lo = mid;
        }
    }
    return hi;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> T >> n;
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    cin >> m;
    for (int i = 0; i < m; ++i)
        cin >> B[i];

    partialSum();
    
    long long cnt = 0;
    // 모든 sumA의 원소에 대해서 sumB를 이분탐색하여 sumA + sumB = T인 경우 찾기
    for (int i = 0; i < N; ++i) {
        int upper = upperBound(sumB, M, T - sumA[i]);
        int lower = lowerBound(sumB, M, T - sumA[i]);
        //cout << upper << lower << "\n";
        cnt += (upper - lower);
    }
    cout << cnt;
}