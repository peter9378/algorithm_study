/**
*	BOJ
*	No.1958	LCS 3
*	@author	peter9378
*	@date		2021.02.05
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

int dp[101][101][101];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b, c;
	cin >> a >> b >> c;

	int alen, blen, clen;
	alen = a.length();
	blen = b.length();
	clen = c.length();

	for (int i = 1; i <= alen; i++)
	{
		for (int j = 1; j <= blen; j++)
		{
			for (int k = 1; k <= clen; k++)
			{
				if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1])
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				else
					dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
			}
		}
	}

	cout << dp[alen][blen][clen];

	return 0;
}
