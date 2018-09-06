/**
*	baekjoon online judge
*	No. 2609	최대공약수와 최소공배수
*	@author	peter9378
*	@date		2018.05.01
*/
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (a%b)
		return gcd(b, a%b);
	else
		return b;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	int a, b;
	cin >> a >> b;

	// 계산 후 출력
	int g = a > b ? gcd(a, b) : gcd(b, a);
	cout << g << "\n" << a*b / g;

	return 0;
}