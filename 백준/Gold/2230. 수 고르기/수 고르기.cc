#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

/* 투포인터
* 2개의 포인터(start, end)를 적절하게 움직여서 O(N)만에 탐색수행
*/

/*
* 배열에서 차이가 M이상인 두 수의 차중 가장 작은것을 구하기
* 1. 배열을 정렬한다
* 2. end를 증가시키면서 M이상인 구간이 나오면 diff에 저장하고, start 증가
* 3. start가 N에 도달하면 탈출
*/

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
   
    int N, M; // N개의 정수, M이상의 차이
    cin >> N >> M;

    vector<int> A(N);
    int start = 0, end = 0;
    int minDiff = 2147483647; // 두 수의 차이중 최소값을 저장할 변수
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.begin() + N);
    while (start < N && end < N) {
        int diff = A[end] - A[start];
        if (diff < M) {
            ++end;
        }
        else {
            if (diff < minDiff) {
                minDiff = diff;
            }
            ++start;
        }
    }
    cout << minDiff;
}