#include <iostream>

using namespace std;

/*
* dp푸는법
1. 테이블 정의하기
2. 점화식
3. 초기항 설정하기
*/

/*
1. 테이블: 2 x k크기의 직사각형을 타일로 채우는 방법
2. 점화식: An = A(n-1) + A(n-2)
3. 초기항: A(1) =1, A(2) = 2, A(3) = A(2) * 2
A(3) = 1 + 2 = 3 // 2개짜리 0개, 2개짜리 1개
A(4) = 1 + 3 + 1 // 2개짜리0개, 2개짜리1개, 2개짜리 2개
A(9) = 55

*/
int A[1001] = { 0 };

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n; cin >> n;
	A[1] = 1;
	A[2] = 2;

	for (int i = 3; i <= n; ++i) {
		A[i] = (A[i - 1] + A[i - 2]) % 10007;
	}
	cout << A[n] % 10007;
}