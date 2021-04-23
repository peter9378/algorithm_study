/**
*	BOJ
*	No.11280	2-SAT - 3
*	@author	peter9378
*	@date		2021.04.23
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

vector<int> arr[20202], rev_arr[20202];

int scc[20202];
bool visit[20202];
vector<int> v;

void dfs(int target)
{
	visit[target] = 1;
	for (auto u : arr[target])
	{
		if (!visit[u])
			dfs(u);
	}
	v.push_back(target);
}

void sfd(int target, int color)
{
	visit[target] = true;
	scc[target] = color;
	for (auto u : rev_arr[target])
	{
		if (!visit[u])
			sfd(u, color);
	}
}

void go(int n)
{
	memset(visit, 0, sizeof visit);
	for (int i = 1 * 2; i <= n * 2 + 1; i++)
	{
		if (!visit[i])
			dfs(i);
	}

	memset(visit, 0, sizeof visit);
	reverse(v.begin(), v.end());

	int cnt = 1;
	for (auto i : v)
	{
		if (!visit[i])
		{
			sfd(i, cnt);
			cnt++;
		}
	}
}
// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		if (a > 0)
			a = a << 1;
		else
			a = (-a << 1 | 1);

		if (b > 0)
			b = b << 1;
		else
			b = (b << 1 | 1);

		arr[a ^ 1].push_back(b);
		arr[b ^ 1].push_back(a);
		rev_arr[b].push_back(a ^ 1);
		rev_arr[a].push_back(b ^ 1);
	}

	go(N);

	for (int i = 1; i <= N; i++)
	{
		if (scc[i << 1] == scc[i << 1 | 1])
		{
			cout << 0;
			return 0;
		}
	}

	cout << 1;
	return 0;
}
