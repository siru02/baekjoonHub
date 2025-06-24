#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <iomanip>

using namespace std;

int main()
{
	string str;
	map<string, int> dict;
	map<string, int>::iterator it;
	int totalCnt = 0;
	while (getline(cin, str)) {
		++totalCnt;
		it = dict.find(str);
		if (it != dict.end()) {
			int cnt = dict[str];
			dict[str] = cnt + 1;
		}
		else {
			dict[str] = 1;
		}
	}

	for (auto element : dict) {
		double percentage = (double)element.second / totalCnt * 100;
		cout << element.first << " " << fixed << setprecision(4) << percentage << "\n";
	}
}