#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

/*dp
* 1. 테이블 설정 -> index원을 만들 수 있는 경우의 수
* 2. 점화식 설정 -> table[i] += table[i - coin[j]]
* -> 금액 i를 만들기 위해서 coin[j]를 사용한다고 하면 
* table[i-coin[j]]에 i-coin[j]금액을 생성하는 방법이 저장되어있음
* 3. 초기값 설정 -> table[0] = 1
*/

/*
* table[value]의 경우의수는 
* table[value-coin[idx]]에서 coin[idx]를 사용하지 않고, 만드는 경우의 수를 더한 것
* 예를 들어 1, 2, 5 이라는 coin이 있다면
* table[1] = 1
* table[2] = 2(1 1, 2) -> 2라는 동전을 새로 사용
* table[3] = 2(1 1 1, 1 2); -> 변화 없음
* table[4] = 3(1 1 1 1, 1 1 2, 2 2) -> 2라는 동전을 새로 사용
* table[5] = 4(1 1 1 1 1, 1 1 1 2, 1 2 2, 5) -> 5라는 동전을 새로 사용
* table[6] = 5(1 1 1 1 1 1, 1 1 1 1 2, 1 1 2 2, 1 5, 2 2 2) -> 2로만 구성된거 새로 사용
* table[7] = 5(1 1 1 1 1 1 1, 1 1 1 1 1 2, 1 1 1 2 2, 1 1 5, 1 2 2 2)
* table[8] = 6(1 1 1 1 1 1 1 1, 1 1 1 1 1 1 2, 1 1 1 1 2 2, 1 1 1 5, 1 1 2 2 2, 2 2 2 2)
* table[9] = 7(1 1 1 1 1 1 1 1 1, 1 1 1 1 1 1 1 2, 1 1 1 1 1 2 2, 1 1 1 1 5, 1 1 1 2 2 2, 1 2 2 2 2, 2 2 5)
*/

int N, K;
int coin[102];
int table[10002]; // index원을 만드는데 필요한 경우의 수 

// table[i]는 특정 코인을 사용하지 않는 경우 + 특정 코인을 적어도 1개 사용하는 경우
// coin을 순회하며 특정 coin을 사용해서 i원을 만들 수 있는 table[i]를 생성한다
// 

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> coin[i];
        //table[coin[i]] = 1; // 초기값
    }
    table[0] = 1;

    // coin배열을 순회
    for (int i = 0; i < N; ++i) {

        // coin[i]원 이상을 순회하며, j원을 만들 수 있는 경우를 추가
        for (int j = coin[i]; j <= K; ++j) {
            table[j] += table[j - coin[i]];
        }
    }

    cout << table[K];
}