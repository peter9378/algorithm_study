/**
*	BOJ
*	No.1031	스타 대결
*	@author	peter9378
*	@date		2021.02.22
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

int N, M;
vector<int> v[111];
int visit[111][111], f[111][111];
const int src = 0, sink = 110;

void add_edge(int from, int to, int value)
{
	v[from].push_back(to);
	v[to].push_back(from);
	visit[from][to] = value;
}

int flow()
{
	int result = 0;

	while (true)
	{
		queue<int> q;
		int temp[111];

		fill(temp + 1, temp + 111, -1);
		q.push(src);
		while (!q.empty() && temp[sink] == -1)
		{
			int here = q.front();
			q.pop();

			for (auto next : v[here])
			{
				if (visit[here][next] - f[here][next] > 0 && temp[next] == -1)
				{
					q.push(next);
					temp[next] = here;
				}
			}
		}

		if (temp[sink] == -1)
			break;
		for (int i = sink; i != src; i = temp[i])
			f[temp[i]][i]++, f[i][temp[i]]--;
		result++;
	}

	return result;
}

bool check(int from, int to)
{
	f[from][to] = 0, f[to][from] = 1;
	f[src][from]--, f[from][src]++;
	f[to][sink]--, f[sink][to]++;

	int result = 0;
	while (true)
	{
		queue<int> q;
		int temp[111];
		fill(temp + 1, temp + 111, -1);
		q.push(src);
		while (!q.empty() && temp[sink] == -1)
		{
			int current = q.front();
			q.pop();

			for (auto next : v[current])
			{
				if ((current == from && next == to) || (current == to && next == from))
					continue;
				if (current > src && current < from && f[current][next] == 0)
					continue;
				if (current == from && next > N && next < to && f[current][next] == 0)
					continue;

				if (visit[current][next] - f[current][next] > 0 && temp[next] == -1)
				{
					q.push(next);
					temp[next] = current;
				}
			}
		}

		if (temp[sink] == -1)
			break;

		for (int i = sink; i != src; i = temp[i])
			f[temp[i]][i]++, f[i][temp[i]]--;
		result++;
	}

	return result == 1;
}


// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int a = 0, b = 0;
	for (int i = 1; i <= N; i++)
	{
		int temp;
		cin >> temp;

		add_edge(src, i, temp);
		a += temp;
	}

	for (int i = 1; i <= M; i++)
	{
		int temp;
		cin >> temp;

		add_edge(i + N, sink, temp);
		b += temp;
	}

	if (a != b)
	{
		cout << "-1\n";
		return 0;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			add_edge(i, j + N, 1);
	}

	if (flow() != a)
	{
		cout << "-1\n";
		return 0;
	}

	else
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (f[i][j + N])
				{
					if (!check(i, j + N))
					{
						f[i][j + N] = 1, f[j + N][i] = 0;
						f[src][i]++, f[i][src]--;
						f[j + N][sink]++, f[sink][j + N]--;
					}
				}
			}
		}
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
				cout << f[i][j + N];
			cout << "\n";
		}
	}

	return 0;
}
