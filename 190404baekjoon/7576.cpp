/**
*	baekjoon online judge
*	No. 7576	토마토
*	@author	peter9378
*	@date		2019.04.04
*/
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int arr[1001][1001];
int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };
queue<pair<int, int>> q;


// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int M, N;
	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];

			if (arr[i][j] == 1)
				q.push(make_pair(i, j));
		}
	}

	int answer = 0;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		answer = max(answer, arr[x][y]);

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + direction_x[i];
			int next_y = y + direction_y[i];

			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M)
			{
				if (!arr[next_x][next_y])
				{
					q.push(make_pair(next_x, next_y));
					arr[next_x][next_y] = arr[x][y] + 1;
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!arr[i][j])
			{
				answer = 0;
				i = N;
				break;
			}
		}
	}

	// print answer
	cout << answer - 1;

	return 0;
}