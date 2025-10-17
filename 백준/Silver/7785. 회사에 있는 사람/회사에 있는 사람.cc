#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

/*
* 로그가 주어졌을 때, 현재 회사에 있는 모든 사람을 구하는 프로그램
*/

int N;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    map<string, bool, greater<string>> m; //key 역순 정렬
    //vector<pair<string, int>> v(m.begin(), m.end()); 이런 방법도 가능
    cin >> N;

    for (int i = 0; i < N; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        if (s2 == "enter") { //맵에 없으면
            m[s1] = true;
        }
        else {
            m.erase(s1);
        }
    }

    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->second == true)
            cout << it->first << "\n";
    }
}