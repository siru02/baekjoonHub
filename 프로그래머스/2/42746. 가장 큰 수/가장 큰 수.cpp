#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& a, const string& b) {
    return a + b > b + a; // 더 큰 조합이 앞에 오도록
}

string solution(vector<int> numbers) {
    vector<string> nums(numbers.size());
    int idx = 0;
    for (auto num : numbers) {
        nums[idx++] = to_string(num);
    }
    sort(nums.begin(), nums.end(), cmp);
    
    string answer = "";
    for (auto num : nums) {
        answer += num;
    }
    if (!answer.empty() && answer[0] == '0') return "0";
    return answer;
}