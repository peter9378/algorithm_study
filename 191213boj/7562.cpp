/**
*	BOJ
*	No.7562	나이트의 이동
*	@author	peter9378
*	@date		2019.12.13
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>
#include <cstring>
using namespace std;

int direction_x[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int direction_y[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int arr[303][303];
bool visit[303][303];

void init(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 0;
			visit[i][j] = false;
		}
	}
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		int I;
		cin >> I;

		init(I);

		int x, y;
		cin >> x >> y;

		int target_x, target_y;
		cin >> target_x >> target_y;

		queue<pair<int, int>> q;
		q.push({ x, y });
		visit[x][y] = true;

		bool flag = false;
		while (!q.empty())
		{
			x = q.front().first;
			y = q.front().second;
			q.pop();

			for (int i = 0; i < 8; i++)
			{
				int next_x = x + direction_x[i];
				int next_y = y + direction_y[i];

				if (next_x >= 0 && next_x < I && next_y >= 0 && next_y < I && !visit[next_x][next_y])
				{
					visit[next_x][next_y] = true;
					arr[next_x][next_y] = arr[x][y] + 1;
					q.push({ next_x, next_y });

					if (next_x == target_x && next_y == target_y)
					{
						flag = true;
						i = 8;
						break;
					}
				}
			}
			if (flag)
				break;
		}
		cout << arr[target_x][target_y] << "\n";
	}

	return 0;
}
