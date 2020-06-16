/**
*	BOJ
*	No.1565	°è´Ü ¼ö
*	@author	peter9378
*	@date		2020.06.16
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>
#include <cstring>
#include <iterator>
#include <numeric>
using namespace std;

#define MOD 1000000000

long long dp[101][11][1024];

bool check(int state, int digit)
{
	return state & (1 << (9 - digit));
}

int digit(int digit)
{
	return 1 << (9 - digit);
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i < 10; i++)
		dp[1][i][1 << (9 - i)] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 1; k < 1024; k++)
			{
				if (!check(k, j))
					continue;

				if (j != 0)
				{
					dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 1][k]) % MOD;
					dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 1][k^digit(j)]) % MOD;
				}

				if (j != 9)
				{
					dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j + 1][k]) % MOD;
					dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j + 1][k^digit(j)]) % MOD;
				}
			}
		}
	}

	long long answer = 0;
	for (int i = 0; i < 10; i++)
		answer = (answer + dp[N][i][1023]) % MOD;
	cout << answer;

	return 0;
}
