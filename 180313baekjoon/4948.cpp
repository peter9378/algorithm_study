/**
*	baekjoon_stepbystep
*	No. 4948 베르트랑 공준
*	@author	peter9378
*	@date		2018.03.15
*/
#include <iostream>
using namespace std;

// 에라토스테네스의 체
int arr[246913] = { 0, 1 };

// main
int main()
{
	ios::sync_with_stdio(false);

	// 에라토스테네스의 체 적용
	for (int i = 2; i <= 246913; i++)
	{
		for (int j = 2; i*j <= 246913; j++)
			arr[i*j] = 1;
	}

	// 임의의 자연수 n 입력
	int n, count;
	while (cin >> n)
	{
		if (!n)
			break;
		// n ~ 2n의 소수 카운트
		count = 0;
		for (int i = n+1; i <= 2 * n; i++)
		{
			if (!arr[i])
				count++;
		}
		// 출력
		cout << count << "\n";
	}

	return 0;
}