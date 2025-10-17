#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>
using namespace std;

/*
* 로그가 주어졌을 때, 현재 회사에 있는 모든 사람을 구하는 프로그램
*/

int N;//도감에 수록되어 있는 포켓몬의 개수
int M; //내가 맞춰야하는 문제의 개수

unordered_map<string, int> m1; //키가 이름, 번호가 밸류
string names[1000005];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> names[i]; //i는 번호를 의미
        m1[names[i]] = i; //맵에 번호를 저장
    }
    //cout << "ans\n";
    for (int i = 0; i < M; ++i) {
        string query;
        cin >> query;
        if (isdigit(query[0])) { //숫자입력이라면
            cout << names[stoi(query)] << "\n";
        }
        else {
            cout << m1[query] << "\n";
        }
    }
}