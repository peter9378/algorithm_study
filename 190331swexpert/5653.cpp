/**
*	SW Expert Academy
*	No. 5653	줄기세포 배양
*	@author	peter9378
*	@date		2019.03.31
*/
#include <iostream>
#include <queue>
using namespace std;

#define MAX 500


// Cell structure
struct Cell {
	Cell() {};
	Cell(int life, int count) :life(life), count(count) {};
	int life = 0;
	int count = 0;
};


Cell grid[MAX][MAX];
int direction_x[] = { 0, -1, 0, 1 };
int direction_y[] = { 1, 0, -1, 0 };

// initialize whole array
void init()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			grid[i][j].life = 0;
			grid[i][j].count = 0;
		}
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
		int N, M, K;
		cin >> N >> M >> K;

		// queue array. index == life power
		queue<pair<int, int>> q[11];
		init();

		// get grid
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int temp;
				cin >> temp;

				grid[i+ MAX/2][j+ MAX/2] = Cell(temp, temp*2);

				// and add to q
				if (temp)
					q[temp].push(make_pair(i + MAX/2, j + MAX/2));
			}
		}

		// K times loop
		while (K--)
		{
			// starts with more power cell
			for (int i = 10; i > 0; i--)
			{
				int size = q[i].size();

				for (int j = 0; j < size; j++)
				{
					// check every cell in queue
					int x = q[i].front().first;
					int y = q[i].front().second;

					q[i].pop();
					grid[x][y].count--;

					// increase cell
					if (grid[x][y].life > grid[x][y].count)
					{
						// check 4 direction
						for (int k = 0; k < 4; k++)
						{
							int next_x = x + direction_x[k];
							int next_y = y + direction_y[k];

							// if next grid is empty
							if (grid[next_x][next_y].life == 0)
							{
								grid[next_x][next_y] = Cell(grid[x][y].life, 2 * grid[x][y].life);
								q[i].push(make_pair(next_x, next_y));
							}
						}
					}

					// if cell is still alive
					if (grid[x][y].count != 0)
						q[i].push(make_pair(x, y));
				}
			}
		}

		// print answer
		int answer = 0;

		for (int i = 1; i <= 10; i++)
			answer += q[i].size();

		cout << "#" << test_case << " " << answer << "\n";
	}

	return 0;
}