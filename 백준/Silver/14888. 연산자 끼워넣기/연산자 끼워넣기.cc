#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int arr[12];
int availableOperator[4];
int maxVal = -2147483648;
int minVal = 2147483647;
int N;

/*
* 수열 입력 -> 4개 연산(+, -, *, /)의 개수 입력
* 앞에서부터 순서대로 계산
*/

/*
* 알고리즘
* 1. dp-여래개의 하위 문제를 먼저 풀고 그 결과를 쌓아 올려 주어진 문제를 해결
* 2. 완전탐색 - 각 자리에 올 수 있는 경우를 대입하여 계산
* 3. 완전탐색을 해야겠다 -> N중 for문을 이용해서 각 자리에 올 수 있는 연산자를 하나씩 호출
*/

int operation0(int depth, int prevVal) {
	return prevVal + arr[depth + 1];
}
int operation1(int depth, int prevVal) {
	return prevVal - arr[depth + 1];
}
int operation2(int depth, int prevVal) {
	return prevVal * arr[depth + 1];
}
int operation3(int depth, int prevVal) {
	return prevVal / arr[depth + 1];
}

int (*operations[])(int, int) = { operation0, operation1, operation2, operation3 };

void recursive(int depth, int prevVal) {
	if (depth == N - 1) {
		if (maxVal < prevVal)
			maxVal = prevVal;
		if (minVal > prevVal)
			minVal = prevVal;
		return;
	}
	for (int opIdx = 0; opIdx < 4; ++opIdx) {
		if (availableOperator[opIdx] > 0) { // 연산 가능한 경우
			availableOperator[opIdx] -= 1;

			int curVal = operations[opIdx](depth, prevVal);
			recursive(depth + 1, curVal);

			availableOperator[opIdx] += 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	for (int i = 0; i < 4; ++i)
		cin >> availableOperator[i];

	//maxVal = arr[0];
	//minVal = arr[0];
	recursive(0, arr[0]);
	cout << maxVal << "\n" << minVal;

}