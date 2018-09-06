/**
*	baekjoon_stepbystep
*	No. 2004	조합 0의 개수
*	@author	peter9378
*	@date		2018.05.11
*/
#include <iostream>
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int com(int a)
{
	int num = 0;
	while (a)
	{
		num += a / 5;
		a /= 5;
	}
	return num;
}

int bi(int a)
{
	int num = 0;
	while (a)
	{
		num += a / 2;
		a /= 2;
	}
	return num;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M;
	cin >> N >> M;

	cout << min(com(N) - com(N - M) - com(M), bi(N) - bi(N - M) - bi(M));

	return 0;
}