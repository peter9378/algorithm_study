/**
*	BOJ
*	No.1660	ĸƾ �̴ټ�
*	@author	peter9378
*	@date		2020.11.28
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

int n;
int arr[300005];
int temp[800];
int ttemp[125];
int dp[3][300005];

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	temp[1] = 1;
	for (int i = 2; i < 800; i++)
		temp[i] = temp[i - 1] + i;

	ttemp[1] = 1;

	for (int i = 2; i < 125; i++)
		ttemp[i] = ttemp[i - 1] + temp[i];

	cin >> n;

	for (int i = 1; i <= n; i++)
		dp[0][i] = 987654321;

	for (int i = 1; i < 800; i++)
	{
		if (ttemp[i] <= n)
		{
			for (int j = 0; j <= n; j++)
			{
				if (j < ttemp[i])
					dp[1][j] = dp[0][j];
				else
					dp[1][j] = min(dp[1][j - ttemp[i]] + 1, dp[0][j]);
			}
		}
		else
			break;

		for (int a = 0; a <= n; a++)
		{
			dp[0][a] = dp[1][a];
			dp[1][a] = 0;
		}
	}

	cout << dp[0][n];

	return 0;
}