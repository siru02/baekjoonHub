#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

/*
* 전개도
* 1. 밑바닥 면을 선정하고 법선벡터를 (1,0,0),(0,1,0),(0,0,1) 3가지로 설정
* 2. 양옆을 x축방향으로 법선벡터를 설정한다
* 3. 위아래를 y축 방향으로 법선벡터를 설정한다
* 4. (-1,0,0)의 양옆에는 법선벡터로 z축 설정, 위아래에는 y축설정
* 5. 
*/

/*
* 알고리즘
* 1. map을 탐색하며 시작 원소를 찾는다
* 2. 시작면을 법선벡터를 (1,0,0),(0,1,0),(0,0,1)로 설정 bfs로 인접면들의 법선을 구한다
* 3. 이후로는 이게 실제로 접히는 모양인지 확인해야함
* 4. 이웃으로 갈 때, rotateFrame으로 (u, v, n)전체를 회전하며 전파
* 5. 이미 방문한 칸에 다른 경로로 도달하면, 저장된 프레임과 같아야 함
*/

typedef struct vec {  
    int x, y, z;
    bool operator== (const vec& other) const {
        return x == other.x && y == other.y && z == other.z;
    }
}vec;

typedef struct frame { 
    vec u, v, n; 
    bool operator==(const frame& other) const {
        return u == other.u && v == other.v && n == other.n;
    }
}frame; // 오른쪽면, 위쪽면, 법선 -> 법선이 같다고 해서, 같은 면이라고 생각할 수 없음

int map[6][6];
int visited[6][6];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 }; //상하좌우순서
frame boardF[6][6]; // 각 칸에 프레임을 저장한다
int normalUsed[6]; //법선벡터 6개 모두 존재하는지 확인
int ans;

/*
* x와 z위에 있는건 y축 법선
* x와 z양옆은 서로 바뀜
*/

// 벡터를 입력으로 받아서 맞는 인덱스 반환
int normalIndex(const vec& n) {
    if (n.x == 1 && n.y == 0 && n.z == 0) return 0; // +x
    if (n.x == -1 && n.y == 0 && n.z == 0) return 1; // -x
    if (n.x == 0 && n.y == 1 && n.z == 0) return 2; // +y
    if (n.x == 0 && n.y == -1 && n.z == 0) return 3; // -y
    if (n.x == 0 && n.y == 0 && n.z == 1) return 4; // +z
    if (n.x == 0 && n.y == 0 && n.z == -1) return 5; // -z
    return -1; // 잘못된 법선
}

inline vec negv(const vec& a) { return { -a.x, -a.y, -a.z }; }

// 현재 프레임을 방향에 맞게 회전시킨다
frame rotateFrame(const frame& cur, int dir) {
    frame nx = cur;
    if (dir == 0) {        // 상: 로컬 u축 +90°
        nx.n = cur.v;
        nx.v = negv(cur.n);
        nx.u = cur.u;
    }
    else if (dir == 1) { // 하: 로컬 u축 -90°
        nx.n = negv(cur.v);
        nx.v = cur.n;
        nx.u = cur.u;
    }
    else if (dir == 2) { // 좌: 로컬 v축 +90°
        nx.n = negv(cur.u);
        nx.u = cur.n;
        nx.v = cur.v;
    }
    else {               // 우: 로컬 v축 -90°
        nx.n = cur.u;
        nx.u = negv(cur.n);
        nx.v = cur.v;
    }
    return nx;
}


int bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[y][x] = 1; //현재 좌표를 방문했다는 증거
    int faces = 1;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) { //상하좌우 순서로 탐색
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= 6 || ny >= 6) continue; //범위체크
            if (map[ny][nx] == 0) continue; // 빈공간 패스

            frame nextFrame = rotateFrame(boardF[cur.second][cur.first], i);
            int nIdx = normalIndex(nextFrame.n);
            if (visited[ny][nx] == 1) { // 방문한 좌표의 경우 프레임 검사를 해야한다
                if (!(boardF[ny][nx] == nextFrame))
                    return -1; //기존에 기록해둔 프레임과 다르면 종료
            }
            else { //처음 방문하는 좌표인 경우
                visited[ny][nx] = 1; // 방문확인
                boardF[ny][nx] = nextFrame; // 보드에 기록
                q.push(make_pair(nx, ny));
                ++faces;

                // 정답 기록
                int normalIdx = normalIndex(nextFrame.n);
                normalUsed[normalIdx] = map[ny][nx]; // 면의 번호를 법선벡터 배열에 저장
            }
        }
    }
    if (faces != 6) return -1;
    for (int i = 0; i < 6; ++i) if (!normalUsed[i]) return -1;
    return 0;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (map[i][j] == 1) { // 시작면
                boardF[i][j] = { {0, -1, 0}, {1, 0, 0}, { 0, 0, 1 } }; // 시작면에 로컬프레임 설정
                normalUsed[4] = 1;
                int flag = bfs(j, i);
                if (flag == -1) cout << 0;
                else cout << normalUsed[5];
                return 0;
            }
        }
    }
}