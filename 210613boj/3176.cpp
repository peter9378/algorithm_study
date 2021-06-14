/**
*	BOJ
*	No.3176	도로 네트워크
*	@author	peter9378
*	@date		2021.06.13
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

int check[101010];
int dep[101010];
int dist[101010];
int dp[101010][22];
int minarr[101010][22];
int maxarr[101010][22];
vector<pair<int, int>> v[101010];

void dfs(int target, int a, int b)
{
	check[target] = 1;
	dep[target] = a;
	dist[target] = b;

	for (auto i : v[target])
	{
		int nxt = i.first;
		int cst = i.second;
		if (check[nxt])
			continue;

		dp[nxt][0] = target;
		minarr[nxt][0] = maxarr[nxt][0] = cst;
		dfs(nxt, a + 1, b + cst);
	}
}

pair<int, int> lca(int u, int v)
{
	int left = 987654321;
	int right = -left;
	if (dep[u] > dep[v])
		swap(u, v);

	int diff = dep[v] - dep[u];
	for (int i = 0; diff; i++)
	{
		if (diff & 1)
		{
			left = min(left, minarr[v][i]);
			right = max(right, maxarr[v][i]);
			v = dp[v][i];
		}
		diff >>= 1;
	}

	if (u == v)
		return { left, right };

	for (int i = 21; i >= 0; i--)
	{
		if (dp[u][i] != dp[v][i])
		{
			left = min({ left, minarr[u][i], minarr[v][i] });
			right = max({ right, maxarr[u][i], maxarr[v][i] });
			u = dp[u][i], v = dp[v][i];
		}
	}

	left = min({ left, minarr[u][0], minarr[v][0] });
	right = max({ right, maxarr[u][0], maxarr[v][0] });
	return { left, right };
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}

	dfs(1, 0, 0);

	for (int j = 1; j < 22; j++)
	{
		for (int i = 1; i <= N; i++)
		{
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
			minarr[i][j] = min(minarr[i][j - 1], minarr[dp[i][j - 1]][j - 1]);
			maxarr[i][j] = max(maxarr[i][j - 1], maxarr[dp[i][j - 1]][j - 1]);
		}
	}

	int M;
	cin >> M;
	while (M--)
	{
		int a, b;
		cin >> a >> b;
		auto t = lca(a, b);
		cout << t.first << " " << t.second << "\n";
	}

	return 0;
}
