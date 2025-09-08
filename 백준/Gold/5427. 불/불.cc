#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

/*
* 불이 난 장소를 q에 넣는다
* bfs를 수행해서 몇초가 지난 시점에 불이 붙는지 visited에 작성한다
*/

int dx[4] = { 0, 1, 0 ,-1 };
int dy[4] = { 1, 0, -1, 0 };
queue<pair<int, int>> q;
queue<pair<int, int>> q2;

char map[1001][1001];
int visited[1001][1001];
int jihoon[1001][1001];

void setQ() {
    while (!q.empty()) {
        q.pop();
    }
    while (!q2.empty()) {
        q2.pop();
    }
}

void setVisited(int& w, int& h) {
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            visited[y][x] = 0;
            jihoon[y][x] = 0;
        }
    }
}

void setMap(int& w, int& h) {
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            cin >> map[y][x];
            if (map[y][x] == '*') {
                visited[y][x] = 1;
                q.push(make_pair(x, y));
            }
            else if (map[y][x] == '@') {
                q2.push(make_pair(x, y));
                jihoon[y][x] = 1;
            }
        }
    }
}

void bfs(int& w, int& h) {
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue; //범위 밖 제외
            if (visited[ny][nx] != 0) continue; // 이미 방문한 장소이므로 제외
            if (map[ny][nx] == '.' || map[ny][nx] == '@') { //불이 붙을 수 있는 장소
                visited[ny][nx] = visited[cur.second][cur.first] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

void printMap(int w, int h) {
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            cout << visited[y][x] << " ";
        }
        cout << "\n";
    }
}

void printJihoon(int w, int h) {
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            cout << jihoon[y][x] << " ";
        }
        cout << "\n";
    }
}

int bfs2(int w, int h) {
    while (!q2.empty()) {
        pair<int, int> cur = q2.front();
        q2.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) { //범위밖이면
                setQ();
                return jihoon[cur.second][cur.first];
            }
            if (jihoon[ny][nx] != 0) continue; // 이미 방문한 장소이므로 제외
            
            if (map[ny][nx] == '#') continue;
            int nextTime = jihoon[cur.second][cur.first] + 1;
            if (visited[ny][nx] == 0 || nextTime < visited[ny][nx]) { // 방문가능한 장소
                jihoon[ny][nx] = nextTime;
                q2.push(make_pair(nx, ny));
            }
        }
    }
    setQ();
    return -1;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int w, h, T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        cin >> w >> h;
        setVisited(w, h);
        setMap(w, h);
        bfs(w, h);
        //printMap(w, h);
        int ans = bfs2(w, h);
        //printJihoon(w, h);
        if (ans == -1) {
            cout << "IMPOSSIBLE\n";
        }
        else {
            cout << ans << "\n";
        }
    }
}