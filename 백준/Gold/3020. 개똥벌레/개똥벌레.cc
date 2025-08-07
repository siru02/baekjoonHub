#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

/*
* 동굴길이N미터, 높이 H
* 종유석과 석순이 번갈아서 등장
* 개똥벌레가 파괴해야하는 장애물의 최솟값과 구간의 개수
* 누적합을 이용해 해결
* celing배열과 floor배열을 받아서 각 높이마다 충돌 개수를 설정
* 각 배열의 idx에해당하는 높이로 들어왔을 때, 천장과 바닥에서 충돌하는 개수를 저장
*/

int N, H;
vector<int> floorCnt, ceilingCnt;
int minCollisionCnt = 200001;

int main() 
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> H;
	floorCnt.assign(H + 2, 0);
	ceilingCnt.assign(H + 2, 0);
	int tmp;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		if (i & 1) { // 종유석
			ceilingCnt[tmp] += 1;
		}
		else { // 석순
			floorCnt[tmp] += 1;
		}
	}

	// 누적합
	for (int i = H - 1; i >= 1; --i) {
		floorCnt[i] += floorCnt[i + 1]; //최고 높이부터 시작해서, 자기보다 높은 높이의 석순이 있다면 개수 추가
		ceilingCnt[i] += ceilingCnt[i + 1]; //자기보다 높은 길이의 종유석이 있다면 개수 추가
	}

	int minCollision = N + 1;
	int cnt = 0;
	for (int height = 1; height <= H; ++height) {
		// 종유석은 천장으로부터의 길이를 뺀 높이까지는 충돌하지 않음
		// 석순은 바닥으로부터 시작한 높이까지 충돌
		int crash = floorCnt[height] + ceilingCnt[H - height + 1];
		if (crash < minCollision) {
			minCollision = crash;
			cnt = 1;
		}
		else if (crash == minCollision) {
			cnt++;
		}
	}
	cout << minCollision << ' ' << cnt << '\n';
}