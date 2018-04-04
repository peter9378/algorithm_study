/**
*	baekjoon_stepbystep
*	No. 2293 동전1
*	@author	peter9378
*	@date		2018.04.04
*/
#include <iostream>
using namespace std;

// dp 배열
int dp[10001];
// 동전 배열
int coin[101];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 숫자 입력
	int N, K;
	cin >> N >> K;

	// 동전 입력
	for (int i = 0; i < N; i++)
		cin >> coin[i];

	// dp 초기값
	dp[0] = 1;

	// dp 연산
	for (int i = 0; i < N; i++)
	{
		for(int j = 1; j <= K; j++)
		{
			if (j >= coin[i])
				dp[j] += dp[j - coin[i]];
		}
	}
	
	// 출력
	cout << dp[K] << "\n";

	return 0;
}