#include <vector>
#include <unordered_set>
using namespace std;

/*
* N마리중 절반을 가져가도 좋다
* 포켓몬은 종류에 따라 번호를 붙여 구분
* 4마리의 포켓몬 [3,1,2,3] -> 3번종류 포켓몬 2마리
* 다양한 종류의 포켓몬을 원함
* 가장 많은 종류의 포켓몬을 선택하는 방법을 찾아 포켓몬 종류의 개수를 리턴
*/

// 인풋은 포켓몬 종류번호
int solution(vector<int> nums)
{
    int cnt = nums.size() / 2;
    unordered_set<int> s;
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        s.insert(*it);
    }
    if (s.size() >= cnt)
        return cnt;
    return s.size();
}