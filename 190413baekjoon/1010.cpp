/**
*	Baekjoon Online Judge
*	No. 1010	다리 놓기
*	@author	peter9378
*	@date		2019.04.13
*/
#include <iostream>
#include <algorithm>
using namespace std;

int dp[31][31];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int T;
	cin >> T;

	for (int i = 0; i < 31; i++)
	{
		dp[i][0] = dp[i][i] = 1;
		
		for (int j = 1; j < i; j++)
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
	}

	while (T--)
	{
		int N, M;
		cin >> N >> M;

		cout << dp[M][N] << "\n";
	}

	return 0;
}