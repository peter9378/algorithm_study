/**
*	baekjoon online judge
*	No. 2178	미로탐색
*	@author	peter9378
*	@date		2019.04.04
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int arr[101][101];
int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };


queue<pair<int, int>> q;

int ctoi(char c)
{
	return c - 48;
}


// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < M; j++)
			arr[i][j] = ctoi(s[j]);
	}

	q.push(make_pair(0, 0));
	arr[0][0] = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + direction_x[i];
			int next_y = y + direction_y[i];

			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M)
			{
				if (arr[next_x][next_y] == 1)
				{
					q.push(make_pair(next_x, next_y));
					arr[next_x][next_y] = arr[x][y] + 1;
				}
			}
		}
	}

	// print answer
	cout << arr[N-1][M-1];

	return 0;
}