/**
*	baekjoon_stepbystep
*	No. 1260	DFS와 BFS
*	@author	peter9378
*	@date		2018.05.11
*/
#include <iostream>
using namespace std;

bool visit[1001];
bool graph[1001][1001];
int N;

void dfs(int num)
{
	visit[num] = 1;

	for (int i = 1; i <= N; ++i)
	{
		if (!visit[i] && graph[num][i])
			dfs(i);
	}
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = graph[b][a] = true;
	}

	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			answer++;
			dfs(i);
		}
	}

	cout << answer;

	return 0;
}