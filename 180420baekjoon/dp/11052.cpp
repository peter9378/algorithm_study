/**
*	baekjoon online judge
*	No. 11052 붕어빵 판매하기
*	@author	peter9378
*	@date		2018.04.27
*/
#include <iostream>
using namespace std;

int P[1001];
int dp[1001];

int max(int a, int b)
{
	return a > b ? a : b;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> P[i];

	// dp 연산
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
			dp[i] = max(dp[i], dp[i - j] + P[j]);
	}

	// 출력
	cout << dp[N];

	return 0;
}