/**
*	baekjoon online judge
*	No. 2225 합분해
*	@author	peter9378
*	@date		2018.04.27
*/
#include <iostream>
using namespace std;

#define MOD 1000000000

// dp 배열
int dp[201][201];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	int N, K;
	cin >> N >> K;

	// 초기값
	for (int i = 0; i <= N; i++)
		dp[1][i] = 1;

	for (int i = 0; i <= N; i++)
		dp[2][i] = i + 1;

	// dp 연산
	for (int i = 3; i <= K; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			for (int k = 0; k <= j; k++)
				dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
		}
	}

	// 출력
	cout << dp[K][N] % MOD;

	return 0;
}