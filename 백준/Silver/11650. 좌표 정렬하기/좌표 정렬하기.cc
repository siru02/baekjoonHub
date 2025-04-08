#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
람다식으로 표현하여 x좌표 우선으로 정렬하되, y좌표도 고민
람다식에서 true를 리턴한다는건 순서가 이미 올바르다는 의미
*/

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	vector<pair<int, int>> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first)
			return a.second < b.second;
		return a.first < b.first;
	});
	for (int i = 0; i < n; i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
}