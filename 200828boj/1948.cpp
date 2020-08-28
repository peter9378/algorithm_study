/**
*	BOJ
*	No.1948	임계경로
*	@author	peter9378
*	@date		2020.08.28
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

#define MAX 100002

int N, M, start, endd, answer, idx[MAX], dist[MAX];
vector<pair<int, int>> arr[MAX], rarr[MAX];
bool check[MAX];

void dfs(int target)
{
	if (check[target])
		return;

	check[target] = true;

	for (pair<int, int> p : rarr[target])
	{
		int next = p.first;
		int weight = p.second;

		if (dist[target] == dist[next] + weight)
		{
			dfs(next);
			answer++;
		}
	}
}



// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		idx[b]++;
		arr[a].push_back({ b, c });
		rarr[b].push_back({ a, c });
	}

	cin >> start >> endd;

	queue<int> q;
	for (int i = 1; i < N; i++)
	{
		if (!idx[i])
			q.push(i);
	}

	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		for (pair<int, int> p : arr[current])
		{
			int next = p.first;
			int weight = p.second;

			if (dist[next] < dist[current] + weight)
				dist[next] = dist[current] + weight;

			if (--idx[next] == 0)
				q.push(next);
		}
	}

	dfs(endd);

	int result = 0;
	for (int i = 1; i <= N; i++)
		result = max(result, dist[i]);

	cout << result << "\n" << answer;

	return 0;
}