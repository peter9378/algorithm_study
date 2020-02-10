/**
*	BOJ
*	No.1167	트리의 지름
*	@author	peter9378
*	@date		2020.02.10
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
using namespace std;

int V, answer = 0, target = 0;
bool visit[100001];
vector<pair<int, int>> arr[100001];

void dfs(int here, int current)
{
	if (visit[here])
		return;

	visit[here] = true;

	if (answer < current)
	{
		answer = current;
		target = here;
	}

	for (int i = 0; i < arr[here].size(); i++)
		dfs(arr[here][i].first, current + arr[here][i].second);
	return;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V;
	for (int i = 0; i < V; i++)
	{
		int a;
		cin >> a;

		while (true)
		{
			int b, c;
			cin >> b;
			if (b == -1)
				break;

			cin >> c;
			arr[a].push_back({ b, c });
		}
	}

	dfs(1, 0);
	for (int i = 0; i < 100001; i++)
		visit[i] = false;

	dfs(target, 0);
	cout << answer;

	return 0;
}
