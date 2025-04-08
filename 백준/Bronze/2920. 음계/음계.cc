#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/*
람다식으로 표현하여 x좌표 우선으로 정렬하되, y좌표도 고민
람다식에서 true를 리턴한다는건 순서가 이미 올바르다는 의미
*/

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

    vector<int> input(8);
    for (int i = 0; i < 8; ++i)
        cin >> input[i];

    vector<int> ascending = { 1,2,3,4,5,6,7,8 };
    vector<int> descending = { 8,7,6,5,4,3,2,1 };

    if (input == ascending)
        cout << "ascending" << endl;
    else if (input == descending)
        cout << "descending" << endl;
    else
        cout << "mixed" << endl;

}