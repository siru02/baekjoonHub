#include <iostream>
#include <algorithm>

using namespace std;

/*
재귀로 
*/
long long input;

long long recursive(int a, int b, int c)
{
	//마지막에 도달했을 때
	if (b == 1)
		return a % c; //입력받은 수에 나머지연산을 해서 리턴한다

	long long cur = recursive(a, b / 2, c); //시간복잡도를 반으로 줄인다
	cur = (cur * cur) % c; //오버플로우 방지
	if (b % 2 == 0) {
		return cur;
		//return (cur * cur) % c;
	}
	else { //b가 홀수인경우
		return (cur * a) % c;
		//return (cur * cur * a) % c;
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	long long a, b, c;
	cin >> a >> b >> c;
	input = a;

	cout << recursive(a, b, c);
	/*
	1. a^b % c = k의 k를 구하기
	2. a^b = {a^(b/2) * a^(b/2)} % c와 같다
	3. a^(b/2) % c = d라고 한다면, k = d * d % c와 같음
	*/
}