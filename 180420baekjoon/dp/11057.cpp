/**
*	baekjoon online judge
*	No. 11057 오르막 수
*	@author	peter9378
*	@date		2018.04.27
*/
#include <iostream>
using namespace std;

#define MOD 10007

int dp[1001][11];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	int N, result = 0;
	cin >> N;

	// 초기값
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;

	// dp 연산
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= j; k++)
				dp[i][j] += dp[i - 1][k];
			dp[i][j] %= MOD;
		}
	}

	// 결과 연산
	for (int i = 0; i < 10; i++)
		result += dp[N][i] % MOD;

	// 출력
	cout << result%MOD << "\n";

	return 0;
}