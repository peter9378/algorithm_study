/**
*	BOJ
*	No.1727	커플 만들기
*	@author	peter9378
*	@date		2021.02.03
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

int N, M;
int m[1001], f[1001];
int dp[1001][1001];

int go()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (i == j)
				dp[i][j] = dp[i - 1][j - 1] + abs(m[i - 1] - f[j - 1]);
			else if (i > j)
				dp[i][j] = min(dp[i - 1][j - 1] + abs(m[i - 1] - f[j - 1]), dp[i - 1][j]);
			else
				dp[i][j] = min(dp[i - 1][j - 1] + abs(m[i - 1] - f[j - 1]), dp[i][j - 1]);
		}
	}
	return dp[N][M];
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> m[i];
	for (int i = 0; i < M; i++)
		cin >> f[i];

	sort(m, m + N);
	sort(f, f + M);
	cout << go();

	return 0;
}
