#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>
using namespace std;

/*
* 정렬된 두 묶음의 숫자카드
* 이 둘을 합치기 위해서는 A + B번의 비교가 필요
* 많은 묶음의 숫자카드가 있다
* 이 중 2개씩 골라합쳐나간다면 고르는 순서에 따라 비교횟수가 달라짐
* N개의 숫자 카드 묶음의 크기가 주어질 때, 최소 몇번의 비교가 필요한지 구해라
*/

/*
* 알고리즘
* 작은묶음부터 순서대로 더해야 비교횟수가 최소화될거같다
*/

struct cmp {
    bool operator() (int a, int b) {
        return a > b;
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    priority_queue<int, vector<int>, cmp> pq;
    int N; cin >> N;
    int x;
    for (int i = 0; i < N; ++i) {
        cin >> x;
        pq.push(x);
    }

    int cnt = 0;
    while (!pq.empty() && pq.size() != 1) {
        int a = pq.top();
        pq.pop();

        int b = 0;
        if (!pq.empty()) {
            b = pq.top();
            pq.pop();
        }
        cnt += (a + b);
        pq.push(a + b); // (a+b)개짜리 카드뭉치가 추가된다
    }
    cout << cnt;
}