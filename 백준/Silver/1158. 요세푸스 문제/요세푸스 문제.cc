#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int queue[5001] = {0};
	int n, k;
	cin >> n >> k;

	int cur = 1;
	cout << "<";
	for (int i = 0; i < n; i++){ //n개의 원소를 삭제하는 루프
		int cnt = 0; //건너뛴 횟수
		while (cnt != k) { //k칸씩 건너뛰므로
			//cout << "loop: " << cur << ", " << cnt << "\n";
			if (queue[(cur + cnt) % n] == 0) //아직 지워지지않은 자리라면
				cnt++;
			else if (++cur == n + 1){ // 이미 지워진 자리라면 cur증가시키고 범위내부인지 확인
				cur = 1;
			}
		}
		cur = (cur + cnt - 1) % n ? (cur + cnt - 1) % n : n;
		queue[cur % n] = 1; //지웠다는 플래그 생성
		cout << cur;
		if (i != n - 1)
			cout << ", ";
	}
	cout << ">";
}