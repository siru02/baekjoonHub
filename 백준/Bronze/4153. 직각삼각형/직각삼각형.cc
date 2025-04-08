#include <iostream>

using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	while (1) {
		int x, y, z;
		cin >> x >> y >> z;
		if (x == 0 && y == 0 && z == 0)
			break;
		if (z * z == x * x + y * y)
			cout << "right\n";
		else if (x * x == y * y + z * z)
			cout << "right\n";
		else if (y * y == x * x + z * z)
			cout << "right\n";
		else
			cout << "wrong\n";
	}
}