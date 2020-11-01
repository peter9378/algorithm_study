/**
*	BOJ
*	No.18227	성대나라의 물탱크
*	@author	peter9378
*	@date		2020.11.01
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

#define MAX 200002

int N, C, Q;
vector<int>v[MAX];
int dist[MAX], euler[MAX][2], weight[MAX];
long long seg[MAX * 4];
void init(int p)
{
	weight[p] = euler[p][0] = ++Q;
	for (int a : v[p])
	{
		if (!dist[a])
			dist[a] = dist[p] + 1, init(a);
	}

	euler[p][1] = Q;
	return;
}

long long update(int p, int l, int r, int x)
{
	if (x < l || r < x)
		return seg[p];
	if (l == r)
		return ++seg[p];
	return seg[p] = update(p * 2, l, (l + r) / 2, x) + update(p * 2 + 1, (l + r) / 2 + 1, r, x);
}

long long query(int p, int l, int r, int x, int y)
{
	if (y < l || r < x)
		return 0;
	if (x <= l && r <= y)
		return seg[p];
	return query(p * 2, l, (l + r) / 2, x, y) + query(p * 2 + 1, (l + r) / 2 + 1, r, x, y);
}

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> C;
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dist[C] = 1;
	init(C);

	cin >> Q;
	while (Q--)
	{
		int a, b;
		cin >> a >> b;
		if (a & 1)
			update(1, 1, N, weight[b]);
		else cout << query(1, 1, N, euler[b][0], euler[b][1])*dist[b] << "\n";
	}
	return 0;
}