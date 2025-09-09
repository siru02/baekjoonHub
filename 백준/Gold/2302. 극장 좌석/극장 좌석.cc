#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

/*
* 1명: 1
* 2명: (1,2) + (2,1)
* 3명: (1,2,3) (2,1,3) + (1,3,2)
* 4명: (1,2,3,4) (1,3,2,4) (2,1,3,4) + (2,1,4,3) (1,2,4,3)
* 5명: (1,2,3,4,5) (1,2,4,3,5) (1,3,2,4,5) (2,1,3,4,5) (2,1,4,3,5) + (1,2,3,5,4)
* (이전회차 맨 뒤에 새로운 숫자를 덧붙인 경우) + (새로운 숫자가 맨뒤에 위치하지 않은 경우)
* table[i] = table[i-1] + table[i-2]
*/

/*dp
* 1. 테이블 설정 -> table[i]는 i명을 배치하는 경우의 수
* 2. 점화식 설정 -> VIP가 있는 구간을 토대로 table[i] = table[a] + table[b] + table[c]
* -> 9명, 4와 7에 vip라면 구간1은 [1,3], 구간2는 [5,6], 구간3은 [8,9]로 만드는 조합이다
* 3. 초기값 설정 -> table[1] = 1;
*/

int table[42];
int VIP[42];
int arr[42];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        cin >> VIP[i];
    }

    VIP[M] = N + 1;
    table[0] = 1;
    table[1] = 1;
    for (int i = 2; i <= N; ++i) {
        table[i] = table[i - 1] + table[i - 2];
    }

    /*cout << "[table]\n";
    for (int i = 0; i < N; ++i) {
        cout << table[i] << "\n";
    }*/

    if (M == 0) {
        // VIP가 없는 경우
        cout << table[N] << "\n";
        return 0;
    }

    arr[0] = VIP[0] - 1;
    for (int i = 1; i <= M; ++i) {
        arr[i] = VIP[i] - VIP[i - 1] - 1;
    }
    int cnt = 1;
    for (int i = 0; i <= M; ++i) {
        //cout << arr[i] << " ";
        cnt *= table[arr[i]];
    }
    cout << cnt;
}