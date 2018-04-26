/**
*	baekjoon online judge
*	No. 11055 가장 큰 증가 부분 수열
*	@author	peter9378
*	@date		2018.04.27
*/
#include <iostream>
using namespace std;

// dp 배열
int dp[1001];
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
				if (temp < dp[j])
					temp = dp[j];
			}
		}
		dp[i] = temp + A[i];
		if (max < dp[i])
			max = dp[i];
	}
	// 출력
	cout << max;

	return 0;
}