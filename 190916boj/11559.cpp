/**
*	BOJ
*	No.11559	Puyo Puyo
*	@author	peter9378
*	@date		2019.09.16
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int arr[12][6];
int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };
bool visit[12][6];

void init()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
			visit[i][j] = false;
	}
}

bool boom()
{
	init();
	bool flag = false;
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			int color = 0;
			if (arr[i][j] && !visit[i][j])
			{
				color = arr[i][j];
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				visit[i][j] = true;

				int cnt = 1;
				vector<pair<int, int>> v;
				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					v.push_back(q.front());
					q.pop();

					for (int k = 0; k < 4; k++)
					{
						int nx = x + direction_x[k];
						int ny = y + direction_y[k];

						if (nx >= 0 && ny >= 0 && nx < 12 && ny < 6 && !visit[nx][ny] && arr[nx][ny] == color)
						{
							q.push(make_pair(nx, ny));
							visit[nx][ny] = true;
							cnt++;
						}
					}
				}

				if (cnt >= 4)
				{
					flag = true;
					for (int i = 0; i < v.size(); i++)
						arr[v[i].first][v[i].second] = 0;
				}
			}
		}
	}
	return flag;
}

void down()
{
	for (int j = 0; j < 6; j++)
	{
		queue<int> q;
		for (int i = 11; i >= 0; i--)
		{
			if (arr[i][j])
				q.push(arr[i][j]);
		}
		for (int i = 11; i >= 0; i--)
		{
			if (q.empty())
				arr[i][j] = 0;
			else
			{
				arr[i][j] = q.front();
				q.pop();
			}
		}
	}
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 12; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < 6; j++)
		{
			switch (s[j])
			{
			case '.':
				arr[i][j] = 0;
				break;
			case 'R':
				arr[i][j] = 1;
				break;
			case 'G':
				arr[i][j] = 2;
				break;
			case 'B':
				arr[i][j] = 3;
				break;
			case 'P':
				arr[i][j] = 4;
				break;
			case 'Y':
				arr[i][j] = 5;
				break;
			}
		}
	}

	int answer = 0;
	while (boom())
	{
		down();
		answer++;
	}

	cout << answer;

	return 0;
}