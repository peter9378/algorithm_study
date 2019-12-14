/**
*	BOJ
*	No.2589	º¸¹°¼¶
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

int N, M;
int answer = -1;
int arr[55][55];
int copy_arr[55][55];
bool visit[55][55];
int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };

void get_copy()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			copy_arr[i][j] = arr[i][j];
	}
}

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	vector<pair<int, int>> land;
	q.push({ x, y });
	land.push_back({ x, y });
	visit[x][y] = true;

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + direction_x[i];
			int next_y = y + direction_y[i];

			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && !visit[next_x][next_y] && arr[next_x][next_y])
			{
				visit[next_x][next_y] = true;
				q.push({ next_x, next_y });
				land.push_back({ next_x, next_y });
			}
		}
	}

	for (int i = 0; i < land.size(); i++)
	{
		int temp = -1;
		get_copy();
		q.push({ land[i].first, land[i].second });

		while (!q.empty())
		{
			x = q.front().first;
			y = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++)
			{
				int next_x = x + direction_x[k];
				int next_y = y + direction_y[k];

				if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && copy_arr[next_x][next_y] == 1)
				{
					copy_arr[next_x][next_y] = copy_arr[x][y] + 1;
					q.push({ next_x, next_y });
					temp = max(copy_arr[next_x][next_y], temp);
				}

			}
		}
		answer = max(answer, temp);
	}
	return;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < M; j++)
		{
			if (s[j] == 'L')
				arr[i][j] = 1;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 0)
			{
				visit[i][j] = true;
				continue;
			}
			bfs(i, j);
		}
	}

	cout << answer - 1;

	return 0;
}
