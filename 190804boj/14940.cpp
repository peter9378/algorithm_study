/**
*	BOJ
*	No. 14940	쉬운 최단거리
*	@author	peter9378
*	@date		2019.08.04
*/
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int arr[1001][1001];
bool visit[1001][1001];
int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
			{
				q.push(make_pair(i, j));
				arr[i][j] = 0;
				visit[i][j] = true;
			}
			else if (arr[i][j] == 0)
				visit[i][j] = true;
		}
	}

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + direction_x[i];
			int next_y = y + direction_y[i];

			if (next_x > -1 && next_y > -1 && next_x < n && next_y < m && !visit[next_x][next_y] && arr[next_x][next_y])
			{
				arr[next_x][next_y] = arr[x][y]+1;
				q.push(make_pair(next_x, next_y));
				visit[next_x][next_y] = true;
			}
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visit[i][j])
				arr[i][j] = -1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}


	return 0;
}