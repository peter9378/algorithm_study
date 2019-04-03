/**
*	baekjoon online judge
*	No. 7569	토마토
*	@author	peter9378
*	@date		2019.04.04
*/
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int arr[101][101][101];
int direction_x[] = { 0, 1, 0, -1 , 0, 0};
int direction_y[] = { 1, 0, -1, 0 , 0, 0};
int direction_z[] = { 0, 0, 0, 0, 1, -1 };

struct tpair{
	int z, x, y;
};

queue<tpair> q;


// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int M, N, H;
	cin >> M >> N >> H;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> arr[i][j][k];

				if (arr[i][j][k] == 1)
					q.push({ i, j, k });
			}
		}
	}

	int answer = 0;
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		q.pop();

		answer = max(answer, arr[z][x][y]);

		for (int i = 0; i < 6; i++)
		{
			int next_x = x + direction_x[i];
			int next_y = y + direction_y[i];
			int next_z = z + direction_z[i];

			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && next_z >= 0 && next_z < H)
			{
				if (!arr[next_z][next_x][next_y])
				{
					q.push({ next_z, next_x, next_y });
					arr[next_z][next_x][next_y] = arr[z][x][y] + 1;
				}
			}
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (!arr[i][j][k])
				{
					answer = 0;
					i = H;
					j = N;
					break;
				}
			}
		}
	}

	// print answer
	cout << answer - 1;

	return 0;
}