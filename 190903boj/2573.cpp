/**
*	BOJ
*	No.2573	빙산
*	@author	peter9378
*	@date		2019.09.03
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int arr[303][303];
vector<pair<int, int>> v;

int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };

bool visit[303][303];

bool all_melt()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j])
				return false;
		}
	}
	return true;
}

void year()
{
	vector<int> temp;
	for (int i = 0; i < v.size(); i++)
	{
		int x = v[i].first;
		int y = v[i].second;

		int count = 0;
		for (int k = 0; k < 4; k++)
		{
			int next_x = x + direction_x[k];
			int next_y = y + direction_y[k];

			if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < M && arr[x][y])
			{
				if (!arr[next_x][next_y])
					count++;
			}
		}
		temp.push_back(count);
	}
	for (int i = 0; i < temp.size(); i++)
		arr[v[i].first][v[i].second] = max(arr[v[i].first][v[i].second] - temp[i], 0);
}

bool separate()
{
	int size = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (arr[v[i].first][v[i].second])
			size++;
	}

	for (int i = 0; i < v.size(); i++)
	{
		int temp = 1;
		if (arr[v[i].first][v[i].second])
		{
			for (int a = 0; a < N; a++)
			{
				for (int b = 0; b < M; b++)
					visit[a][b] = false;
			}
			queue<pair<int, int>> q;
			q.push(make_pair(v[i].first, v[i].second));
			visit[v[i].first][v[i].second] = true;

			while (!q.empty())
			{
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int k = 0; k < 4; k++)
				{
					int next_x = x + direction_x[k];
					int next_y = y + direction_y[k];

					if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < M && !visit[next_x][next_y])
					{
						if (arr[next_x][next_y])
						{
							q.push(make_pair(next_x, next_y));
							temp++;
							visit[next_x][next_y] = true;
						}
					}
				}
			}

			if (size == temp)
				return false;
			else
				return true;
		}
	}
	return true;
}

void print()
{
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j])
				v.push_back(make_pair(i, j));
		}
	}

	int answer = 0;

	while (!separate())
	{
		year();
		//print();
		answer++;
	}

	if (all_melt())
		answer = 0;

	cout << answer;

	return 0;
}