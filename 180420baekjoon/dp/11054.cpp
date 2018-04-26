/**
*	baekjoon online judge
*	No. 11054 가장 긴 바이토닉 부분 수열
*	@author	peter9378
*	@date		2018.04.27
*/
#include <iostream>
using namespace std;

// dp 배열
int dp[2][1001];
int A[1001];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 숫자 입력
	int N;
	cin >> N;

	// 와인 입력
	for (int i = 1; i <= N; i++)
		cin >> A[i];

	int max = 0;

	// dp 연산
	for (int i = 1; i <= N; i++)
	{
		int temp = 0;
		for (int j = 0; j < i; j++)
		{
			if (A[i] > A[j])
			{
				if (temp < dp[0][j])
					temp = dp[0][j];
			}
		}
		dp[0][i] = temp + 1;
	}

	for (int i = N; i >= 1; i--)
	{
		int temp = 0;
		for (int j = N; j > i; j--)
		{
			if (A[i] > A[j])
			{
				if (temp < dp[1][j])
					temp = dp[1][j];
			}
		}
		if (dp[1][i] < temp + 1)
			dp[1][i] = temp + 1;
	}

	for (int i = 1; i <= N; i++)
	{
		if (max < dp[0][i] + dp[1][i])
			max = dp[0][i] + dp[1][i];
	}

	// 출력
	cout << max - 1;

	return 0;
}