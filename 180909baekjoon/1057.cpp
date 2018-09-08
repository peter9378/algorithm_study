/**
*	baekjoon online judge
*	No. 1057	토너먼트
*	@author	peter9378
*	@date		2018.09.09
*/
#include <iostream>
using namespace std;

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int round, a, b;
	cin >> round >> a >> b;

	int count = 0;
	while (a!=b)
	{
		a = a / 2 + a % 2;
		b = b / 2 + b % 2;
		count++;
	}
	cout << count;
	return 0;
}