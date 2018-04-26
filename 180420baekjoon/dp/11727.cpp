/**
*	baekjoon_stepbystep
*	No. 11727 2xn 타일링 2
*	@author	peter9378
*	@date		2018.04.26
*/
#include <iostream>
using namespace std;

#define MOD 10007

// dp 배열
int dp[1001];


// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	int N;
	cin >> N;

	// 초기값 설정
	dp[0] = dp[1] = 1;

	// dp 연산
	for (int i = 2; i <= N; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]*2)%MOD;

	// 출력
	cout << dp[N];

	return 0;
}