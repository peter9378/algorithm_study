/**
*	BOJ
*	No.2206	벽 부수고 이동하기
*	@author	peter9378
*	@date		2019.12.16
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

int N, M;
int answer = 987654321;
int arr[1001][1001];
bool visit[1001][1001][2];
int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < M; j++)
			arr[i][j] = s[j] - '0';
	}

	queue <pair<pair<int, int>, pair<int, int>>> q;	// x, y / use, distance
	q.push({ {0, 0}, { false, 1} });
	visit[0][0][0] = true;

	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		bool use = q.front().second.first;
		int distance = q.front().second.second;
		q.pop();

		if (x == N - 1 && y == M - 1)
		{
			answer = distance;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + direction_x[i];
			int next_y = y + direction_y[i];

			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M)
			{
				if (arr[next_x][next_y] == 1 && use == 0)
				{
					q.push({ {next_x, next_y}, { use + 1, distance + 1} });
					visit[next_x][next_y][use + 1] = true;
				}
				else if (arr[next_x][next_y] == 0 && !visit[next_x][next_y][use])
				{
					q.push({ {next_x, next_y}, {use, distance + 1} });
					visit[next_x][next_y][use] = true;
				}
			}
		}
	}

	if (answer == 987654321)
		cout << -1;
	else
		cout << answer;

	return 0;
}
