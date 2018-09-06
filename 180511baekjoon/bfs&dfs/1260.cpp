/**
*	baekjoon_stepbystep
*	No. 1260	DFS와 BFS
*	@author	peter9378
*	@date		2018.05.11
*/
#include <iostream>
#include <queue>
using namespace std;

bool visit[1001];
bool graph[1001][1001];
int N;

void bfs(int num)
{
	queue<int> q;

	for (int i = 0; i <= N; i++)
		visit[i] = false;

	q.push(num);
	visit[num] = true;

	while (!q.empty())
	{
		int temp = q.front();
		q.pop();

		cout << temp << " ";

		for (int i = 1; i <= N; i++)
		{
			if (graph[temp][i] && !visit[i])
			{
				visit[i] = true;
				q.push(i);
			}
		}
	}
}

void dfs(int num)
{
	cout << num << " ";

	for (int i = 1; i <= N; ++i)
	{
		if (!visit[i] && graph[num][i])
		{
			visit[i] = true;
			dfs(i);
		}
	}
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int M, V;
	cin >> N >> M >> V;

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		graph[a][b] = graph[b][a] = true;
	}

	visit[V] = true;
	dfs(V);
	cout << "\n";
	bfs(V);

	return 0;
}