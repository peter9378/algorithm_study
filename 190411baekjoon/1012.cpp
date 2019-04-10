/**
*	baekjoon online judge
*	No. 1012	유기농 배추
*	@author	peter9378
*	@date		2019.04.11
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int arr[51][51];
bool visit[51][51];
int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };

// init
void init()
{
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			arr[i][j] = 0;
			visit[i][j] = false;
		}
	}
}

// dfs
void dfs(int x, int y)
{
	visit[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + direction_x[i];
		int next_y = y + direction_y[i];

		if (next_x >= 0 && next_x < M && next_y >=0 && next_y < N && !visit[next_x][next_y] && arr[next_x][next_y])
			dfs(next_x, next_y);
	}
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int T;
	cin >> T;

	while (T--)
	{
		int K;
		cin >> M >> N >> K;

		init();

		queue<pair<int, int>> q;
		for (int i = 0; i < K; i++)
		{
			int x, y;
			cin >> x >> y;

			arr[x][y] = 1;
			q.push(make_pair(x, y));
		}

		int answer = 0;

		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (arr[x][y] && !visit[x][y])
			{
				dfs(x, y);
				answer++;
			}
		}

		// print answer
		cout << answer << "\n";
	}


	return 0;
}