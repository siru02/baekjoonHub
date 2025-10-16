#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <vector>

using namespace std;

/*
* 오큰수
* 오큰수는 오른쪽에 있으면서 A[i]보다 큰 수중에서 가장 왼쪽에 있는 수
* 1. 배열을 순회하면서 A[i]에 해당하는 오큰수를 찾는다
* 2. 완전탐색은 O(N^2)
* 3. O(N)만에 끝내야한다
*/

int A[1000001];
int ans[1000001];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    stack<int> st;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // A[i]를 최대로 가지는 왼쪽 원소들을 구한다
    for (int i = 0; i < N; ++i) {
        // A[i]를 오큰수로 가지는 st원소들을 찾는다
        while (!st.empty() && A[st.top()] < A[i]) { // 스택은 단조 감소 상태
            ans[st.top()] = A[i];
            st.pop();
        }
        st.push(i);
    }
    // 못찾은 값들 처리
    while (!st.empty()) {
        ans[st.top()] = -1;
        st.pop();
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << " ";
    }
}