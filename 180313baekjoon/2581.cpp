/**
*	baekjoon_stepbystep
*	No. 2581 소수
*	@author	peter9378
*	@date		2018.03.15
*/
#include <iostream>
using namespace std;

// 에라토스테네스의 체
int arr[10001] = { 0, 1 };

// main
int main()
{
	ios::sync_with_stdio(false);
	// 범위 입력
	int m, n;
	cin >> m >> n;

	// 에라토스테네스의 체 적용
	for (int i = 2; i <= 10001; i++)
	{
		for (int j = 2; i*j <= 10001; j++)
			arr[i*j] = 1;
	}

	// 최소값과 소수의 합 계산
	bool flag = true;
	int min = -1, sum = 0;
	for (int i = m; i <= n; i++)
	{
		if (!arr[i])
		{
			if (flag)
			{
				flag = false;
				min = i;
			}
			sum += i;
		}
	}

	// 출력
	if (sum)
		cout << sum << "\n" << min;
	else
		cout << "-1";

	return 0;
}