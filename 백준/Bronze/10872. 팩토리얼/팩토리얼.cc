#include <iostream>

using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	long long n;
	long long num = 1;
	cin >> n;
	while (n) {
		num *= n--;
	}
	cout << num;
}