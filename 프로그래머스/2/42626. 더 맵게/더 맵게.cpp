#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
섞어서 새로운 스코빌지수의 음식 생성
모든 음식의 스코빌지수가 K이상이 될 때까지 반복해서 수행
*/

struct cmp {
    bool operator() (int a, int b) {
        return a > b;
    }
};

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, cmp> pq;
    
    for (auto tmp : scoville) {
        pq.push(tmp);
    }
    
    int cnt = 0;
    while (pq.size() > 1) {
        int a = pq.top();
        if (a >= K) return cnt;
        pq.pop();
        int b = pq.top() * 2;
        pq.pop();
        pq.push(a + b);
        ++cnt;
    }
    if (pq.top() >= K) return cnt;
    return -1;
}