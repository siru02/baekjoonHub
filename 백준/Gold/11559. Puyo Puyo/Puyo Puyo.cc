#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int visited[13][7];
char board[13][7];
int chain = 0;

queue<pair<int, int>> q;

void setVisited() {
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 6; ++j)
            visited[i][j] = 0;
    }
}

int bfs(int x, int y) {
    vector<pair<int, int>> toDelete;
    q.push(make_pair(x, y));
    char puyo = board[y][x];
    int cnt = 1;
    visited[y][x] = 1;
    toDelete.push_back(make_pair(x, y));

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;
            if (nx < 0 || ny < 0 || nx >= 6 || ny >= 12) continue;
            if (puyo != board[ny][nx]) continue;
            if (visited[ny][nx]) continue;
            q.push(make_pair(nx, ny));
            toDelete.push_back(make_pair(nx, ny));
            visited[ny][nx] = 1;
            ++cnt;
        }
    }
    if (cnt >= 4) {
        for (pair<int, int> cur : toDelete) {
            board[cur.second][cur.first] = '.';
        }
        return 1;
    }
    return 0;
}

void gravity() {
    for (int x = 0; x < 6; ++x) {
        char tmp[13];
        for (int y = 11; y >= 0; --y) {
            tmp[y] = board[y][x];
        }
        int idx = 0;
        for (int y = 11; y >= 0; --y) {
            if (tmp[11 - y] != '.')
                board[idx++][x] = tmp[11 - y];
        }
        for (int y = idx; y < 12; ++y) {
            board[y][x] = '.';
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string str;
    for (int i = 11; i >= 0; --i) {
        cin >> str;
        for (int j = 0; j < 6; ++j) {
            board[i][j] = str[j];
        }
    }
    while (1) {
        int puyopuyo = 0;
        for (int y = 0; y < 12; ++y) {
            for (int x = 0; x < 6; ++x) {
                if (visited[y][x] == 1 || board[y][x] == '.') continue;
                puyopuyo += bfs(x, y);
            }
        }
        if (puyopuyo == 0) break;
        gravity();
        ++chain;
        setVisited();
    }
    cout << chain;
}