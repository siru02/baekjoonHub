#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

/* 투포인터
* 2개의 포인터(start, end)를 적절하게 움직여서 O(N)만에 탐색수행
* 하나의 용액을 고정(i)
* 나머지 두 개를 (left, right)를 투 포인터로 움직여서 0에 가까운 합 탐색
* 
* 이분탐색
* lo, hi로 기준을 정하여 정렬된 배열을 이분탐색
* 세 용액중에서 두 개를 고정한다(i, j)
* 0에 가깝게 되는 k를 이분탐색을 통해 찾는다
*/

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<long long> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.begin() + N);

    long long ans[3];
    long long minVal = 4e18;

    // 이분탐색 풀이 -> 두개의 원소 정해놓고, 탐색
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            // (i, j)에 해당하는 최적해 k를 찾는다
            int lo = j, hi = N;
            while (lo + 1 < hi) {
                int mid = (lo + hi) / 2;
                long long curVal = arr[i] + arr[j] + arr[mid];

                if (llabs(curVal) < llabs(minVal)) {
                    minVal = curVal;
                    ans[0] = arr[i];
                    ans[1] = arr[j];
                    ans[2] = arr[mid];
                }

                if (curVal > 0) {
                    hi = mid;
                }
                else {
                    lo = mid;
                }
            }
        }
    }
    

    /*// 투포인터 풀이
    for (int i = 0; i < N - 2; ++i) {
        int left = i + 1;
        int right = N - 1;
        while (left < right) {
            long long curVal = arr[i] + arr[left] + arr[right];
            if (llabs(curVal) < minVal) {
                minVal = llabs(curVal);
                ans[0] = arr[i];
                ans[1] = arr[left];
                ans[2] = arr[right];
            }
            if (curVal < 0) {
                ++left;
            }
            else {
                --right;
            }
        }
    }*/

    sort(ans, ans + 3);
    cout << ans[0] << " " << ans[1] << " " << ans[2];
}