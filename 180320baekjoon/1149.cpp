/**
*	baekjoon_stepbystep
*	No. 1149 RGB거리
*	@author	peter9378
*	@date		2018.03.23
*/
#include <iostream>
using namespace std;

// dp 배열
int dp[4][1001];
// 비용 배열
int cost[4][1001];

// min함수 구현
int min(int a, int b)
{
	return a < b ? a : b;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 집 개수 입력
	int N;
	cin >> N;

	// 비용 입력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> cost[j][i];
		}
	}

	// dp 초기값 초기화
	dp[0][0] = cost[0][0];
	dp[1][0] = cost[1][0];
	dp[2][0] = cost[2][0];

	// dp 루프
	for (int i = 1; i < N; i++)
	{
		dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + cost[0][i];
		dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + cost[1][i];
		dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + cost[2][i];
	}

	// 셋 중에 가장 작은 값 출력
	cout << min(min(dp[0][N - 1], dp[1][N - 1]), dp[2][N - 1]);

	return 0;
}