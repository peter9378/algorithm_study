/**
*	BOJ
*	No.1520	내리막 길
*	@author	peter9378
*	@date		2019.11.04
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

int M, N;
int arr[505][505];
int dp[505][505];

int direction_x[] = { 1, 0, -1, 0 };
int direction_y[] = { 0, 1, 0, -1 };

int dfs(int x, int y)
{
	if (x == 0 && y == 0)
		return 1;

	if (dp[x][y] == -1)
	{
		dp[x][y] = 0;

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + direction_x[i];
			int next_y = y + direction_y[i];

			if (next_x >= 0 && next_y >= 0 && next_x < M && next_y < N)
			{
				if (arr[x][y] < arr[next_x][next_y])
					dp[x][y] += dfs(next_x, next_y);
			}
		}
	}

	return dp[x][y];
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}

	cout << dfs(M - 1, N - 1);

	return 0;
}