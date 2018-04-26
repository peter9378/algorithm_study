/**
*	baekjoon online judge
*	No. 10844 쉬운 계단 수
*	@author	peter9378
*	@date		2018.04.26
*/
#include <iostream>
using namespace std;

#define MOD 1000000000

int dp[101][11];

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
			if (!j)
				dp[i][0] = dp[i - 1][1] % MOD;
			else if (j == 9)
				dp[i][9] = dp[i - 1][8] % MOD;
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
		}
	}

	// 결과 연산
	for (int i = 1; i<10; i++)
		result = (result + dp[N][i]) % MOD;

	// 출력
	cout << result << "\n";

	return 0;
}