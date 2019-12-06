/**
*	BOJ
*	No.17144	미세먼지 안녕!
*	@author	peter9378
*	@date		2019.12.06
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

int R, C, T;
int arr[55][55];
int temp[55][55];
int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1,  0, -1, 0 };
queue<pair<int, int>> dust;
vector<int> fresher;

void init()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (arr[i][j] > 0)
				dust.push({ i, j });
			temp[i][j] = 0;
		}
	}
}

void print()
{
	cout << endl;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 8; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
	cout << endl;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C >> T;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == -1)
				fresher.push_back(i);
		}
	}

	while (T--)
	{
		// dust expansion
		init();
		while (!dust.empty())
		{
			int x = dust.front().first;
			int y = dust.front().second;
			int remain = 0;
			dust.pop();

			if (arr[x][y] == 0)
				continue;

			for (int i = 0; i < 4; i++)
			{
				int next_x = x + direction_x[i];
				int next_y = y + direction_y[i];

				if (next_x >= 0 && next_x < R && next_y >= 0 && next_y < C && arr[next_x][next_y] != -1)
				{
					if (arr[x][y] / 5)
					{
						temp[next_x][next_y] += arr[x][y] / 5;
						remain += arr[x][y] / 5;
					}
				}
			}

			temp[x][y] -= remain;
			//print();
		}

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
				arr[i][j] += temp[i][j];
		}

		//print();

		// fresher operation - upside
		for (int i = fresher[0] - 1; i > 0; i--)
			arr[i][0] = arr[i - 1][0];
		for (int i = 0; i < C - 1; i++)
			arr[0][i] = arr[0][i + 1];
		for (int i = 0; i < fresher[0]; i++)
			arr[i][C - 1] = arr[i + 1][C - 1];
		for (int i = C - 1; i > 1; i--)
			arr[fresher[0]][i] = arr[fresher[0]][i - 1];
		arr[fresher[0]][1] = 0;

		// fresher operation - bottomside
		for (int i = fresher[1] + 1; i < R; i++)
			arr[i][0] = arr[i + 1][0];
		for (int i = 0; i < C; i++)
			arr[R - 1][i] = arr[R - 1][i + 1];
		for (int i = R - 1; i > fresher[1]; i--)
			arr[i][C - 1] = arr[i - 1][C - 1];
		for (int i = C - 1; i > 1; i--)
			arr[fresher[1]][i] = arr[fresher[1]][i - 1];
		arr[fresher[1]][1] = 0;

		//print();
	}

	int answer = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			answer += arr[i][j];
	}

	cout << answer + 2;

	return 0;
}
