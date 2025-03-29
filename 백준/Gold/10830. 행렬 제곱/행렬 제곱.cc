#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
아이디어
1. 행렬의 곱을 제곱식으로 구현한다
2. a^2n = a^n * a^n이고, a^k에서 k가 홀수라면 a^k = a^(k/2) * a^(k/2) * a이다
3. 이는 일반숫자 뿐 아니라 행렬의 곱에서도 적용되는 원리이다
*/

// matrix[y][x]의 값을 계산하는 함수
long long calculate(int x, int y, int n, vector<long long> &cur1, vector<long long> &cur2)
{
	long long val = 0;
	for (int i = 0; i < n; i++) {
		val += cur1[y * n + i] * cur2[i * n + x];
	}
	return val % 1000;
}

// 행렬 제곱을 계산하는 함수
vector<long long> matrix_pow(int n, vector<long long> &cur) {
	vector<long long> cur_pow(n * n); //이거를 어떻게 리턴할거냐 //일차원 벡터로 만들어서 그냥 돌릴까
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cur_pow[y * n + x] = calculate(x, y, n, cur, cur);
		}
	}
	return cur_pow;
}

// 행렬의 곱을 계산하는 함수
vector<long long> matrix_mul(int n, vector<long long> &cur1, vector<long long>& cur2) {
	vector<long long> cur_mul(n * n);
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cur_mul[y * n + x] = calculate(x, y, n, cur1, cur2);
		}
	}
	return cur_mul;
}

// b는 행렬의 차수를 의미
vector<long long> recursive(int n, long long b, vector<long long> &prev, vector<long long>& matrix)
{
	if (b == 1) {
		return prev;
	}
	// 입력을 제곱한다
	vector<long long> cur = matrix_pow(n, prev);
	
	/*
	cout << "depth : " << b << "\n";
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			cout << cur[y * n + x] << " ";
		}
		cout << "\n";
	}
	*/

	if (b % 2 == 0) {
		//recursive(n, b / 2, matrix_pow(n, cur));
		return recursive(n, b / 2, cur, matrix);
	}
	else {
		//cur = matrix_mul(n, cur, matrix);
		//return recursive(n, b / 2, cur, matrix);
		cur = recursive(n, b / 2, cur, matrix);
		//return matrix_mul(n, cur, matrix);
		return matrix_mul(n, cur, prev); //왜 이렇지?
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	long long n, b, tmp;
	cin >> n >> b;
	vector<long long> matrix(n * n);

	//입력부
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			cin >> tmp;
			matrix[n * y + x] = tmp % 1000;
		}
	}

	vector<long long> ans = recursive(n, b, matrix, matrix);

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			cout << ans[y * n + x] << " ";
		}
		cout << "\n";
	}
}