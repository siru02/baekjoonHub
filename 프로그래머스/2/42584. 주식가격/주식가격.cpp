#include <string>
#include <vector>
#include <stack>
#include <iostream>

/*
* 가격이 떨어지지 않은 기간이 몇초인지 return
* 스택에 인덱스를 단조증가형태로 저장
* 단조증가가 깨지는 지점을 만나면 index차이만큼 저장
*/

using namespace std;

vector<int> solution(vector<int> prices) {
    stack<int> st;
    int n = prices.size();
    vector<int> ans(n, 0);
    
    st.push(0);
    for (int idx = 1; idx < n; ++idx) {
        while (!st.empty()) {
            if (prices[st.top()] <= prices[idx]) break;
            //가격이 떨어진 경우
            ans[st.top()] = idx - st.top();
            st.pop();
        }
        st.push(idx);
    }
    for (int i = 0; i < n; ++i) {
        if (ans[i] == 0) {
            ans[i] = n - i - 1;
        }
    }
    return ans;
}