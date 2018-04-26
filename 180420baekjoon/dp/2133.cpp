/**
*	baekjoon online judge
*	No. 2133 타일 채우기
*	@author	peter9378
*	@date		2018.04.27
*/
#include <iostream>
using namespace std;

// dp 배열
int dp[31];
int arr[31];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 계단 개수 입력
	int N;
	cin >> N;

	// 초기값
	dp[0] = arr[0] = 1;
	dp[2] = 3;
	for (int i = 4; i <= 30; i += 2)
		dp[i] = 2;

	// dp 루프
	for (int i = 2; i <= N; i+=2)
	{
		for (int j = 2; j <= i; j += 2)
			arr[i] += dp[j] * arr[i - j];
	}

	// 출력
	cout << arr[N];

	return 0;
}