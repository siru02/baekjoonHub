#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int N;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    vector<int> ans(N, 0);
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i]; // 높이 저장
    }

    stack<pair<int, int>> st; // (높이, 인덱스)

    // 왼쪽부터 처리
    for (int i = 0; i < N; i++) {
        // 현재 탑보다 낮거나 같은 탑들을 제거
        // 제일 오른쪽 탑을 대상으로 왼쪽의 탑부터 비교하는데,
        // 현재 탑보다 낮으면 미래애 올 오른쪽 탑들의 레이저도 수신할 수 없으므로
        while (!st.empty() && st.top().first < arr[i]) {
            st.pop();
        }

        // 수신할 탑의 인덱스 저장
        if (st.empty()) {
            ans[i] = 0;
        }
        else {
            ans[i] = st.top().second;
        }

        // 현재 탑을 스택에 추가
        st.push({ arr[i], i + 1 });
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}