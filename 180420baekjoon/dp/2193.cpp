/**
*	baekjoon online judge
*	No. 2193 이친수
*	@author	peter9378
*	@date		2018.04.27
*/
#include <iostream>
using namespace std;

long long dp[91][2];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	int N;
	cin >> N;

	// 초기값
	dp[1][0] = dp[2][1] = 0;
	dp[1][1] = dp[2][0] = 1;

	// dp 연산
	for (int i = 3; i <= N; i++)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	// 출력
	cout << dp[N][0] + dp[N][1] << "\n";

	return 0;
}