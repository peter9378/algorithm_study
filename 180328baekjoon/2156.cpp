/**
*	baekjoon_stepbystep
*	No. 2156 포도주 시식
*	@author	peter9378
*	@date		2018.04.04
*/
#include <iostream>
using namespace std;

// dp 배열
int dp[10001];
// 와인 배열
int wine[10001];

// max 함수 구현
int max(int a, int b)
{
	return a > b ? a : b;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 와인 개수 입력
	int N;
	cin >> N;

	// 와인 양 입력
	for (int i = 1; i <= N; i++)
		cin >> wine[i];

	// dp 초기값
	dp[1] = wine[1];
	for (int i = 1; i <= N; i++)
			dp[i] = wine[i] + wine[i - 1];

	// dp 연산
	for (int i = 3; i <= N; i++)
		dp[i] = max(max(wine[i] + dp[i - 2], dp[i - 1]), wine[i] + wine[i-1]+dp[i-3]);

	// 출력
	cout << dp[N] << "\n";

	return 0;
}