/**
*	BOJ
*	No.1707	이분 그래프
*	@author	peter9378
*	@date		2019.12.14
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

int V, E;
vector<int> arr[20002];
int check[20002];
bool visit[20002];

void init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		check[i] = 0;
		visit[i] = false;
		arr[i].clear();
	}
}

void bfs()
{
	for (int i = 1; i <= V; i++)
	{
		if (!visit[i])
		{
			queue<int> q;
			q.push(i);
			visit[i] = true;

			while (!q.empty())
			{
				int current = q.front();
				int color = check[current] ? check[current] : 1;
				q.pop();

				for (int i = 0; i < arr[current].size(); i++)
				{
					if (visit[arr[current][i]])
					{
						if (check[arr[current][i]] == color)
						{
							cout << "NO\n";
							return;
						}
					}
					else
					{
						q.push(arr[current][i]);
						if (color == 1)
							check[arr[current][i]] = 2;
						else if (color == 2)
							check[arr[current][i]] = 1;
						visit[arr[current][i]] = true;
					}
				}
			}
		}
	}
	cout << "YES\n";
	return;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K;
	cin >> K;

	while (K--)
	{
		cin >> V >> E;

		init(V);
		int a, b;
		for (int i = 0; i < E; i++)
		{
			cin >> a >> b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}

		bfs();
	}


	return 0;
}
