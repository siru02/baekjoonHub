#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

/*
* 두 선분이 실제로 겹치는지
* 두 선분이 한 점에서 만나는지
*/

struct Point {
	long long x, y;
};

bool operator<(const Point& a, const Point& b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

bool operator>(const Point& a, const Point& b) {
	if (a.x != b.x) return a.x > b.x;
	return a.y > b.y;
}

int ccw(Point a, Point b, Point c) {
	long long val = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	if (val > 0) return 1; // 반시계
	if (val < 0) return -1; // 시계
	return 0; // 일직선
}

bool isIntersect(Point a, Point b, Point c, Point d) {
	int ab = ccw(a, b, c) * ccw(a, b, d); // AB 양옆에 C와 D가 있는지
	int cd = ccw(c, d, a) * ccw(c, d, b); // CD 양옆에 A와 B가 있는지

	if (ab == 0 && cd == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return !(b < c || d < a);
	}
	return ab <= 0 && cd <= 0;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	Point A, B, C, D;
	cin >> A.x >> A.y >> B.x >> B.y;
	cin >> C.x >> C.y >> D.x >> D.y;

	if (isIntersect(A, B, C, D)) {
		cout << "1";
	}
	else {
		cout << "0";
	}
}