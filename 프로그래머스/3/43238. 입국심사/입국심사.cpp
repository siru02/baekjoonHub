#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
//시간 T를 주면 심사관들이 처리할 수 있는 인원 수가 단조 증가한다는 점을 이용
/*
* 가장 앞에 있는 사람은 비어있는 심사대로 가서 심사
* 더 빨리 끝나는 심사대가 있으면 기다렸다가 그곳으로 가서 심사
* 모든 사람이 심사를받는데 걸리는 시간을 최소화 
-> 
*/

//mid시간동안 심사가능한 인원이 n명 이상이면 ok
bool parametricCheck(vector<int>& times, int n, long long mid) {
    long long num = 0;
    for (auto time : times) {
        num += mid / time;
        if (num >= n)
            return true;
    }
    return false;
}

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    long long lo = 0, hi = LLONG_MAX;
    while (lo + 1 < hi) {
        long long mid = (lo + hi) / 2;
        if (parametricCheck(times, n, mid)) { //수행가능
            hi = mid;
        }
        else {
            lo = mid;
        }
    }
    return hi;
}