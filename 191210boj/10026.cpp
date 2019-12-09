/**
*	BOJ
*	No.10026	적록색약
*	@author	peter9378
*	@date		2019.12.10
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

char arr[101][101];
bool visit[101][101];
int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };

void init()
{
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
			visit[i][j] = false;
	}
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < N; j++)
			arr[i][j] = s[j];
	}

	init();
	int normal = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visit[i][j])
			{
				normal++;
				queue<pair<int, int>> q;
				q.push({ i, j });
				char target = arr[i][j];
				visit[i][j] = true;

				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++)
					{
						int next_x = x + direction_x[k];
						int next_y = y + direction_y[k];

						if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N && !visit[next_x][next_y])
						{
							if (arr[next_x][next_y] == target)
							{
								q.push({ next_x, next_y });
								visit[next_x][next_y] = true;
							}
						}
					}
				}
			}
		}
	}

	init();
	int color = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visit[i][j])
			{
				color++;
				queue<pair<int, int>> q;
				q.push({ i, j });
				bool type = (arr[i][j] == 'B');
				visit[i][j] = true;

				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++)
					{
						int next_x = x + direction_x[k];
						int next_y = y + direction_y[k];

						if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N && !visit[next_x][next_y])
						{
							if (type)
							{
								if (arr[next_x][next_y] == 'B')
								{
									q.push({ next_x, next_y });
									visit[next_x][next_y] = true;
								}
							}
							else
							{
								if (arr[next_x][next_y] != 'B')
								{
									q.push({ next_x, next_y });
									visit[next_x][next_y] = true;
								}
							}
						}
					}
				}
			}
		}
	}

	cout << normal << " " << color;


	return 0;
}