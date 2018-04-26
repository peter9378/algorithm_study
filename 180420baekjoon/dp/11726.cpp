/**
*	baekjoon_stepbystep
*	No. 11726 2xn 타일링
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

	int N;
	cin >> N;

	dp[0] = dp[1] = 1;

	for (int i = 2; i <= N; i++)
		dp[i] = (dp[i - 1] + dp[i - 2])%MOD;

	cout << dp[N];

	return 0;
}