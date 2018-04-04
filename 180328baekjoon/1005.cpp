/**
*	baekjoon_stepbystep
*	No. 1005 ACM Craft
*	@author	peter9378
*	@date		2018.04.04
*/
#include <iostream>
using namespace std;

int N, K, final_building;
int time[1001];
int build[1001][1001];
int dp[1001];

// max 함수 구현
int max(int a, int b)
{
	return a > b ? a : b;
}

// dp함수 구현
int func(int target)
{
	if (dp[target])
		return dp[target];

	int result = 0;
	for (int i = 1; i <= N; i++)
	{
		if (build[target][i])
			result = max(result, func(i));
	}
	return dp[target] = result + time[target];
}

// 배열 초기화 함수
void initialize()
{
	for (int i = 0; i <= N; i++)
	{
		time[i] = 0;
		dp[i] = 0;
		for (int j = 0; j < K; j++)
			build[i][j] = 0;
	}
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 테스트 케이스 개수 입력
	int T;
	cin >> T;

	// 테스트 케이스 루프
	for (int test_case = 0; test_case < T; test_case++)
	{
		// 입력
		scanf("%d %d", &N, &K);

		// 초기화
		initialize();

		// 건물 짓는데 걸리는 시간 입력
		for (int i = 1; i <= N; i++)
			scanf("%d", &time[i]);

		// 빌드(건설 순서) 입력
		for (int i = 0; i < K; i++)
		{
			int tempA, tempB;
			scanf("%d %d", &tempA, &tempB);
			build[tempB][tempA] = 1;
		}

		// 짓고싶은 건물 입력
		cin >> final_building;

		// 출력
		cout << func(final_building) << "\n";
	}


	return 0;
}