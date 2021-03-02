/**
*	BOJ
*	No.5542	JOI 국가의 행사
*	@author	peter9378
*	@date		2021.03.02
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

int N, M, K, Q;
int arr[111111];
int dist[111111];
int answer[111111];
vector<vector<pair<int, int>>> v;
set<int> s[111111];
pair<int, pair<int, int>> edge[211111];

int check(int h)
{
	return h == arr[h] ? h : arr[h] = check(arr[h]);
}

void merge(int a, int b)
{
	a = check(a);
	b = check(b);
	arr[a] = b;
	return;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K >> Q;
	v.resize(N + 1);
	for (int i = 1; i <= N; i++)
		arr[i] = i;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
		edge[i].second = { a,b };
	}

	memset(dist, -1, sizeof(dist));

	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < K; i++)
	{
		int temp;
		cin >> temp;
		pq.push({ 0,temp });
	}
	while (pq.size())
	{
		int cost = -pq.top().first;
		int current = pq.top().second;
		pq.pop();

		if (dist[current] != -1)
			continue;

		dist[current] = cost;
		for (auto next : v[current])
		{
			if (dist[next.first] == -1)
				pq.push({ -next.second - cost,next.first });
		}
	}

	for (int i = 1; i <= Q; i++)
	{
		int a, b;
		cin >> a >> b;
		s[a].insert(i);
		s[b].insert(i);
	}

	for (int i = 0; i < M; i++)
		edge[i].first = -min(dist[edge[i].second.first], dist[edge[i].second.second]);

	sort(edge, edge + M);

	for (int i = 0; i < M; i++)
	{
		int left = check(edge[i].second.first);
		int right = check(edge[i].second.second);
		if (left == right)
			continue;

		if (s[left].size() > s[right].size())
			swap(left, right);

		for (auto next : s[left])
		{
			if (s[right].count(next))
			{
				answer[next] = -edge[i].first;
				s[right].erase(next);
			}
			else
				s[right].insert(next);
		}

		merge(left, right);
	}

	for (int i = 1; i <= Q; i++)
		cout << answer[i] << "\n";

	return 0;
}
