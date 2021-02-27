/**
*	BOJ
*	No.16404	주식회사 승범이네
*	@author	peter9378
*	@date		2021.02.27
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

int N, M;
vector<int> v[500005];
long long seg[2000002], lazy[2000002];
int start[500001], ed[500001], cnt = 0;

void ppg(int node, int s, int e)
{
	if (lazy[node] == 0)
		return;

	seg[node] += (e - s + 1) * lazy[node];

	if (s != e)
	{
		for (int i = node * 2; i <= node * 2 + 1; i++)
			lazy[i] += lazy[node];
	}

	lazy[node] = 0;
	return;
}

void update(int target, int start, int end, int left, int right, long long l)
{
	ppg(target, start, end);
	if (end < left || right < start)
		return;

	if (left <= start && end <= right)
	{
		lazy[target] = l;
		ppg(target, start, end);
		return;
	}

	int mid = start + end >> 1;
	update(target * 2, start, mid, left, right, l);
	update(target * 2 + 1, mid + 1, end, left, right, l);

	seg[target] = seg[target * 2] + seg[target * 2 + 1];
}

long long sum(int node, int start, int end, int left, int right)
{
	ppg(node, start, end);
	if (end < left || right < start)
		return 0;

	if (left <= start && end <= right)
		return seg[node];

	int mid = start + end >> 1;

	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}


void dfs(int x, int par)
{
	start[x] = ++cnt;
	for (int nxt : v[x])
	{
		if (nxt == par)
			continue;
		dfs(nxt, x);
	}

	ed[x] = cnt;
	return;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		int temp;
		cin >> temp;

		if (temp == -1)
			continue;

		v[temp].push_back(i);
	}

	dfs(1, -1);
	int maxi = 0;
	for (int i = 1; i <= N; i++)
		maxi = max(maxi, ed[i]);

	while (M--)
	{
		int oper;
		cin >> oper;
		if (oper == 1)
		{
			int temp;
			long long x;
			cin >> temp >> x;
			update(1, 1, maxi, start[temp], ed[temp], x);
		}
		else {
			int temp;
			cin >> temp;
			cout << sum(1, 1, maxi, start[temp], start[temp]) << "\n";
		}
	}

	return 0;
}
