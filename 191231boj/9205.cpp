/**
*	BOJ
*	No.9205	맥주 마시면서 걸어가기
*	@author	peter9378
*	@date		2019.12.31 - Goodbye 2019
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

int T, N;
bool answer;
vector<pair<int, int>> dist;
bool visit[101];

bool check(int a, int b, int c, int d)
{
	return abs(a - c) + abs(b - d) <= 1000;
}

void dfs(int index)
{
	if (index == N + 1)
	{
		answer = true;
		return;
	}

	for (int i = 1; i < N + 2; i++)
	{
		if (!visit[i])
		{
			if (check(dist[index].first, dist[index].second, dist[i].first, dist[i].second))
			{
				visit[i] = true;
				dfs(i);
			}
		}
	}
	return;
}

void init()
{
	for (int i = 0; i < 101; i++)
		visit[i] = false;
	dist.clear();
	answer = false;
	return;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	while (T--)
	{
		cin >> N;
		init();

		for (int i = 0; i < N + 2; i++)
		{
			int x, y;
			cin >> x >> y;
			dist.push_back({ x, y });
		}

		dfs(0);
		if (answer)
			cout << "happy\n";
		else
			cout << "sad\n";
	}
	return 0;
}
