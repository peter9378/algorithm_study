/**
*	BOJ
*	No.2585	경비행기
*	@author	peter9378
*	@date		2020.03.23
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
#include <cstring>
#include <iterator>
#include <numeric>
using namespace std;

vector<pair<int, int>> v;
bool visit[(int)1e3 + 2];

int dfs(pair<int, int> a, pair<int, int> b)
{
	return (int)ceil(sqrt((b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second)) / 10);
}

bool bfs(int maxi, int n, int k)
{
	memset(visit, 0, sizeof(visit));

	queue<pair<int, int>> q;
	q.push({ 0, 0 });

	while (!q.empty()) {
		int from = q.front().first;
		int to = q.front().second;
		q.pop();

		if (from == v.size() - 1)
		{
			if (to <= k + 1)
				return 1;
			return 0;
		}

		for (int i = 1; i < v.size(); i++)
		{
			if (visit[i])
				continue;

			if (dfs(v[i], v[from]) <= maxi)
			{
				visit[i] = 1;
				q.push({ i, to + 1 });
			}
		}
	}

	return 0;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	v.push_back({ 0, 0 });

	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;

		v.push_back({ a, b });
	}

	v.push_back({ 1e4, 1e4 });

	int left = 1, right = dfs({ 0, 0 }, { 1e4, 1e4 });

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (bfs(mid, n, k))
			right = mid - 1;
		else
			left = mid + 1;
	}

	cout << left;

	return 0;
}