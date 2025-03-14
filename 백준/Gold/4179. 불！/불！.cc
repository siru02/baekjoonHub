#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define X first
#define Y second

string maze[1000];
int times[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int R, C;
    cin >> R >> C;
    queue<pair<int,int>> Q;
    pair<int, int> J;
    for(int i=0; i<R; i++) {
        cin >> maze[i];
        for(int j=0; j<C; j++) {
            if(maze[i][j] == 'F') Q.push({i, j});
            else {
                times[i][j] = -1;
                if(maze[i][j] == 'J') J = {i, j};
            }
        }
    }

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int d=0; d<4; d++) {
            int nx = cur.X + dx[d];
            int ny = cur.Y + dy[d];
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(maze[nx][ny] == '#') continue;
            if(times[nx][ny] != -1) continue;
            times[nx][ny] = times[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    times[J.X][J.Y] = 0;
    Q.push(J);
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        int nxt = times[cur.X][cur.Y] + 1;
        for(int d=0; d<4; d++) {
            int nx = cur.X + dx[d];
            int ny = cur.Y + dy[d];
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) {
                cout << nxt;
                return 0;
            }
            if(maze[nx][ny] == '#') continue;
            if(times[nx][ny] != -1 && times[nx][ny] <= nxt) continue;
            times[nx][ny] = nxt;
            Q.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE";
}