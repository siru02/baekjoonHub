#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[10] = { 0 };

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr[i] = num;
	}

	int cnt = 0;
	while (--n >= 0) {
		int i = k / arr[n];
		cnt += i;
		k -= arr[n] * i;
	}
	cout << cnt;
}