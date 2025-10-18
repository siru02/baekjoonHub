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

struct cmp {
    // 비교연산으로 (a,b)가 true를 반환하면 a의 우선순위가 b보다 낮아 교환해야한다
    bool operator() (int a, int b) {
        if (abs(a) > abs(b)) return true;
        if (abs(a) == abs(b)) {
            return a > b;
        }
        return false;
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
        if (x == 0) { //우선순위 큐에서 제거
            if (!pq.empty()) {
                cout << pq.top() << "\n";
                pq.pop();
            }
            else cout << 0 << "\n";
        }
        else { //우선순위큐에 추가
            pq.push(x);
        }
    }
}