/**
*	baekjoon online judge
*	No. 4963	섬의 개수
*	@author	peter9378
*	@date		2019.04.09
*/
#include <iostream>
#include <algorithm>
using namespace std;

int arr[51][51];
bool visit[51][51];
int direction_x[] = { 0, 1, 0, -1 , 1, 1, -1, -1};
int direction_y[] = { 1, 0, -1, 0 , -1, 1, 1, -1};
int w, h;

void init()
{
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
			visit[i][j] = false;
	}
}

void dfs(int x, int y)
{
	visit[x][y] = true;

	for (int i = 0; i < 8; i++)
	{
		int next_x = x + direction_x[i];
		int next_y = y + direction_y[i];

		if (next_x >= 0 && next_x < h && next_y >= 0 && next_y < w)
		{
			if (!visit[next_x][next_y] && arr[next_x][next_y])
				dfs(next_x, next_y);
		}
	}
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	cin >> w >> h;

	while (w && h)
	{
		init();
		int answer = 0;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
				cin >> arr[i][j];
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (!visit[i][j] && arr[i][j])
				{
					dfs(i, j);
					answer++;
				}
			}
		}

		// print answer
		cout << answer << "\n";
		cin >> w >> h;
	}

	return 0;
}