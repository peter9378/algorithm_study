/**
*	BOJ
*	No.17244	아맞다우산
*	@author	peter9378
*	@date		2019.09.26
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
string arr[101];
int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };
int temp[101][101];
bool visit[101][101];

void init()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visit[i][j] = false;
			if (arr[i][j] == '#')
				temp[i][j] = -1;
			else
				temp[i][j] = 0;
		}
	}
}

int bfs(pair<int, int> from, pair<int, int> to)
{
	init();
	queue<pair<int, int>> q;
	visit[from.first][from.second] = true;
	q.push(from);

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + direction_x[i];
			int ny = y + direction_y[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M && !visit[nx][ny])
			{
				if (temp[nx][ny] == -1)
					continue;
				if (nx == to.first && ny == to.second)
					return temp[x][y] + 1;

				q.push(make_pair(nx, ny));
				temp[nx][ny] = temp[x][y] + 1;
				visit[nx][ny] = true;
			}
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;

	pair<int, int> start;
	pair<int, int> exit;
	vector<pair<int, int>> item;
	int index = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		for (int j = 0; j < arr[i].length(); j++)
		{
			if (arr[i][j] == 'S')
				start = make_pair(i, j);
			else if (arr[i][j] == 'E')
				exit = make_pair(i, j);
			else if (arr[i][j] == 'X')
				item.push_back(make_pair(i, j));
		}
	}

	vector<int> check;
	for (int i = 0; i < item.size(); i++)
		check.push_back(i);

	int answer = 99999;
	if (item.empty())
		answer = bfs(start, exit);
	else
	{
		do
		{
			int time = 0;
			time += bfs(start, make_pair(item[check.front()].first, item[check.front()].second));
			for (int i = 1; i < item.size(); i++)
				time += bfs(make_pair(item[check[i - 1]].first, item[check[i - 1]].second), make_pair(item[check[i]].first, item[check[i]].second));
			time += bfs(make_pair(item[check.back()].first, item[check.back()].second), exit);
			answer = min(answer, time);
		} while (next_permutation(check.begin(), check.end()));
	}
	cout << answer;

	return 0;
}