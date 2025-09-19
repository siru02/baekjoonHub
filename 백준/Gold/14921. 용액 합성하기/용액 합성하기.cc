#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int N;
int A[100002];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A, A + N);

    int ans = A[0] + A[1];
    for (int i = 0; i < N - 1; ++i) {
        int lower = lower_bound(A + i + 1, A + N, -A[i]) - A;
        if (lower != N) {
            int sum = A[i] + A[lower];
            if (abs(sum) < abs(ans))
                ans = sum;
        }

        // 바로 앞 원소가 아니라면
        if (lower != i + 1) {
            int sum = A[i] + A[lower - 1];
            if (abs(sum) < abs(ans)) {
                ans = sum;
            }
        }

    }
    cout << ans;
}