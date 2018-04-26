/**
*	baekjoon online judge
*	No. 9461 파도반 수열
*	@author	peter9378
*	@date		2018.04.27
*/
#include <iostream>
using namespace std;

// dp 배열
long long dp[101];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 테스트 케이스 개수 입력
	int T;
	cin >> T;

	// 초기값
	dp[0] = dp[1] = dp[2] = dp[3] = 1;
	dp[4] = dp[5] = 2;

	// dp 연산
	for (int i = 6; i <= 100; i++)
		dp[i] = dp[i - 1] + dp[i - 5];

	// 테스트 케이스 루프
	while (T--)
	{
		// 숫자 입력
		int N;
		cin >> N;

		// 출력
		cout << dp[N] << "\n";
	}

	return 0;
}