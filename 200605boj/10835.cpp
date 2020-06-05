/**
*	BOJ
*	No.10835	카드게임
*	@author	peter9378
*	@date		2020.06.05
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

int N;
int leftarr[2002];
int rightarr[2002];
int dp[2002][2002];

int dfs(int a, int b)
{
	if (a == N || b == N)
		return 0;

	if (dp[a][b] != -1)
		return dp[a][b];

	dp[a][b] = max(dfs(a + 1, b), dfs(a + 1, b + 1));

	if (leftarr[a] > rightarr[b])
		dp[a][b] = max(dp[a][b], dfs(a, b + 1) + rightarr[b]);

	return dp[a][b];
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 2002; i++)
	{
		for (int j = 0; j < 2002; j++)
			dp[i][j] = -1;
	}

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> leftarr[i];

	for (int i = 0; i < N; i++)
		cin >> rightarr[i];

	cout << dfs(0, 0);

	return 0;
}