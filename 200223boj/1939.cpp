/**
*	BOJ
*	No.1939	중량제한
*	@author	peter9378
*	@date		2020.02.23
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

vector<pair<int, int>> arr[10001];
bool visit[10001];
int from, to;

bool bfs(int target)
{
	for (int i = 0; i < 10001; i++)
		visit[i] = false;

	queue<int> q;
	visit[from] = true;
	q.push(from);

	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		if (current == to)
			return true;

		for (int i = 0; i < arr[current].size(); i++)
		{
			if (!visit[arr[current][i].first] && arr[current][i].second >= target)
			{
				visit[arr[current][i].first] = true;
				q.push(arr[current][i].first);
			}
		}
	}
	return false;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		arr[a].push_back({ b, c });
		arr[b].push_back({ a, c });
	}

	cin >> from >> to;
	int answer = 0, left = 1, right = 1000000000, mid;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (bfs(mid))
		{
			answer = max(answer, mid);
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << answer;

	return 0;
}
