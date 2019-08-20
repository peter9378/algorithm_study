/**
*	BOJ
*	No.1496	기타리스트
*	@author	peter9378
*	@date		2019.08.20
*/
#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][1001];
int V[101];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, S, M;
	cin >> N >> S >> M;

	for (int i = 1; i <= N; i++)
		cin >> V[i];

	dp[0][S] = true;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			if (dp[i-1][j])
			{
				if (j + V[i] <= M)
					dp[i][j + V[i]] = true;
				if (V[i] <= j)
					dp[i][j - V[i]] = true;
			}
		}
	}

	int answer = -1;
	for (int i = 0; i <= M; i++)
	{
		if (dp[N][i])
			answer = max(answer, i);
	}

	cout << answer;

	return 0;
}