/**
*	BOJ
*	No.1504	특정한 최단 경로
*	@author	peter9378
*	@date		2020.02.09
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

int N, E, should1, should2;
vector<pair<int, int>> arr[888];
int node[888];
int answer[2][4];
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void init()
{
	for (int i = 0; i < 888; i++)
		node[i] = 987654321;
}

void bfs(int start)
{
	init();
	node[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int a = pq.top().first;
		int b = pq.top().second;
		int size = arr[b].size();
		pq.pop();

		for (int i = 0; i < size; i++)
		{
			int next_a = arr[b][i].first;
			int next_b = arr[b][i].second;

			if (a + next_a <= node[next_b])
			{
				node[next_b] = a + next_a;
				pq.push({ a + next_a, next_b });
			}
		}
	}
	return;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> E;

	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		arr[a].push_back({ c, b });
		arr[b].push_back({ c, a });
	}

	cin >> should1 >> should2;

	bfs(1);
	answer[0][0] = node[should1];
	answer[1][0] = node[should2];

	bfs(should1);
	answer[0][1] = node[should2];
	answer[1][1] = node[N];

	bfs(should2);
	answer[0][2] = node[N];
	answer[1][2] = node[should1];

	bool flag = false;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (answer[i][j] == 987654321)
			{
				flag = true;
				i = 2;
				break;
			}
			else
				answer[i][3] += answer[i][j];
		}
	}

	if (flag)
		cout << -1;
	else
		cout << min(answer[0][3], answer[1][3]);

	return 0;
}
