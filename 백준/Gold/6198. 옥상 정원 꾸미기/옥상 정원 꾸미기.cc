#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <vector>

using namespace std;

/*
* 도시에는 N개의 빌딩이 있다
* i번째 빌딩의 키가h[i], 모든 빌딩은 일렬, 오른쪽으로만 볼 수 있음
* i번째 빌딩 관리인이 볼 수 있는 다른 옥상 정원은 i+1 ~ N
* 자신이 위치한 빌딩보다 높거나 같은 빌딩이 있으면 못봄
*/

/*
* 단조 감소 스택으로 풀기
* 이전 건물들의 시야 상태를 스택 하나로 유지
* 스택에는 현재 시점에서 아직 시야가 막히지 않은 왼쪽 건물들
*/

int N;
int H[80002];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    long long ans = 0;
    stack<int> st;
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    st.push(H[0]);

    // for문으로 H의 원소들을 순회하며 각 원소를 볼 수 있는 원소들만을 stack에 남겨둔다
    for (int i = 1; i < N; ++i) {
        // 스택을 순회하면서 현재원소가 기존 스택원소(왼쪽의 빌딩들)보다 크면 제거
        while (!st.empty() && st.top() <= H[i]) {
            st.pop();
        }
        ans += st.size(); //현재 탑을 볼 수 있는 원소들만 stack에 남아있으므로
        st.push(H[i]);
    }
    cout << ans;
}