/**
*	BOJ
*	No.1509	팰린드롬 분할
*	@author	peter9378
*	@date		2020.06.15
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

string s;
long long dp[2505][2505];
long long dpp[2505];

int check(int start, int end)
{
	long long &result = dp[start][end];
	if (result != -1)
		return result;

	if (start >= end)
		return 1;

	if (s[start] != s[end])
		return result = 0;

	return result = check(start + 1, end - 1);
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;
	int len = s.length();
	s = '#' + s;
	for (int i = 0; i < 2505; i++)
	{
		for (int j = 0; j < 2505; j++)
			dp[i][j] = -1;
		dpp[i] = 63;
	}
	dpp[0] = 0;

	for (int i = 1; i <= len; i++)
	{
		dpp[i] = dpp[i - 1] + 1;
		for (int j = 1; j < i; j++)
		{
			if (!check(j, i))
				continue;
			dpp[i] = min(dpp[i], dpp[j - 1] + 1);
		}
	}

	cout << dpp[len];

	return 0;
}