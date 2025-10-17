#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
* 전화번호가 다른 번호의 앞의 일부분인지 확인하는것
* 접두어가 존재하면 false리턴
* stack으로 판별할까?
*/

bool solution(vector<string> phone_book) {
    bool answer = true;
    int size = phone_book.size();
    sort(phone_book.begin(), phone_book.end()); // 사전순정렬
    
    
    for (int i = 0; i < size - 1; ++i) {
        int j = i + 1;
        if (phone_book[i].size() > phone_book[j].size()) {
            int idx = 0;
            for (char ch : phone_book[j]) {
                if (ch != phone_book[i][idx]) {
                    break;
                }
                ++idx;
            }
            if (idx == phone_book[j].size())
                return false;
        }
        else {
            int idx = 0;
            for (char ch : phone_book[i]) {
                if (ch != phone_book[j][idx]) {
                    break;
                }
                ++idx;
            }
            if (idx == phone_book[i].size())
                return false;
        }
    }
    return true;
}