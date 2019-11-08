/**
*	BOJ
*	No.1926	±×¸²
*	@author	peter9378
*	@date		2019.11.08
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int arr[505][505];
int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}

	int answer = 0;
	int maxx = -1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j])
			{
				queue<pair<int, int>> q;
				q.push({ i, j });
				int count = 0;

				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++)
					{
						int next_x = x + direction_x[k];
						int next_y = y + direction_y[k];

						if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < M && arr[next_x][next_y])
						{
							q.push({ next_x, next_y });
							arr[next_x][next_y] = 0;
							count++;
						}
					}
				}
				if (count == 0)
					count++;
				answer++;
				maxx = max(maxx, count);
			}
		}
	}

	if (answer == 0)
		cout << "0\n0";
	else
	{
		cout << answer << "\n";
		cout << maxx;
	}

	return 0;
}