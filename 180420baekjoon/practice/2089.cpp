/**
*	baekjoon online judge
*	No. 2089	-2진수
*	@author	peter9378
*	@date		2018.05.07
*/
#include <iostream>
#include <string>
using namespace std;

void func(long long a)
{
	if (a == 0)
		return;
	if (a < 0)
	{
		func(-((a - 1) / 2));
		cout << -a % 2;
	}
	else
	{
		func(-(a / 2));
		cout << a % 2;
	}
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long N;
	cin >> N;

	if (N == 0)
		cout << N;
	else
		func(N);

	return 0;
}