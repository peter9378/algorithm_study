/**
*	baekjoon online judge
*	No. 7576 토마토
*	@author	peter9378
*	@date		2018.05.14
*/
#include <iostream>
#include <queue>
using namespace std;

// 토마토 배열
int arr[1001][1001];

// 방향 배열
int direction_x[4] = { 0, 0, -1, 1 };
int direction_y[4] = { -1, 1, 0, 0 };
queue<pair<int, int>> q;

int max(int a, int b)
{
	return a > b ? a : b;
}


// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M, N;
	cin >> M >> N;

	// 토마토 입력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				q.push({ i, j });
		}
	}

	int result = 0;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		result = max(result, arr[x][y]);

		for (int i = 0; i < 4; i++)
		{
			int temp_x = x + direction_x[i];
			int temp_y = y + direction_y[i];

			if (temp_x < 0 || temp_x >= N || temp_y < 0 || temp_y >= M)
				continue;

			if (arr[temp_x][temp_y] == 0)
			{
				q.push({ temp_x, temp_y });
				arr[temp_x][temp_y] = arr[x][y] + 1;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 0)
			{
				result = 0;
				i = M;
				j = M;
			}
		}
	}

	cout << result - 1;

	return 0;
}