/**
*	baekjoon online judge
*	No. 2011 암호코드
*	@author	peter9378
*	@date		2018.04.27
*/
#include <iostream>
using namespace std;

#define MOD 1000000

// dp 배열
int dp[5001][2];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 암호 입력
	char code[5001];
	int arr[5001];
	cin >> code;
	
	// 길이 구하기
	int length;
	for (length = 0; code[length] != NULL; length++)
		arr[length + 1] = code[length] - '0';

	// 초기값
	dp[1][0] = arr[1] == 0?0:1;

	// dp 연산
	for (int i = 2; i <= length; i++)
	{
		if (arr[i] == 0)
			dp[i][0] = 0;
		else
			dp[i][0] = dp[i - 1][0] % MOD + dp[i - 1][1] % MOD;

		if ((arr[i - 1] == 1) && (arr[i] >= 0 && arr[i] <= 9) || (arr[i - 1] == 2 && (arr[i] >= 0 && arr[i] <= 6)))
			dp[i][1] = dp[i - 1][0] % MOD;
		else
			dp[i][1] = 0;
	}

	// 출력
	cout << (dp[length][0] % MOD + dp[length][1] % MOD)%MOD;

	return 0;
}