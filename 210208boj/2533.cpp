/**
*	BOJ
*	No.2533	사회망 서비스(SNS)
*	@author	peter9378
*	@date		2021.02.10
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

int N;
int dp[1010101][2];
vector<int> arr[1010101];
vector<int> v[1010101];

void dfs(int current, int previous)
{
	for (auto next : arr[current])
	{
		if (next ^ previous)
		{
			v[current].push_back(next);
			dfs(next, current);
		}
	}
}

int go(int current, int flag)
{
	int &result = dp[current][flag];
	if (result != -1)
		return result;

	result = 0;

	if (!flag)
	{
		for (auto next : v[current])
			result += go(next, 1);
	}
	else
	{
		for (auto next : v[current])
		{
			int a = go(next, 0);
			int b = go(next, 1);
			result += min(a, b);
		}
		result++;
	}

	return result;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	dfs(1, 0);

	memset(dp, -1, sizeof dp);
	cout << min(go(1, 0), go(1, 1));

	return 0;
}
