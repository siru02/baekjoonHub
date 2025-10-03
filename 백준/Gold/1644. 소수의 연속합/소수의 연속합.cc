#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

/*
* 하나 이상의 연속된 소수의 합으로 나타낼 수 있는 자연수들
* 자연수가 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 구하라
*/

/*
* 알고리즘
* 이분탐색? 불가능할듯
* 투포인터?
* 양쪽에서 조인다
*/

int N;

vector<int> getPrimes() {
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
    return primes;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    if (N < 2) { cout << 0; return 0; }
    vector<int> primes = getPrimes();
    int M = (int)primes.size();

    int st = 0, ed = 0;
    int sum = primes[0];
    int cnt = 0;
    while (st <= ed && primes[ed] <= N) {
        //cout << "sum: " << sum << "\n";
        if (sum == N) {
            //cout << 1 << "\n";
            ++cnt;
            sum -= primes[st];
            ++ed;
            ++st;
            if (ed == M) break;
            sum += primes[ed];
        }
        else if (sum < N) {
            //cout << 2 << "\n";
            ++ed;
            if (ed == M) break;
            sum += primes[ed];
        }
        else {
            //cout << 3 << "\n";
            sum -= primes[st];
            ++st;
            if (st == M) break;
        }
    }
    cout << cnt;
}