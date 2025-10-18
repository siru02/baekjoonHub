#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end()); //정렬
    int N = citations.size(); //논문 개수
    int answer = 0;
    
    for (int i = 0; i < N; ++i) {
        int H = min(citations[i], N - i); //인용수가 많은 경우, 남은 논문수가 많은 경우 모두 포함해야함
        answer = max(answer, H);
    }
    return answer;
}