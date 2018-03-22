/**
*	baekjoon_stepbystep
*	No. 2579 계단 오르기
*	@author	peter9378
*	@date		2018.03.23
*/
#include <iostream>
using namespace std;

// dp 배열
int dp[301];
// 계단 배열
int stair[301];

// max함수 구현
int max(int a, int b)
{
	return a > b ? a : b;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 계단 개수 입력
	int N;
	cin >> N;

	// 점수 입력
	for (int i = 0; i < N; i++)
		cin >> stair[i];

	// dp 초기값 초기화
	dp[0] = stair[0];
	dp[1] = stair[0] + stair[1];
	dp[2] = max(stair[0], stair[1]) + stair[2];

	// dp 루프
	for (int i = 3; i < N; i++)
		dp[i] = max(dp[i - 2] + stair[i], stair[i - 1] + stair[i] + dp[i - 3]);

	cout << dp[N - 1];

	return 0;
}