#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (auto cmd : commands) {
        vector<int> tmp(array.begin() + cmd[0] - 1, array.begin() + cmd[1]);
        sort(tmp.begin(), tmp.end());
        /*for (int i : tmp){
            cout << i << " ";
        }
        cout << "\n";*/
        answer.push_back(tmp[cmd[2] - 1]);
    }
    return answer;
}