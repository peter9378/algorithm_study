/**
*	baekjoon online judge
*	No. 16236	아기 상어
*	@author	peter9378
*	@date		2019.03.18
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct shark {
	int x, y;
	int size, kill, time;
};

int N, answer = 0;
int direction_x[] = { -1, 0, 1, 0 };
int direction_y[] = { 0, 1, 0, -1 };
int arr[21][21];
bool visit[21][21];

// check border
bool check(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < N;
}

// for comparision
bool compare(shark a, shark b)
{
	if (a.time <= b.time)
	{
		if (a.time == b.time)
		{
			if (a.x <= b.x)
			{
				if (a.x == b.x)
				{
					if (a.y < b.y)
						return true;
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	cin >> N;

	shark s;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];

			if (arr[i][j] == 9)
			{
				// init shark location
				arr[i][j] = 0;
				s = { i, j, 2, 0, 0 };
			}
		}
	}

	vector<shark> v;
	queue<shark> q;

	while (true)
	{
		v.clear();
		for (int i = 0; i < 21; i++)
		{
			for (int j = 0; j < 21; j++)
				visit[i][j] = false;
		}

		visit[s.x][s.y] = 1;
		q.push(s);

		// bfs
		while (!q.empty())
		{
			int x = q.front().x;
			int y = q.front().y;
			int size = q.front().size;
			int kill = q.front().kill;
			int time = q.front().time;
			q.pop();

			// check 4 directions
			for (int i = 0; i < 4; i++)
			{
				int next_x = x + direction_x[i];
				int next_y = y + direction_y[i];

				if (check(next_x, next_y) && !visit[next_x][next_y])
				{
					if (arr[next_x][next_y] == 0 || arr[next_x][next_y] == size)
					{
						// same size fish or no fish
						visit[next_x][next_y] = true;
						q.push({ next_x, next_y, size, kill, time + 1 });
					}
					else if (arr[next_x][next_y] < size)
					{
						// smaller fish
						visit[next_x][next_y] = true;
						v.push_back({ next_x, next_y, size, kill + 1, time + 1 });
					}
				}
			}
		}

		if (v.size() == 0)
			break;

		// sort
		sort(v.begin(), v.end(), compare);

		if (v[0].size == v[0].kill)
		{
			v[0].size++;
			v[0].kill = 0;
		}

		// remove dead fish
		arr[v[0].x][v[0].y] = 0;
		answer += v[0].time;
		s = { v[0].x, v[0].y, v[0].size, v[0].kill, 0 };
	}

	// print answer
	cout << answer;

	return 0;
}