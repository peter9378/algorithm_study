/**
*	BOJ
*	No.1197	최소 스패닝 트리
*	@author	peter9378
*	@date		2019.11.13
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

bool visit[10001];
vector<pair<int, int>> edge[10001];

long long prim()
{
	long long answer = 0;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0, 1 });

	while (!q.empty())
	{
		pair<int, int> current = q.top();
		q.pop();

		if (visit[current.second])
			continue;
		visit[current.second] = true;
		answer += current.first;

		for (int i = 0; i < edge[current.second].size(); i++)
		{
			if (!visit[edge[current.second][i].second])
				q.push(edge[current.second][i]);
		}
	}
	return answer;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int V, E;
	cin >> V >> E;

	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({ c, b });
		edge[b].push_back({ c, a });
	}

	cout << prim();

	return 0;
}