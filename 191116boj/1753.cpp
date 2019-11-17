/**
*	BOJ
*	No.1753	최단경로
*	@author	peter9378
*	@date		2019.11.16
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

int arr[20002];
vector<vector<pair<int, int>>> vv;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int V, E;
	cin >> V >> E;

	int K;
	cin >> K;

	vv.resize(V + 1);
	for (int i = 0; i < 20002; i++)
		arr[i] = -1;

	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		vv[u].push_back({ v, w });
	}

	priority_queue<pair<int, int>> q;
	q.push({ 0, K });
	while (!q.empty())
	{
		int current = q.top().second;
		int weight = -q.top().first;
		q.pop();

		if (arr[current] != -1)
			continue;

		arr[current] = weight;
		for (int i = 0; i < vv[current].size(); i++)
		{
			int next = vv[current][i].first;
			int distance = -vv[current][i].second - weight;
			if (arr[next] != -1)
				continue;
			q.push({ distance, next });
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (arr[i] == -1)
			cout << "INF\n";
		else
			cout << arr[i] << "\n";
	}

	return 0;
}
