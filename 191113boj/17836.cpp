/**
*	BOJ
*	No.17836	공주님을 구해라!
*	@author	peter9378
*	@date		2019.11.13
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int arr[101][101];
int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };
pair<int, int> gram;
int answer = 987654321;

void print()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
	cout << "current answer = " << answer << endl;
	cout << endl;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, T;
	cin >> N >> M >> T;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
			{
				gram = { i, j };
				arr[i][j] = 0;
			}
			else if (arr[i][j] == 1) arr[i][j] = -1;
		}
	}

	queue<pair<int, int>> q;
	q.push({ 0, 0 });
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

			if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < M && arr[next_x][next_y] == 0)
			{
				if (next_x == gram.first && next_y == gram.second)
					answer = min(answer, N + M - 2 + arr[x][y] - next_x - next_y);
				else if (next_x == N - 1 && next_y == M - 1)
					answer = min(answer, arr[x][y]);
				else
				{
					arr[next_x][next_y] = arr[x][y] + 1;
					q.push({ next_x, next_y });
				}
			}
		}
		//print();
	}

	if (answer == 987654321 || answer > T)
		cout << "Fail";
	else
		cout << answer;

	return 0;
}