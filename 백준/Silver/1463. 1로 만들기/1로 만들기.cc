#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int MEM[1000001] = { 0 }; //메모이제이션

void recursive(int n, int cur) {
	if (cur == n + 1) {
		return;
	}
	int cnt = 2147483647;
	if (cur % 3 == 0) {
		cnt = MEM[cur / 3];
	}
	if (cur % 2 == 0) {
		cnt = cnt > MEM[cur / 2] ? MEM[cur / 2] : cnt;
	}
	cnt = cnt > MEM[cur - 1] ? MEM[cur - 1] : cnt;
	MEM[cur] = cnt + 1;
	//cout << "MEM[" << cur << "]: " << MEM[cur] << "\n";
	recursive(n, cur + 1);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n; cin >> n;
	MEM[0] = -1;
	recursive(n, 1);
	cout << MEM[n];
}