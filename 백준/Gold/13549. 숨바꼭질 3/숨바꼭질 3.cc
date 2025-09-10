#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

/*
* 
*/

int N, K;
int X[100003];
int dx[2] = { 1, -1 };
queue<int> q;

bool teleport(int nx, int time) {
    if (nx == 0) {
        q.push(nx);
        X[nx] = time;
        return K == nx;
    }

    while (nx <= 100000) {
        //cout << "nx=" << nx << "\n";
        if (X[nx] == 0) {
            q.push(nx);
            X[nx] = time;
        }
        if (K == nx)
            return true;
        nx *= 2;
    }
    return false;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> K; // 수빈이 위치, 동생 위치
    
    if (teleport(N, 1)) {
        cout << 0;
        return 0;
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        //cout << "cur=" << cur << "\n";

        // 앞 뒤
        for (int i = 0; i < 2; ++i) {
            int nx = cur + dx[i];
            if (nx < 0 || nx >= 100000) continue;
            if (X[nx] != 0) continue;

            bool flag = teleport(nx, X[cur] + 1);
            if (flag) {
                cout << X[nx] - 1;
                return 0;
            }
        }
    }
}