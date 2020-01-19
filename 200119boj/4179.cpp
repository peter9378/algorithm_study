/**
*	BOJ
*	No.4179	불!
*	@author	peter9378
*	@date		2020.01.19
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

string arr[1001];
queue<pair<int, int>> q;
queue<pair<int, int>> fire;
int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int R, C;
	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		cin >> arr[i];

		for (int j = 0; j < C; j++)
		{
			if (arr[i][j] == 'F')
				fire.push({ i, j });
			else if (arr[i][j] == 'J')
				q.push({ i, j });
		}
	}

	int answer = 0, temp;
	bool flag = false, possible = true;
	while (true)
	{
		answer++;
		temp = fire.size();
		while (temp--)
		{
			int x = fire.front().first;
			int y = fire.front().second;
			fire.pop();

			for (int k = 0; k < 4; k++)
			{
				int next_x = x + direction_x[k];
				int next_y = y + direction_y[k];

				if (next_x >= 0 && next_y >= 0 && next_x < R && next_y < C)
				{
					if (arr[next_x][next_y] == '.' || arr[next_x][next_y] == 'J')
					{
						arr[next_x][next_y] = 'F';
						fire.push({ next_x, next_y });
					}
				}
			}
		}

		temp = q.size();
		while (temp--)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++)
			{
				int next_x = x + direction_x[k];
				int next_y = y + direction_y[k];

				if (next_x >= 0 && next_y >= 0 && next_x < R && next_y < C)
				{
					if (arr[next_x][next_y] == '.')
					{
						arr[next_x][next_y] = 'J';
						q.push({ next_x, next_y });
					}
				}
				else
				{
					cout << answer;
					return 0;
				}
			}
		}
		if (q.size() == 0)
			break;
	}

	cout << "IMPOSSIBLE";

	return 0;
}
