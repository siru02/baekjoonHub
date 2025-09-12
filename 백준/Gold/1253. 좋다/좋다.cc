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

// 이분탐색 풀이
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
    //sort(arr, arr + N);

    int idx = 0;
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            table[idx++] = { arr[i] + arr[j], i, j };
        }
    }
    sort(table, table + idx, [](sum a, sum b) {return a.val < b.val; });
    
    int cnt = 0;
    for (int i = 0; i < N; ++i) { //N개의 arr을 순회
        int target = arr[i]; // target자체가 자기 자신을 포함한 합일 수 있는 경우를 체크해야함
        int lo = -1, hi = idx;
        bool found = false;

        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            if (table[mid].val == target) {
                int left = mid;
                int right = mid;

                // 왼쪽으로 확장
                while (left >= 0 && table[left].val == target) {
                    if (table[left].idx1 != i && table[left].idx2 != i) {
                        found = true;
                        break;
                    }
                    left--;
                }
                // 오른쪽으로 확장
                while (!found && right < idx && table[right].val == target) {
                    if (table[right].idx1 != i && table[right].idx2 != i) {
                        found = true;
                        break;
                    }
                    right++;
                }
                break; // target 구간 다 확인했으니 종료
            }
            else if (table[mid].val > target) {
                hi = mid;
            }
            else {
                lo = mid;
            }
        }
        if (found) cnt++;
    }
    cout << cnt;
}
