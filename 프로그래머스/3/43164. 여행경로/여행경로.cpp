#include <string>
#include <vector>
#include <algorithm>

/*
* 첫 원소부터 시작해서 dfs로 수행해야할듯 백트래킹사용
*/

using namespace std;

bool flag = false;
vector<string> answer;

// 현재 장소를 기준으로 사용가능한 티켓을 찾아서 dfs수행
void dfs(string cur, vector<bool>& used, vector<string>& ans, vector<vector<string>>& tickets, int usedTicketCnt) {
    if (usedTicketCnt == tickets.size()) {
        answer = ans;
        flag = true;
        return;
    }
    
    for (int idx = 0; idx < tickets.size(); ++idx) {
        if (used[idx] == true) continue;
        if (tickets[idx][0] != cur) continue;
        
        used[idx] = true; //티켓사용표기
        ans.push_back(tickets[idx][1]);
        dfs(tickets[idx][1], used, ans, tickets, usedTicketCnt + 1); //다음 장소로 이동
        if (flag) return;
        
        ans.pop_back(); //경로제외
        used[idx] = false; //티켓미사용표기
    }
    
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    vector<bool> used(tickets.size(), false);
    
    vector<string> ans;
    ans.push_back("ICN");
    dfs("ICN", used, ans, tickets, 0);
    return answer;
}