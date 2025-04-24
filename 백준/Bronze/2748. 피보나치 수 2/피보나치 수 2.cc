#include <iostream>

using namespace std;

long long fibo[100] = { 0 };

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n; cin >> n;
	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 2; i <= n; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		//cout << "fibo[" << i << "]: " << fibo[i] << "\n";
	}
	cout << fibo[n];
}