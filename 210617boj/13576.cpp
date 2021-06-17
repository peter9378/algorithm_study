/**
*	BOJ
*	No.13576	Prefix¿Í Suffix
*	@author	peter9378
*	@date		2021.06.17
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

string a;
int t, g[100001], tg[100001], arr[100001], r[100001], lcp[100001];
int dp[100005];
vector<int> v;
vector<pair<int, int>> answer;

bool compare(int x, int y)
{
	if (g[x] == g[y])
		return g[x + t] < g[y + t];
	return g[x] < g[y];
}

void get()
{
	v.resize(a.length());
	int j = 0;

	for (int i = 1; i < a.length(); i++)
	{
		while (j&&a[i] != a[j])
			j = v[j - 1];
		if (a[i] == a[j])
			v[i] = ++j;
	}
}

int go(int target)
{
	int &result = dp[target];
	if (result != -1)
		return result;

	result = 1;
	for (int i = target + 1; i < a.length(); i++)
	{
		if (lcp[i] >= a.length() - arr[target])
		{
			result += go(i);
			i += go(i) - 1;
		}
		else
			break;
	}

	return result;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp, -1, sizeof(dp));
	cin >> a;
	get();
	t = 1;

	for (int i = 0; i < a.length(); i++)
	{
		arr[i] = i;
		g[i] = a[i] - 'A';
	}

	while (t <= a.length())
	{
		g[a.length()] = -1;
		sort(arr, arr + a.length(), compare);
		tg[arr[0]] = 0;
		for (int i = 1; i < a.length(); i++)
		{
			if (compare(arr[i - 1], arr[i]))
				tg[arr[i]] = tg[arr[i - 1]] + 1;
			else
				tg[arr[i]] = tg[arr[i - 1]];
		}

		for (int i = 0; i < a.length(); i++)
			g[i] = tg[i];
		t <<= 1;
	}

	for (int i = 0; i < a.length(); i++)
		r[arr[i]] = i;

	int len = 0;
	for (int i = 0; i < a.length(); i++)
	{
		int k = r[i];
		if (k)
		{
			int j = arr[k - 1];
			while (a[j + len] == a[i + len])
				len++;

			lcp[k] = len;
			if (len)
				len--;
		}
	}

	for (int i = 0; i < a.length(); i++)
		go(i);

	answer.push_back({ a.length(),1 });
	int x = v[a.length() - 1];
	while (x)
	{
		int idx = r[a.length() - x];
		answer.push_back({ x,dp[idx] });
		x = v[x - 1];
	}

	cout << answer.size() << "\n";
	for (int i = answer.size() - 1; i >= 0; i--)
		cout << answer[i].first << " " << answer[i].second << "\n";

	return 0;
}
