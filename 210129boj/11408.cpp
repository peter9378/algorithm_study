/**
*	BOJ
*	No.11408	¿­Ç÷°­È£ 5
*	@author	peter9378
*	@date		2021.01.29
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


int arr[802][802];
int m[802][802];
int cost[802][802];
vector<int> v[802];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	int start = 0, end = 801;
	for (int i = 1; i <= N; i++)
	{
		arr[start][i] = 1;
		v[start].push_back(i);
		v[i].push_back(start);
	}

	for (int i = 1; i <= M; i++)
	{
		arr[i + 400][end] = 1;
		v[end].push_back(i + 400);
		v[i + 400].push_back(end);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 401; j <= 400 + M; j++)
			cost[i][j] = 2e9;
	}

	for (int i = 1; i <= N; i++)
	{
		int temp;
		cin >> temp;

		for (int j = 0; j < temp; j++)
		{
			int work, money;
			cin >> work >> money;
			cost[i][work + 400] = money;
			cost[work + 400][i] = -money;
			v[i].push_back(work + 400);
			v[work + 400].push_back(i);
			arr[i][work + 400] = 1;
		}
	}

	int answer = 0;
	int result = 0;
	while (true)
	{
		int temp[802];
		int distance[802];
		bool visit[802] = { 0, };

		fill(distance, distance + 802, 2e9);
		fill(temp, temp + 802, -1);

		deque<int> dq;
		dq.push_back(start);
		distance[start] = 0;
		visit[start] = true;
		while (!dq.empty())
		{
			int node = dq.front();
			dq.pop_front();
			visit[node] = false;

			for (auto n : v[node])
			{
				if (distance[n] > distance[node] + cost[node][n] && arr[node][n] > m[node][n])
				{
					distance[n] = distance[node] + cost[node][n];
					temp[n] = node;

					if (!visit[n])
					{
						visit[n] = true;
						dq.push_back(n);

						if (distance[dq.front()] > distance[dq.back()])
						{
							dq.push_front(dq.back());
							dq.pop_back();
						}
					}
				}
			}
		}

		if (temp[end] == -1)
			break;

		int flow = 2e9;
		for (int i = end; i != start; i = temp[i])
			flow = min(flow, arr[temp[i]][i] - m[temp[i]][i]);

		for (int i = end; i != start; i = temp[i])
		{
			result += cost[temp[i]][i];
			m[temp[i]][i] += flow;
			m[i][temp[i]] -= flow;
		}
		answer += flow;
	}

	cout << answer << "\n" << result << "\n";

	return 0;
}
