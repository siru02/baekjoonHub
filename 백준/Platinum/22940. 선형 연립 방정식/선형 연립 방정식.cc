#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

double matrix[10][10];
double ans[10];

// 피벗이 0이면 아래 행에서 교환
void pivotIfZero(int N, int x) {
	if (matrix[x][x] == 0) {
		for (int i = x + 1; i < N; ++i) {
			if (matrix[i][x] != 0) {
				swap(matrix[x], matrix[i]);
				return;
			}
		}
	}
}

// x번째 변수를 삭제한다
void elimination(int N, int x) {
	pivotIfZero(N, x);

	// 피벗을 1로 정규화
	double pivot = matrix[x][x];
	for (int j = x; j <= N; ++j) {
		matrix[x][j] /= pivot;
	}

	// i는 삭제할 행 번호, 아래 행을 소거
	for (int i = x + 1; i < N; ++i) {
		double factor = matrix[i][x];
		for (int j = x; j <= N; ++j) {
			matrix[i][j] -= matrix[x][j] * factor;
		}
	}

}

// 역방향 대입
void backSubstitute(int N) {
	for (int i = N - 1; i >= 0; --i) {
		double val = matrix[i][N];
		for (int j = i + 1; j < N; ++j) {
			val -= matrix[i][j] * ans[j];
		}
		ans[i] = val / matrix[i][i];
	}
}

void gausianElimination(int N) {
	for (int x = 0; x < N - 1; ++x) {
		elimination(N, x);
	}
}

int main() 
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N; cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N + 1; ++j) {
			cin >> matrix[i][j];
		}
	}

	gausianElimination(N);
	backSubstitute(N);

	for (int i = 0; i < N; ++i)
		cout << (int)(ans[i] + 0.5) << " "; // 정수 반올림 출력
}