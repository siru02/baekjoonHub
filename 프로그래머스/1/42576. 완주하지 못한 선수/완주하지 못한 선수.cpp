#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;
/*
* 이름목록 2개가 주어지는데 완주하지 못한 선수들의 이름을 return하라
*/


string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> m; //이름, 참여자 수
    for (auto it = participant.begin(); it != participant.end(); ++it) {
        if (m.find(*it) != m.end()){
            m[*it] += 1;
        }
        else {
            m[*it] = 1;
        }
    }
    for (auto it = completion.begin(); it != completion.end(); ++it) {
        if (m.find(*it) != m.end()){
            m[*it] -= 1;
            if (m[*it] == 0) {
                m.erase(*it);
            }
        }
    }
    string answer = m.begin()->first;
    return answer;
}