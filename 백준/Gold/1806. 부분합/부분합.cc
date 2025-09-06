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
* 연속된 수들의 부분합 중에 그 합이 S 이상이 되는 것 중, 가장 짧은 것의 길이
* 1. 투포인터->start, end를 조절해서 각 start별로 S이상이 되는 최소부분을 구하기
* 2. 이분탐색->각 start별로(O(N)) 이분탐색(O(logN))을 수행하여 구간합이 S이상이 되는 lower_bound찾기
*/

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, S;
    cin >> N >> S;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    //sort(arr.begin(), arr.begin() + N, [](int a, int b) {if (a > b) return true; return false; });
    int minLen = 100001;
    int len = 1;
    int sum = arr[0];

    int start = 0, end = 0;
    // 모든 start에 대해서 구간합을 만족하는 최소 인덱스(end)를 구한다
    while (start < N && end < N) {
        if (sum >= S) { // 구간합이 최소를 만족하면
            if (len < minLen)
                minLen = len;
            //cout << "start[" << arr[start] << "]'s Len = " << len << ", end = " << arr[end] << "\n";
            sum -= arr[start]; //sum에서 제외할 원소의값을 제거
            start += 1;
            len -= 1;
            if (end < start) {
                end = start;
                len = 1;
            }
        }
        else {
            end += 1;
            len += 1;
            if (end < N)
                sum += arr[end];
        }
    }

    if (minLen == 100001)
        cout << 0;
    else
        cout << minLen;
}