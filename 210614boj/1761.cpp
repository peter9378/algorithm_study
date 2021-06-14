/**
*	BOJ
*	No.1761	정점들의 거리
*	@author	peter9378
*	@date		2021.06.14
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

int depth[40404];
int check[40404];
int dist[40404];
int dp[40404][20];
vector<pair<int, int>> v[40404];

void dfs(int target, int d, int chk)
{
	check[target] = 1;
	depth[target] = d;
	dist[target] = chk;

	for (auto i : v[target])
	{
		int nxt = i.first;
		int cst = i.second;
		if (check[nxt])
			continue;
		dp[nxt][0] = target;
		dfs(nxt, d + 1, chk + cst);
	}
}

int lca(int u, int v)
{
	if (depth[u] > depth[v])
		swap(u, v);

	int diff = depth[v] - depth[u];
	for (int i = 0; diff; i++)
	{
		if (diff & 1)
			v = dp[v][i];
		diff >>= 1;
	}

	if (u == v)
		return u;

	for (int i = 19; i >= 0; i--)
	{
		if (dp[u][i] != dp[v][i])
		{
			u = dp[u][i];
			v = dp[v][i];
		}
	}

	return dp[u][0];
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	depth[1] = check[1] = 1;
	dp[1][0] = dist[1] = 0;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}

	dfs(1, 0, 0);
	for (int j = 1; j < 20; j++)
	{
		for (int i = 1; i <= N; i++)
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
	}

	int M;
	cin >> M;

	while (M--)
	{
		int a, b;
		cin >> a >> b;

		int distance_a = dist[a], distance_b = dist[b];
		int target = dist[lca(a, b)];
		int answer = distance_a + distance_b - 2 * target;
		cout << answer << "\n";
	}

	return 0;
}
