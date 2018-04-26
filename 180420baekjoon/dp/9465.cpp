/**
*	baekjoon online judge
*	No. 2193 이친수
*	@author	peter9378
*	@date		2018.04.27
*/
#include <iostream>
using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

// dp 배열
int dp[100001][3];
int arr[100001][2];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 테스트 케이스 개수 입력
	int test_case;
	cin >> test_case;

	// 테스트 케이스 루프
	while (test_case--)
	{
		// 입력
		int num;
		cin >> num;

		// 점수 입력
		for (int i = 1; i <= num; i++)
			cin >> arr[i][0];
		for (int i = 1; i <= num; i++)
			cin >> arr[i][1];

		// dp 연산
		for (int i = 1; i <= num; i++)
		{
			dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + arr[i][0];
			dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + arr[i][1];
		}
		
		// 출력
		cout << max(max(dp[num][0], dp[num][1]), dp[num][2]) << "\n";
	}

	return 0;
}