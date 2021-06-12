/**
*	BOJ
*	No.11400	´ÜÀý¼±
*	@author	peter9378
*	@date		2021.06.12
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

#define MAX 100000

int V, E, arr[MAX + 1];
vector<int> v[MAX + 1];
set<pair<int, int>> answer;
int cnt = 1;

int dfs(int current, int previous)
{
	arr[current] = cnt++;

	int result = arr[current];
	for (auto child : v[current])
	{
		if (child == previous)
			continue;

		if (arr[child])
		{
			result = min(result, arr[child]);
			continue;
		}

		int prev = dfs(child, current);
		if (prev > arr[current])
		{
			int a = min(current, child);
			int b = max(current, child);
			if (!answer.count({ a, b }))
				answer.insert({ a, b });
		}

		result = min(result, prev);
	}
	return result;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E;
	if (V == 1)
	{
		cout << 0;
		return 0;
	}

	for (int i = 0; i < E; ++i)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= V; ++i)
	{
		if (!arr[i])
			dfs(i, 0);
	}

	cout << answer.size() << "\n";
	for (auto x : answer)
		cout << x.first << " " << x.second << "\n";

	return 0;
}
