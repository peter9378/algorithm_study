/**
*	BOJ
*	No.1048	À¯´ÏÄÜ
*	@author	peter9378
*	@date		2020.12.25	Merry Christmas
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
#include <unordered_map>
#include <cstring>
#include <iterator>
#include <numeric>
#include <complex>
using namespace std;

#define MOD 1000000007

int N, M, L;
long long dp[50][301][301];
char str[51];
char board[301][301];

int sum(int index, int a, int b, int c, int d)
{
	if (a < 1)
		a = 1;
	if (b < 1)
		b = 1;
	if (c > N)
		c = N;
	if (d > M)
		d = M;

	long long result = 0;
	result += dp[index][c][d];
	result -= dp[index][a - 1][d];
	result -= dp[index][c][b - 1];
	result += dp[index][a - 1][b - 1];
	result += 2LL * MOD;

	return result % MOD;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> L >> str;
	L = -1;

	while (str[++L]);
	for (int i = 0; i < N; ++i)
		cin >> board[i];

	for (int j = 1; j <= N; ++j)
	{
		for (int k = 1; k <= M; ++k)
		{
			dp[0][j][k] = dp[0][j - 1][k] + dp[0][j][k - 1] - dp[0][j - 1][k - 1];
			if (board[j - 1][k - 1] == str[0])
				dp[0][j][k]++;
		}
	}
	for (int i = 1; i < L; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			for (int k = 1; k <= M; ++k)
			{
				if (board[j - 1][k - 1] == str[i])
				{
					dp[i][j][k] = sum(i - 1, 1, 1, N, M);
					dp[i][j][k] -= sum(i - 1, 1, k - 1, N, k + 1);
					dp[i][j][k] -= sum(i - 1, j - 1, 1, j + 1, M);
					dp[i][j][k] -= sum(i - 1, j - 2, k - 2, j + 2, k + 2);
					dp[i][j][k] += sum(i - 1, j - 2, k - 1, j + 2, k + 1);
					dp[i][j][k] += sum(i - 1, j - 1, k - 2, j + 1, k + 2);
				}
				dp[i][j][k] += dp[i][j - 1][k];
				dp[i][j][k] += dp[i][j][k - 1];
				dp[i][j][k] -= dp[i][j - 1][k - 1];
				(dp[i][j][k] += 2LL * MOD) %= MOD;
			}
		}
	}

	cout << dp[L - 1][N][M];

	return 0;
}
