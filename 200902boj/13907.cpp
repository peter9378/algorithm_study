/**
*	BOJ
*	No.13907	¼¼±Ý
*	@author	peter9378
*	@date		2020.09.02
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
using namespace std;

int N, M, K, S, E;
vector<pair<int, int>> arr[1001];
long long dist[1001][1001];

void dijk(long long &start)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 1001; j++)
			dist[i][j] = 987654321;
	}

	priority_queue<pair<pair<long long, int>, int>, vector<pair<pair<long long, int>, int>>, greater<pair<pair<long long, int>, int>>> pq;
	dist[S][0] = 0;
	pq.push({ {0, 0}, S });

	while (!pq.empty())
	{
		int current = pq.top().second;
		int cnt = pq.top().first.second;
		long long cost = pq.top().first.first;
		pq.pop();

		bool find = false;
		for (int i = 0; i < cnt; i++)
		{
			if (dist[current][i] < cost)
			{
				find = true;
				break;
			}
		}

		if (find || dist[current][cnt] < cost)
			continue;

		if (current == E)
		{
			start = min(start, dist[current][cnt]);
			continue;
		}

		for (auto n : arr[current])
		{
			int next = n.second;
			long long cost = (long long)n.first;

			if (cnt + 1 <= N && dist[next][cnt + 1] > dist[current][cnt] + cost)
			{
				dist[next][cnt + 1] = dist[current][cnt] + cost;
				pq.push({ {dist[next][cnt + 1], cnt + 1}, next });
			}
		}
	}
	return;
}

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K >> S >> E;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back({ c, b });
		arr[b].push_back({ c, a });
	}

	long long start = 987654321;
	dijk(start);
	cout << start << "\n";

	vector<pair<long long, long long>> v;
	for (int i = 1; i <= N; i++)
	{
		if (dist[E][i] != 987654321)
			v.push_back({ dist[E][i], (long long)i });
	}

	long long sum = 0, tax;
	for (int i = 0; i < K; i++)
	{
		cin >> tax;
		sum += tax;

		long long answer = 987654321;
		for (auto vv : v)
			answer = min(answer, vv.first + vv.second*sum);

		cout << answer << "\n";
	}

	return 0;
}