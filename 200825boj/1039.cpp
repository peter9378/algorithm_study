/**
*	BOJ
*	No.1039	±³È¯
*	@author	peter9378
*	@date		2020.08.25
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
using namespace std;

string N;
int M, K;
int dp[1000001][11];

int dfs(string s, int index)
{
	if (index == K)
		return stoi(s);

	int &result = dp[stoi(s)][index];
	if (result != -1)
		return result;

	for (int i = 0; i < s.length() - 1; i++)
	{
		for (int j = i + 1; j < s.length(); j++)
		{
			swap(s[i], s[j]);

			if (s[0] == '0')
			{
				swap(s[i], s[j]);
				continue;
			}

			result = max(result, dfs(s, index + 1));
			swap(s[i], s[j]);
		}
	}

	return result;
}

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	memset(dp, -1, sizeof(dp));

	cout << dfs(N, 0);

	return 0;
}