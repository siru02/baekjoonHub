#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

/*
* i번 강의와 j번 강의를 같은 블루에이에 녹화하려면 i와 j사이의 모든 강의도 같은 블루레이
* 순서대로 저장되어야 한다
* M개의 블루레이에 모든 강의 동영상을 녹화한다
* 이분탐색으로 M개의 블루레이에 저장가능한 최소저장크기(mid)를 구한다
*/

int N, M; // 강의 수, 블루레이 수
int lecture[100002];
int lo = 0, hi = 1;
/*
* 저장크기는 1이상이지만 lo를 0으로 설정하는 이유는 조건을 만족하는 시작범위를 hi가 가리키고
* lo는 조건을 만족하지 않는 가장 끝 범위를 가리키기 때문
* hi가 최대크기+1인 이유는 조건을 만족하지 않는 범위를 판별하기 위해서
*/

bool parametricCheck(int mid) {
	int diskCnt = 1;
	int lectureIdx = 0;
	int recordLength = 0;
	for (; lectureIdx < N; ++lectureIdx) {
		recordLength += lecture[lectureIdx];
		if (recordLength > mid) { // 디스크에 기록할수있는 범위를 초과하면
			lectureIdx -= 1; //기록idx감소
			diskCnt += 1; // 디스크개수 증가
			recordLength = 0; //디스크크기 초기화
		}
	}
	//cout << "[parametric_check]\n" << "mid: " << mid << ", diskCnt: " << diskCnt;
	//cout << "valid: " << (diskCnt <= M) << "\n";
	return diskCnt <= M;
}

int main() 
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> lecture[i];
		hi += lecture[i];
		if (lo < lecture[i])
			lo = lecture[i];
	}
	lo -= 1; //lo는 최소값-1 부터 시작한다

	// lo와 hi는 1차이나는 시점에서 탈출 -> 연속된 수라면 hi가 조건을 만족하는 시작범위이므로
	int mid = (lo + hi) / 2;
	while (lo + 1 < hi) {
		mid = (lo + hi) / 2;
		if (parametricCheck(mid)) { //저장가능한경우 -> hi를 낮춘다
			hi = mid;
		}
		else { // 저장 불가능한 경우 -> lo를 증가시킨다
			lo = mid;
		}
		//cout << "(lo, hi) = " << lo << " " << hi << "\n\n";
	}
	cout << hi;
}