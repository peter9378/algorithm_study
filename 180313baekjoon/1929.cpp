/**
*	baekjoon_stepbystep
*	No. 1929 소수 구하기
*	@author	peter9378
*	@date		2018.03.15
*/
#include <iostream>
using namespace std;

// 에라토스테네스의 체
int arr[1000001] = { 0, 1 };

// main
int main()
{
	ios::sync_with_stdio(false);
	// 범위 입력
	int m, n;
	cin >> m >> n;

	// 에라토스테네스의 체 적용
	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; i*j <= n; j++)
			arr[i*j] = 1;
	}

	// 출력
	for (int i = m; i <= n; i++)
	{
		if (!arr[i])
			cout << i << "\n";
	}

	return 0;
}