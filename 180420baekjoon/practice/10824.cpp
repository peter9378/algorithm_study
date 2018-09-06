/**
*	baekjoon online judge
*	No. 10824	네 수
*	@author	peter9378
*	@date		2018.05.01
*/
#include <iostream>
using namespace std;

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	// 네 수 입력
	long long a, b, c, d;
	cin >> a >> b >> c >> d;

	// 붙이기 위해서 자리수 맞추기
	int temp = b;
	while (temp)
	{
		temp /= 10;
		a*=10;
	}

	temp = d;
	while (temp)
	{
		temp /= 10;
		c *= 10;
	}

	// 숫자 붙이기
	a += b;
	c += d;

	// 출력
	cout << a+c;

	return 0;
}