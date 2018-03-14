/**
*	baekjoon_stepbystep
*	No. 9020 골드바흐의 추측
*	@author	peter9378
*	@date		2018.03.15
*/
#include <iostream>
using namespace std;

// 에라토스테네스의 체
int arr[10001] = { 0, 1 };

void gb(int num)
{
	int mid = num / 2;
	for (int i = mid, j = mid; i <= num; i--, j++)
	{
		if (!arr[i] && !arr[j])
		{
			printf("%d %d\n", i, j);
			return;
		}
	}
	return;
}

// main
int main()
{
	ios::sync_with_stdio(false);

	// 에라토스테네스의 체 적용
	for (int i = 2; i <= 10001; i++)
	{
		for (int j = 2; i*j <= 10001; j++)
			arr[i*j] = 1;
	}

	// 테스트 케이스 개수 입력
	int T;
	scanf("%d", &T);

	int temp;
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &temp);
		gb(temp);
	}

	return 0;
}