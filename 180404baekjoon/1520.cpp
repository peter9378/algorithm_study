/**
*	baekjoon_stepbystep
*	No. 1520 내리막 길
*	@author	peter9378
*	@date		2018.04.10
*/
#include <iostream>
#include <string>
using namespace std;

// dp 배열
int dp[501][501];
// 방향 배열
int x[4] = { 0, 1, 0, -1 };
int y[4] = { -1, 0, 1, 0 };
// 지도 배열
int map[501][501];


// dp 재귀 함수
int process(int i, int j)
{
	if (i == 0 && j == 0)
		return dp[i][j] = 1;
	if (dp[i][j] == 0)
	{
		for (int k = 0; k < 4; k++)
		{
			// 4방향 돌면서 재귀
			if (map[i + y[k]][j + x[k]] > map[i][j])
				dp[i][j] += process(i + y[k], j + x[k]);
		}
	}
	return dp[i][j];
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 지도 가로/세로 입력
	int M, N;
	cin >> M >> N;

	// 지도 숫자 입력
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);
	}

	// 출력
	cout << process(M - 1, N - 1);

	return 0;
}