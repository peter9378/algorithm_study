/**
*	BOJ
*	No.2419	»ç¼ö¾ÆÅÁ
*	@author	peter9378
*	@date		2021.03.18
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
int dp[333][333][2];
vector<int> v;

int func(int left, int right, int current, int prev)
{
	if (!prev)
		return 0;

	if (left > right)
		return 1e9;

	int &result = dp[left][right][current];
	if (result != -1)
		return result;

	result = 1e9;
	if (current)
	{
		if (right != n)
			result = min(result, func(left, right + 1, 0, prev - 1) + prev * (v[right + 1] - v[left]));
		if (left)
			result = min(result, func(left - 1, right, 1, prev - 1) + prev * (v[left] - v[left - 1]));
	}
	else
	{
		if (right != n)
			result = min(result, func(left, right + 1, 0, prev - 1) + prev * (v[right + 1] - v[right]));
		if (left)
			result = min(result, func(left - 1, right, 1, prev - 1) + prev * (v[right] - v[left - 1]));
	}

	return result;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	v.push_back(0);
	sort(v.begin(), v.end());
	memset(dp, -1, sizeof(dp));

	int answer = 0;
	int idx = lower_bound(v.begin(), v.end(), 0) - v.begin();
	for (int i = 0; i <= n; i++)
	{
		memset(dp, -1, sizeof(dp));
		answer = max(answer, i*m - func(idx, idx, 0, i));
	}
	cout << answer;

	return 0;
}
