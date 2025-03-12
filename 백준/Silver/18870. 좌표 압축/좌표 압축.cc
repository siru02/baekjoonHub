#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N; cin >> N;
	vector<int> v(N);
	vector<int> mem(N);

	int value;
	for (int i = 0; i < N; i++) {
		cin >> value;
		v[i] = value;
		mem[i] = value;
	}
	sort(v.begin(), v.end()); //벡터정렬

	//중복요소 삭제
	vector<int>::iterator last = unique(v.begin(), v.end());
	v.erase(last, v.end());

	//map
	unordered_map<int, int> index_map;
    for (int i = 0; i < v.size(); i++) {
        index_map[v[i]] = i;  // 값과 그 값을 찾을 위치 저장
    }

    // mem 벡터에 있는 값들이 v 벡터에서 몇 번째 인덱스에 있는지 출력
    for (int i = 0; i < N; i++) {
        cout << index_map[mem[i]] << " ";
    }
}