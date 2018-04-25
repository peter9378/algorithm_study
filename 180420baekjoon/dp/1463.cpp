/**
*	baekjoon online judge
*	No. 1463	1로 만들기
*	@author	peter9378
*	@date		2018.04.25
*/
#include <iostream>
using namespace std;

// dp 배열
int dp[1000001];

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

	// 숫자 입력
	int N;
	cin >> N;

	// dp 초기값 초기화(1보다 크거나 같음)
	dp[1] = 0;

	// dp 루프
	for (int i = 2; i <= N; i++)
	{
		// 무조건 1 증가 시도
		dp[i] = dp[i - 1] + 1;
		// 2배가 가능한 경우
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
		// 3배가 가능한 경우
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}

	// 출력
	cout << dp[N];

	return 0;
}