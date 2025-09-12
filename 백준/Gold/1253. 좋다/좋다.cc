#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

/*
* N개의 수 중에서 좋은 수가 몇개인지
* 수의 위치가 다르면 값이 같아도 다른 수
*/

/*
* 이분탐색
* 두 수의 합으로 이루어진 배열 생성 -> O(N^2)
* 정렬 -> O(N^2 * log N)
* 초기 배열을 순회하며 정렬된 배열을 이분탐색 -> O(N * N * log N)
* 어떤 수가 다른 두 수의 합으로 이루어져야한다
*/

/*
* 투포인터
* st, ed정하고 st에 대한 최적 ed를 찾기
* target고정하고, st하나 고정하여 두 수의 합으로 표현되는지 확인
*/

typedef struct sum {
    int val;
    int idx1, idx2;
}sum;

int N;
int arr[2002];
sum table[4000002];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    
    int cnt = 0;

    for (int i = 0; i < N; ++i) {
        int target = arr[i];
        int st = 0, ed = N - 1;
        while (ed > st) {
            int sum = arr[st] + arr[ed];
            if (target == sum) {
                if (st != i && ed != i) {
                    ++cnt;
                    break;
                }
                else if (st == i) ++st;
                else if (ed == i) --ed;
            }
            else if (target > sum) {
                ++st;
            }
            else {
                --ed;
            }
        }
    }
    
    cout << cnt;
}