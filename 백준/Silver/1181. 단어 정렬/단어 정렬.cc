#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
	if (a.length() == b.length()) {	// 길이가 같으면 
		return a < b;		// b가 사전순으로 a 보다 다음 순서가 되게 정렬 (= 사전 순으로 정렬)
	}
	else {					// 길이가 다르면
		return a.length() < b.length();	// b의 길이가 더 길도록 정렬 (=길이가 짧은 것이 앞으로)
	}
}

int main() {
	string str[20001];

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	
	sort(str, str + n, compare);

	for (int i = 0; i < n; i++) {
		if (str[i] == str[i - 1]) {	// 같은 단어가 여러 번 입력된 경우에는 한 번씩만 출력
			continue;
		}
		cout << str[i] << "\n";
	}


	return 0;
}