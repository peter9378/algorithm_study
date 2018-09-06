/**
*	baekjoon online judge
*	No. 1850	최대공약수
*	@author	peter9378
*	@date		2018.05.01
*/
#include <iostream>
using namespace std;

long long gcd(long long a, long long b)
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

	long long A, B, result;
	cin >> A >> B;

	result = gcd(A, B);

	while (result--)
		cout << '1';

	return 0;
}