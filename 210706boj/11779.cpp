/**
*	BOJ
*	No.11779	최소비용 구하기 2
*	@author	peter9378
*	@date		2021.07.06
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
int trace[1001];
vector<pair<int, int>> arr[1001];

vector<int> dijkstra(int start, int vertex)
{
	vector<int> distance(vertex, 987654321);
	distance[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int current = pq.top().second;
		pq.pop();

		if (distance[current] < cost)
			continue;

		for (int i = 0; i < arr[current].size(); i++)
		{
			int neighbor = arr[current][i].first;
			int neighborDistance = cost + arr[current][i].second;
			if (distance[neighbor] > neighborDistance)
			{
				distance[neighbor] = neighborDistance;
				trace[neighbor] = current;
				pq.push({ neighborDistance, neighbor });
			}
		}
	}
	return distance;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	N++;

	for (int i = 0; i < M; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		arr[u].push_back({ v, w });
	}

	int start, end;
	cin >> start >> end;

	vector<int> result = dijkstra(start, N);
	cout << result[end] << "\n";

	vector<int> v;
	int node = end;

	while (node)
	{
		v.push_back(node);
		node = trace[node];
	}

	cout << v.size() << "\n";

	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	return 0;
}
