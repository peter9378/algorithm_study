/**
*	baekjoon_stepbystep
*	No. 9095 1, 2, 3 더하기
*	@author	peter9378
*	@date		2018.04.26
*/
#include <iostream>
using namespace std;

// dp 배열
int dp[11];


// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	int T;
	cin >> T;

	// 초기값
	dp[0] = dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	// dp 연산
	for (int i = 4; i < 11; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

	// 입력/출력
	for (int test_case = 0; test_case < T; test_case++)
	{
		int N;
		cin >> N;

		cout << dp[N] << "\n";
	}
	return 0;
}