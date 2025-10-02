#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
#include <bitset>

using namespace std;

/*
* 가로로 N개의 칸
* 첫째 줄에서 적절하게 뽑아서 아래줄에서 최대한 많이 뽑도록 하는 방법
* 첫째줄의 숫자를 뽑으면 아래줄의 숫자와 연결되어 이어짐
*/

/*
* 아이디어
* 사이클이 존재하는 원소쌍들을 찾아서 개수를 센다
*/

int line[102];
int N;
int ans[102];
int ansCnt = 0;

bool checkNodeInAns(int idx) {
    int cur = line[idx];
    for (int i = 0; i < ansCnt; ++i) {
        if (ans[i] == cur)
            return true;
    }
    return false;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> line[i];
    }

    for (int i = 1; i <= N; ++i) {
        if (checkNodeInAns(i)) continue; // 이미 순회한 노드라면 제외
        int nodes[102]; //방문한 점을 저장하는 배열
        int startNode = line[i];
        int idx = 0;
        nodes[idx] = startNode;
        for (int depth = 0; depth < N - 1; ++depth) {
            int nextNode = line[nodes[idx]]; //현재노드의 line가 다음 점이다
            if (startNode == nextNode) { // 시작점으로 돌아오는 사이클이 생성된 경우
                for (int j = 0; j <= idx; ++j) {
                    ans[ansCnt++] = nodes[j]; //사이클원소를 추가
                }
                break;
            }
            nodes[++idx] = nextNode;
         }
    }

    sort(ans, ans + ansCnt);
    cout << ansCnt << "\n";
    for (int i = 0; i < ansCnt; ++i) {
        cout << ans[i] << "\n";
    }
}