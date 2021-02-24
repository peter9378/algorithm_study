/**
*	BOJ
*	No.14869	¿ä¸® °­ÁÂ
*	@author	peter9378
*	@date		2021.02.24
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

long long no[10101];
long long arr[3030][3030];
long long temp[3030][3030];

struct pos {
	long long idx, vl;
};

bool compare(pos a, pos b) {
	return a.vl < b.vl;
}

deque<pair<long long, long long>> dq[3030];
long long dp[3030][3030];
pos p[3030][4];

long long sol(long long l, long long target)
{
	if (no[target] != p[l][0].idx&&target != p[l][0].idx) 
		return p[l][0].vl;
	if (no[target] != p[l][1].idx&&target != p[l][1].idx) 
		return p[l][1].vl;
	if (no[target] != p[l][2].idx&&target != p[l][2].idx) 
		return p[l][2].vl;
}

void add(long long l, long long target, long long v) 
{
	p[l][3].vl = v;
	p[l][3].idx = target;

	sort(p[l], p[l] + 4, compare);
	return;
}

void get(long long l, long long target, long long v) 
{
	while (!dq[target].empty() && dq[target].back().second > v)
		dq[target].pop_back();

	dq[target].push_back({ l,v });
	return;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long M, N, S, E, T;
	cin >> M >> N >> S >> E >> T;

	for (int j = 1; j <= M; j++)
	{
		for (int i = 1; i <= N; i++) 
		{
			cin >> arr[i][j];
			temp[i][j] = temp[i - 1][j] + arr[i][j];
		}
	}

	for (int i = 1; i <= M; i++)
		cin >> no[i];

	for (int i = 1; i <= N; i++) 
	{
		for (int j = 1; j <= M; j++)
			dp[i][j] = 1e18;
		for (int j = 0; j < 4; j++)
			p[i][j].vl = 1e18;
	}

	for (int i = 1; i <= M; i++)
		dq[i].push_back({ 0,-T });

	for (int i = S; i <= N; i++) 
	{
		for (int j = 1; j <= M; j++) 
		{
			if (i == N) 
			{
				for (int k = i - S + 1; k < N; k++)
					get(k, j, sol(k, j) - temp[k][j]);
			}

			while (dq[j].front().first < i - E) 
				dq[j].pop_front();
			dp[i][j] = dq[j].front().second + temp[i][j] + T;
			add(i, j, dp[i][j]);
		}

		for (int j = 1; j <= M; j++) 
		{
			long long tmp = i - S + 1;
			get(tmp, j, sol(tmp, j) - temp[tmp][j]);
		}
	}

	long long answer = 1e18;
	for (int j = 1; j <= M; j++)
		answer = min(answer, dp[N][j]);

	cout << answer;

	return 0;
}
