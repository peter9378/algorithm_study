/**
*	BOJ
*	No.12766	지사 배정
*	@author	peter9378
*	@date		2021.07.13
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

vector<long long> vv;
vector<vector<pair<int, long long>>> arr(5005), rarr(5005);
long long dp[5005][5005];
long long pre[5005];

void dijk(int target, vector<vector<pair<int, long long>>>& vvp, vector<long long>& dist)
{
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	dist[target] = 0;

	pq.push({ dist[target], target });
	while (!pq.empty())
	{
		int current = pq.top().second;
		long long distance = pq.top().first;
		pq.pop();

		if (distance > dist[current])
			continue;

		for (auto a : vvp[current])
		{
			int v = a.first;
			long long w = a.second;
			if (dist[v] > distance + w)
			{
				dist[v] = distance + w;
				pq.push({ dist[v], v });
			}
		}
	}
}

void go(int lvl, int start, int end, int left, int right)
{
	if (start > end)
		return;
	int mid = (start + end) >> 1;
	long long& result = dp[lvl][mid];
	int temp = left;
	result = dp[lvl - 1][left] + (mid - left - 1) * (pre[mid] - pre[left]);

	for (int i = left; i < min(mid, right); i++)
	{
		long long val = dp[lvl - 1][i] + (mid - i - 1) * (pre[mid] - pre[i]);
		if (result > val)
		{
			result = val;
			temp = i;
		}
	}

	go(lvl, start, mid - 1, left, temp + 1);
	go(lvl, mid + 1, end, temp, right);
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, B, S, M;
	cin >> N >> B >> S >> M;
	for (int i = 0; i < M; ++i) {
		int u, v;
		long long w;
		cin >> u >> v >> w;

		arr[u].push_back({ v,w });
		rarr[v].push_back({ u,w });
	}
	vector<long long> dist(N + 1), rev_dist(N + 1);
	fill(dist.begin(), dist.end(), 1e18);
	fill(rev_dist.begin(), rev_dist.end(), 1e18);

	dijk(B + 1, arr, dist);
	dijk(B + 1, rarr, rev_dist);
	vv.resize(B + 1, 0);
	for (int i = 1; i <= B; ++i)
		vv[i] = dist[i] + rev_dist[i];

	sort(vv.begin(), vv.end());
	for (int i = 1; i <= B; i++)
		pre[i] = pre[i - 1] + vv[i];
	for (int i = 1; i <= B; i++)
		dp[1][i] = (i - 1) * pre[i];
	for (int i = 2; i <= S; i++)
		go(i, i, B, i - 1, B);

	cout << dp[S][B];

	return 0;
}
