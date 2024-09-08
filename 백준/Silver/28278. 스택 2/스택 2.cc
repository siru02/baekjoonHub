#include <iostream>
#include <stack>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, command, value;
    stack<int> st;

    cin >> N;  // 명령어의 개수를 입력받음
    for (int i = 0; i < N; i++) {
        cin >> command;  // 명령어 입력
        if (command == 1) {
            cin >> value;  // 1인 경우에는 숫자를 추가로 입력받음
            st.push(value);
        }
        else if (command == 2) {
            if (st.empty()) {
                cout << -1 << '\n';
            } else {
                cout << st.top() << '\n';
                st.pop();
            }
        }
        else if (command == 3) {
            cout << st.size() << '\n';
        }
        else if (command == 4) {
            cout << (st.empty() ? 1 : 0) << '\n';
        }
        else if (command == 5) {
            if (st.empty()) {
                cout << -1 << '\n';
            } else {
                cout << st.top() << '\n';
            }
        }
    }

    return 0;
}
