/**
*	baekjoon_stepbystep
*	No. 1932 숫자삼각형
*	@author	peter9378
*	@date		2018.03.23
*/
#include <iostream>
using namespace std;

// dp 배열
int dp[501][501];

// max함수 구현
int max(int a, int b)
{
	return a > b ? a : b;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 삼각형 크기 입력
	int N;
	cin >> N;

	int answer = 0;
	// 입력과 동시에 바로바로 dp계산
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			// 숫자 입력
			cin >> dp[i][j];
			// 맨 왼쪽이면 그냥 바로 위
			if (j == 1)
				dp[i][j] += dp[i - 1][j];
			// 맨 오른쪽이어도 그냥 바로 위
			else if (j == i)
				dp[i][j] += dp[i - 1][j - 1];
			// 그 이외에는 위에 두 개 중에 큰걸로
			else
				dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
			// 최대값은 매번 check
			if (answer < dp[i][j])
				answer = dp[i][j];
		}
	}

	// 출력
	cout << answer;

	return 0;
}