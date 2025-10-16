#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long D = d, K = k;
    
    // x = 0, K, 2K, 3K, ... 형태로 순회
    for (long long x = 0; x <= D; x += K) {
        // x가 주어졌을 때 가능한 최대 y 값 계산
        long long maxYSquared = D * D - x * x;
        long long maxY = (long long)sqrt(maxYSquared);
        
        // y는 0, K, 2K, ... 형태이므로 maxY 이하의 K의 배수 개수를 센다
        answer += (maxY / K) + 1;
    }
    
    return answer;
}