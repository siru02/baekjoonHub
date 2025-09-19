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
    /*for (int i = 0; i < N; ++i) {
        cout << A[i] << " ";
    }
    cout << "\n";*/

    long long zeroCnt = 0;
    // i < j < k 인덱스로 k를 이분탐색
    // 첫번째 원소를 고정하여 0부터 N-3까지 탐색
    for (int i = 0; i < N - 2 && A[i] <= 0; ++i) {
        // 두번째 원소를 고정하여 i+1부터 N-2까지 탐색
        for (int j = i + 1; j < N - 1; ++j) {
            zeroCnt += upper_bound(A + j + 1, A + N, -(A[i] + A[j])) - lower_bound(A + j + 1, A + N, -(A[i] + A[j]));
            /*int lo = j;
            int hi = N;
            int couple = A[i] + A[j];
            while (lo + 1 < hi) {
                int mid = (lo + hi) / 2;
                int val = couple + A[mid];
                if (val == 0) {
                    int st = mid, ed = mid;
                    while (st > j && A[st] == A[mid]) --st;
                    while (ed < N && A[ed] == A[mid]) ++ed;
                    while (++st < ed) {
                        //cout << "(" << i << "," << j << "," << st << "):";
                        //cout << "(" << A[i] << "," << A[j] << "," << A[st] << ")\n";
                        zeroCnt += 1;
                    }
                    break;
                }
                else if (val > 0) {
                    hi = mid;
                }
                else {
                    lo = mid;
                }
            }*/
        }
    }

    cout << zeroCnt;
}