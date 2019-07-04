/**
*	BOJ
*	No.1743	음식물 피하기
*	@author	peter9378
*	@date		2019.07.04
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };
int arr[101][101];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 0; i < K; i++)
	{
		int r, c;
		cin >> r >> c;

		arr[r-1][c-1] = 1;
	}

	int answer = -1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j])
			{
				queue<pair<int, int>> q;
				int count = 0;
				q.push(make_pair(i, j));

				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++)
					{
						int next_x = x + direction_x[k];
						int next_y = y + direction_y[k];

						if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < M)
						{
							if (arr[next_x][next_y])
							{
								arr[next_x][next_y] = 0;
								q.push(make_pair(next_x, next_y));
								count++;
							}
						}
					}
				}
				answer = max(answer, count);
			}
		}
	}

	cout << answer;

	return 0;
}