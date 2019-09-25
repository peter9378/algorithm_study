/**
*	BOJ
*	No.2468	안전 영역
*	@author	peter9378
*	@date		2019.09.26
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int arr[101][101];
bool visit[101][101];
int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };

void init()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			visit[i][j] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int top = -1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			top = max(top, arr[i][j]);
		}
	}

	int answer = -1;
	for (int rain = 0; rain <= top; rain++)
	{
		init();
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (visit[i][j])
					continue;

				if (arr[i][j] <= rain)
				{
					visit[i][j] = true;
					continue;
				}

				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				visit[i][j] = true;
				cnt++;

				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++)
					{
						int nx = x + direction_x[k];
						int ny = y + direction_y[k];

						if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visit[nx][ny] && arr[nx][ny] > rain)
						{
							q.push(make_pair(nx, ny));
							visit[nx][ny] = true;
						}
					}
				}
			}
		}
		answer = max(answer, cnt);
	}

	cout << answer;

	return 0;
}