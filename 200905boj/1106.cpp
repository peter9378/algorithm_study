/**
*	BOJ
*	No.1106	хёез
*	@author	peter9378
*	@date		2020.09.05
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

int cost[22], customer[22];
int dp[100001];

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int C, N;
	cin >> C >> N;

	for (int i = 1; i <= N; i++)
		cin >> cost[i] >> customer[i];

	for (int i = 1; i <= N; i++)
	{
		for (int j = cost[i]; j <= 100000; j++)
			dp[j] = max(dp[j], dp[j - cost[i]] + customer[i]);
	}

	for (int i = 1; i <= 100000; i++)
	{
		if (dp[i] >= C)
		{
			cout << i;
			break;
		}
	}

	return 0;
}