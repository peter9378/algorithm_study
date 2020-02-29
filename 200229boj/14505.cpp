/**
*	BOJ
*	No.14505	팰린드롬 개수 구하기 (Small)
*	@author	peter9378
*	@date		2020.02.29
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
using namespace std;

long long dp[1111][1111];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		dp[i][i] = 1;

		if (s[i] == s[i + 1])
			dp[i][i + 1] = 3;
		else
			dp[i][i + 1] = 2;
	}

	for (int i = 2; i < s.length(); i++)
	{
		for (int index = 0; index < s.length(); index++)
		{
			int target = i + index;
			if (target > s.length())
				break;

			dp[index][target] = dp[index + 1][target] + dp[index][target - 1] - dp[index + 1][target - 1];
			if (s[index] == s[target])
				dp[index][target] += dp[index + 1][target - 1] + 1;
		}
	}

	cout << dp[0][s.length() - 1];

	return 0;
}