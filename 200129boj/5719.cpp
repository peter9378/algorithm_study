/**
*	BOJ
*	No.5719	거의 최단 경로
*	@author	peter9378
*	@date		2020.01.29
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

int N, M, X, Y, Z, S, E;
int arr[505][505];
int dp[505];

void dijk()
{
	for (int i = 0; i < 505; i++)
		dp[i] = -1;

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, S });

	while (!pq.empty())
	{
		int current = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (dp[current] != -1)
			continue;

		dp[current] = cost;

		for (int i = 0; i < N; i++)
		{
			if (arr[current][i] == -1 || dp[i] != -1)
				continue;

			pq.push({ -cost - arr[current][i],i });
		}
	}
}

void del()
{
	queue<int> q;
	q.push(E);
	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		for (int i = 0; i < N; i++)
		{
			if (dp[current] == dp[i] + arr[i][current] && arr[i][current] != -1)
			{
				arr[i][current] = -1;
				q.push(i);
			}
		}
	}
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	while (N != 0 && M != 0)
	{
		cin >> S >> E;

		for (int i = 0; i < 505; i++)
		{
			for (int j = 0; j < 505; j++)
				arr[i][j] = -1;
		}

		for (int i = 0; i < M; i++)
		{
			cin >> X >> Y >> Z;
			arr[X][Y] = Z;
		}

		dijk();
		del();
		dijk();
		cout << dp[E] << "\n";

		cin >> N >> M;
	}

	return 0;
}
