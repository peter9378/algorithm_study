/**
*	BOJ
*	No.11266	단절점
*	@author	peter9378
*	@date		2020.03.31
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

int idx;
vector<int> arr[10001];
bool visit[10001];
int counting[10001];

int dfs(int current, bool check)
{
	int result = counting[current] = ++idx;
	int child = 0;

	for (int i = 0; i < arr[current].size(); i++)
	{
		int next = arr[current][i];
		if (counting[next])
		{
			result = min(result, counting[next]);
			continue;
		}

		child++;
		int previous = dfs(next, false);

		if (!check && counting[current] <= previous)
			visit[current] = true;
		result = min(result, previous);
	}

	if (check)
		visit[current] = child >= 2;
	return result;
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
		int a, b;
		cin >> a >> b;

		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	for (int i = 1; i <= V; i++)
	{
		if (!counting[i])
			dfs(i, true);
	}

	int answer = 0;
	for (int i = 1; i <= V; i++)
	{
		if (visit[i])
			answer++;
	}

	cout << answer << "\n";
	for (int i = 1; i <= V; i++)
	{
		if (visit[i])
			cout << i << " ";
	}

	return 0;
}