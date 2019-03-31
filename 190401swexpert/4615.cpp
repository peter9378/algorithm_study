/**
*	SW Expert Academy
*	No. 4615	재미있는 오셀로 게임
*	@author	peter9378
*	@date		2019.04.01
*/
#include <iostream>
#include <queue>
using namespace std;

// board array. 0: empty 1: black 2: white
int arr[11][11];

// 8-way direction
int direction_x[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int direction_y[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

// initialize board array
void init()
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
			arr[i][j] = 0;
	}
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		// input data
		int N, M;
		cin >> N >> M;

		// initialize board array
		init();
		arr[N / 2][N / 2] = arr[N / 2 + 1][N / 2 + 1] = 2;
		arr[N / 2][N / 2 + 1] = arr[N / 2 + 1][N / 2] = 1;

		for (int i = 0; i < M; i++)
		{
			int x, y, color;
			cin >> x >> y >> color;

			arr[x][y] = color;

			// check 8 direction
			for (int j = 0; j < 8; j++)
			{
				int next_x = x + direction_x[j];
				int next_y = y + direction_y[j];

				// border check
				if (next_x <1 || next_x>N || next_y<1 || next_y>N)
					continue;

				queue<pair<int, int>> q;
				bool flag = true;
				while (arr[next_x][next_y] != color)
				{
					// if empty, break
					if (arr[next_x][next_y] == 0)
					{
						flag = false;
						break;
					}
					// add queue when color is different
					q.push(make_pair(next_x, next_y));
					next_x += direction_x[j];
					next_y += direction_y[j];
				}

				// change color
				if (flag)
				{
					while (!q.empty())
					{
						arr[q.front().first][q.front().second] = color;
						q.pop();
					}
				}
			}
		}

		// calculate color
		int black=0, white = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				switch (arr[i][j])
				{
				case 1:
					black++;
					break;
				case 2:
					white++;
					break;
				}
			}
		}
		
		// print answer
		cout << "#" << test_case << " " << black << " " << white << "\n";
	}

	return 0;
}