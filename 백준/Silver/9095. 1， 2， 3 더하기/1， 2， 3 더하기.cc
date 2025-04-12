#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int MEM[1000001] = { 0 }; //메모이제이션

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int cnt; cin >> cnt;
	int n;
	MEM[1] = 1;
	MEM[2] = 2;
	MEM[3] = 4;
	for (int i = 4; i <= 12; i++) {
		MEM[i] = MEM[i - 1] + MEM[i - 2] + MEM[i - 3];
	}
	for (int i = 0; i < cnt; i++) {
		cin >> n;
		cout << MEM[n] << "\n";
	}
}