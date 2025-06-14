#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int board[10][10];
int paper[6] = {0, 5, 5, 5, 5, 5}; // 색종이 크기별 남은 개수
int ans = 1e9; // 최소 개수

// (x, y)를 시작으로 size x size 색종이를 붙일 수 있는지 확인
bool canAttach(int x, int y, int size) {
    if (x + size > 10 || y + size > 10) return false;

    for (int i = x; i < x + size; ++i)
        for (int j = y; j < y + size; ++j)
            if (board[i][j] != 1) return false;

    return true;
}

// 색종이 붙이기 or 떼기
void setPaper(int x, int y, int size, int val) {
    for (int i = x; i < x + size; ++i)
        for (int j = y; j < y + size; ++j)
            board[i][j] = val;
}

// 다음 (x, y)부터 DFS 수행
void dfs(int x, int y, int used) {
    if (x >= 10) {
        ans = min(ans, used);
        return;
    }

    if (y >= 10) {
        dfs(x + 1, 0, used);
        return;
    }

    // 가지치기
    if (used >= ans) return;

    if (board[x][y] == 1) {
        for (int size = 5; size >= 1; --size) {
            if (paper[size] > 0 && canAttach(x, y, size)) {
                setPaper(x, y, size, 0);
                paper[size]--;
                dfs(x, y + 1, used + 1);
                paper[size]++;
                setPaper(x, y, size, 1); // 백트래킹
            }
        }
    } else {
        dfs(x, y + 1, used); // 다음 칸으로
    }
}

int main() {
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            cin >> board[i][j];

    dfs(0, 0, 0);
    cout << (ans == 1e9 ? -1 : ans) << '\n';
    return 0;
}
