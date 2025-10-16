#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long double distance(long long x, long long y) {
    return sqrt(x*x + y*y);
}

// 투포인터로 접근, x=0, y=d부터 카운트해서 x에 대해 가능한 y를 찾으면 d/k만큼 추가

/*long long solution(int k, int d) {
    long long answer = 0;
    long long x = 0, y = d;
    while (x <= y) {
        long double dist = distance(x, y);
        cout << "(" << x << ", " << y << ") = " << dist << "\n";
        if (dist > d) { // 현재 거리가 더 멀다면 y를 감소시킨다
            y -= k;
        }
        else { // 현재 거리가 조건에 부합한다면 x를 증가시킨다
            x += k;
            answer += y / k;
            if (x != y)
                answer += y / k; // y축의 방향에서 카운트 하는 경우도 포함
            else
                answer += 
            cout << "ans= "<< answer << "\n";
        }
    }
    return answer;
}*/

long long solution(int k, int d) {
    long long K = k, D = d;
    long long ans = 0;

    // y를 d 이하의 가장 큰 k의 배수로 맞춤
    long long y = (D / K) * K;

    for (long long x = 0; x <= D; x += K) {
        // 현재 x에서 조건을 만족할 때까지 y를 내림
        while (y >= 0 && x * x + y * y > D * D) y -= K;
        if (y < 0) break;                // 이후 x에서도 더 이상 유효한 y가 없음
        ans += (y / K) + 1;              // b = 0..(y/k) ⇒ +1 필수
    }
    return ans;
}