#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

/*
* 합이 0이되는 3인조를 찾아라
* 3개를 더해서 0이 되도록 하는것을 구하는 문제로 투포인터와 이분탐색 모두 가능
*/

/*
* 투포인터
* A를 정렬 -> O(N)
* A를 순회 -> O(N)
* 매 순회에서 투 포인터로 0에 가까운 것 탐색 -> O(N)
* st=i+1, ed=N-1로 설정 -> A는 오름차순으로 정렬되어있으므로
* 첫 원소 i에 대해 최소가 되는 st와 ed를 구한다
*/

/*
* 이분탐색
* A를 정렬 -> O(N)
* 하나의 원소를 고정하고, 나머지 2개의 원소를 이분탐색해야한다
*/

int N;
int A[10002];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A, A + N);

    long long zeroCnt = 0;
    // i < j < k 인덱스로 k를 이분탐색
    // 첫번째 원소를 고정하여 0부터 N-3까지 탐색
    for (int i = 0; i < N - 2 && A[i] <= 0; ++i) {
        int st = i + 1;
        int ed = N - 1;
        while (st < ed) {
            int sum = A[i] + A[st] + A[ed];
            if (sum == 0) {
                // 양끝이 같은값이면 사이 범위의 개수를 모두 더한다
                if (A[st] == A[ed]) {
                    long long cnt = ed - st + 1;
                    zeroCnt += cnt * (cnt - 1) / 2; // nC2계산
                    break;
                }
                else {
                    // A[st]와 A[ed]가 다른 값이면 A[st]와 같은 cntL개수, A[ed]와 같은 cntR개수 카운트
                    long long cntL = 1, cntR = 1;

                    while (st + 1 < ed && A[st] == A[st + 1]) {
                        ++st; ++cntL;
                    }
                    while (ed - 1 > st && A[ed] == A[ed - 1]) {
                        --ed; ++cntR;
                    }
                    zeroCnt += cntL * cntR;
                    ++st;
                    --ed;
                }
            }
            else if (sum > 0) {
                --ed;
            }
            else {
                ++st;
            }
        }
    }

    cout << zeroCnt;
}