/**
*	baekjoon online judge
*	No. 1699 제곱수의 합
*	@author	peter9378
*	@date		2018.04.27
*/
#include <iostream>
using namespace std;

// dp 배열
int dp[100001];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 계단 개수 입력
	int N;
	cin >> N;

	// dp 루프
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j*j <= i; j++)
		{
			if (dp[i] > dp[i - j*j] + 1 || dp[i] == 0)
				dp[i] = dp[i - j*j] + 1;
		}
	}

	// 출력
	cout << dp[N];

	return 0;
}