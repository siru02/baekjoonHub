#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

/*
* 같은 색 뿌요가 4개이상 상하좌우로 연결되어 있으면 연결된 같은 색 뿌요가 터지며 1연쇄
* 중력으로 위의 뿌요들이 떨어지면서 연쇄가 늘어남
* 터질 수 있는 뿌요가 여러 그룹이 있다면 동시에 터지고, 이는 한번의 연쇄로 취급
* 상대방의 필드가 주어졌을 때, 연쇄가 몇 번 연속으로 일어날지 계산해라
*/

/*
* 1. 입력 받기
* 2. 제일 아랫줄부터 탐색해서, bfs로 터질애들 찾아서 터트리기
* 3. 중력효과로 아래로 떨구기
*/

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int visited[13][7];
char board[13][7];
int height[7];
int chain = 0;

queue<pair<int, int>> q;

void printBoard() {
    for (int y = 11; y >= 0; --y) {
        for (int x = 0; x < 6; ++x) {
            cout << board[y][x];
        }
        cout << "\n";
    }
}

void setVisited() {
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 6; ++j)
            visited[i][j] = 0;
    }
}

// 현재 좌표를 기준으로 puyo가 가능한지 체크
int bfs(int x, int y) {
    //cout << "bfs start(" << x << ", " << y << ")\n";
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
            if (nx < 0 || ny < 0 || nx >= 6 || ny >= 12) continue; //범위 밖
            if (puyo != board[ny][nx]) continue; // 같지 않은 puyo는 제외
            if (visited[ny][nx]) continue; // 이미 방문체크한 puyo는 제외

            // 처음 방문하는 연결된 뿌요라면
            q.push(make_pair(nx, ny));
            toDelete.push_back(make_pair(nx, ny));
            visited[ny][nx] = 1;
            ++cnt;
            //cout << cnt << "\n";
        }
    }
    if (cnt >= 4) {
        for (pair<int, int> cur : toDelete) {
            board[cur.second][cur.first] = '.'; //빈공간으로 바꾼다
        }
        return 1;
    }
    return 0;
}

// 중력으로 아래로 떨어지는 효과
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
    for (int i = 11; i >= 0; --i) { //11번째 줄이 제일 윗줄, 0이 제일 아랫줄
        cin >> str;
        for (int j = 0; j < 6; ++j) {
            board[i][j] = str[j];
        }
    }

    // 루프
    while (1) {
        int puyopuyo = 0;
        for (int y = 0; y < 12; ++y) {
            for (int x = 0; x < 6; ++x) {
                if (visited[y][x] == 1) continue; // 방문한 장소라면
                if (board[y][x] == '.') continue; // 빈공간 패스
                puyopuyo += bfs(x, y); // 뿌요뿌요했으면 1리턴받음
            }
        }
        if (puyopuyo == 0) break; //한번도 뿌요뿌요하지 않으면 탈출
        gravity();
        ++chain;
        //cout << "chain: " << chain << "\n";
        //printBoard();
        setVisited();
    }
    //printBoard();
    //printBoard();
    cout << chain;
}