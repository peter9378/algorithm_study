/**
*	baekjoon online judge
*	No. 1912 연속합
*	@author	peter9378
*	@date		2018.04.27
*/
#include <iostream>
using namespace std;

// dp 배열
int dp[100001];
int arr[100001];

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
		cin >> arr[i];

	int max = 0;

	// dp 연산
	for (int i = 1; i <= N; i++)
	{
		if (dp[i - 1] + arr[i] > arr[i])
			dp[i] = dp[i - 1] + arr[i];
		else
			dp[i] = arr[i];
	}
	max = dp[1];
	for (int i = 2; i <= N; i++)
	{
		if (max < dp[i])
			max = dp[i];
	}

	// 출력
	cout << max ;

	return 0;
}