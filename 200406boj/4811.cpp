/**
*	BOJ
*	No.4811	¾Ë¾à
*	@author	peter9378
*	@date		2020.04.06
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
long long dp[33][33];

long long dfs(int w, int h)
{
	if (dp[w][h])
		return dp[w][h];

	if (w == 0)
		return 1;

	dp[w][h] = dfs(w - 1, h + 1);
	if (h > 0)
		dp[w][h] += dfs(w, h - 1);

	return dp[w][h];
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		cin >> N;

		if (N == 0)
			break;

		cout << dfs(N, 0) << "\n";
	}

	return 0;
}