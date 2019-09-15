/**
*	BOJ
*	No.2688	줄어들지 않아
*	@author	peter9378
*	@date		2019.09.16
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

long long dp[10][64];

void init()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 64; j++)
			dp[i][j] = 0;
	}
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		init();
		for (int i = 0; i < 10; i++)
			dp[i][0] = i + 1;
		for (int i = 1; i < n; i++)
		{
			dp[0][i] = 1;
			for (int j = 1; j < 10; j++)
				dp[j][i] = dp[j][i - 1] + dp[j - 1][i];
		}

		cout << dp[9][n - 1] << "\n";
	}

	return 0;
}