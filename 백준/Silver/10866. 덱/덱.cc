#include <queue>
#include <string>
#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

queue<int> Q;
deque<int> DQ;

int main()
{
	fastio;
	int n;
	cin >> n;
	string str;
	int num;
	while (n--)
	{
		cin >> str;
		if (str == "push_front")
		{
			cin >> num;
			DQ.push_front(num);
		}
		else if (str == "push_back")
		{
			cin >> num;
			DQ.push_back(num);
		}
		else if (str == "pop_front")
		{
			cout << (DQ.empty() ? -1 : DQ.front()) << '\n', DQ.size() ? DQ.pop_front() : void();
			//cout << (Q.empty() ? -1 : Q.front()) << '\n', Q.empty() ? void() : Q.pop();
		}
		else if (str == "pop_back")
		{
			cout << (DQ.empty() ? -1 : DQ.back()) << '\n', DQ.size() ? DQ.pop_back() : void();
		}
		else if (str == "empty")
		{
			cout << DQ.empty() << '\n';
		}
		else if (str == "front")
		{
			cout << (DQ.empty() ? -1 : DQ.front()) << '\n';
		}
		else if (str == "back")
		{
			cout << (DQ.empty() ? -1 : DQ.back()) << '\n';
		}
		else if (str == "size")
		{
			cout << DQ.size() << '\n';
		}
	}
}