#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

/*
* n번째 피보나치 수를 10억7로 나눈 나머지를 출력해야한다
* (a + b) % 10억 == {(a % 10억) + (b % 10억)} % 10억 이 성립하는가?
* a의 몫을 A, b의 몫을 B라고 생각하면, a = A * 10억 + aa, b = B * 10억 + bb
* (a + b) % 10억 = (aa + bb) % 10억
*/

/*
* fibo배열에 저장할 때, 10억으로 나눈 값들만 저장해도 되는가?
* 10억 * @에 해당하는 @는 이후 계산에서도 나머지연산으로 없어지므로 저장할때 % 10억을 해야한다
*/

int fibo[1000002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	fibo[0] = 0; fibo[1] = 1;
	for (int i = 2; i <= n; ++i) {
		fibo[i] = (fibo[i - 1] % 1000000007 + fibo[i - 2] % 1000000007) % 1000000007;
	}
	cout << fibo[n];
}