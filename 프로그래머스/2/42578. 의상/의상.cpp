#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/*
* 의상 종류가 하나라도 다르면 다른 방법으로 옷을 입은것
*/

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> m; //key:옷종류, value=개수
    for (auto at : clothes) {
        m[at[1]]++; //옷종류에 해당하는 옷 개수 추가
    }
    int answer = 1;
    for (auto tmp : m) {
        answer *= (tmp.second + 1);
    }
    return answer - 1;
}