/**
*	baekjoon_stepbystep
*	No. 1003 피보나치 함수
*	@author	peter9378
*	@date		2018.03.23
*/
#include <iostream>
using namespace std;

// dp배열
int dp[2][41];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 테스트케이스 개수 입력
	int T;
	cin >> T;

	// 초기값 설정
	dp[0][0] = 1;
	dp[1][1] = 1;

	// dp미리 계산
	for (int i = 2; i <= 41; i++)
	{
		dp[0][i] = dp[0][i - 1] + dp[0][i - 2];
		dp[1][i] = dp[1][i - 1] + dp[1][i - 2];
	}

	// 추가연산으로 인한 값 재초기화
	dp[1][0] = 0;

	// 테스트케이스에 따른 dp값 출력
	for (int test_case = 0; test_case < T; test_case++)
	{
		int N;
		cin >> N;

		cout << dp[0][N] << " " << dp[1][N] << "\n";
	}

	return 0;
}