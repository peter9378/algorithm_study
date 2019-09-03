/**
*	BOJ
*	No.3197	백조의 호수
*	@author	peter9378
*	@date		2019.09.01
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int R, C;
string arr[1505];
vector<pair<int, int>> swan;
vector<pair<int, int>> melt;

int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };
bool visit[1505][1505];
int checkarr[1505][1505];

bool promise(int mid)
{
	pair<int, int> swan1 = make_pair(swan[0].first, swan[0].second);
	pair<int, int> swan2 = make_pair(swan[1].first, swan[1].second);

	queue<pair<int, int>> q;
	q.push(swan1);
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			visit[i][j] = false;
	}
	visit[q.front().first][q.front().second] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + direction_x[i];
			int next_y = y + direction_y[i];
			if (next_x == swan2.first && next_y == swan2.second)
				return true;

			if (next_x >= 0 && next_x < R && next_y >= 0 && next_y < C && !visit[next_x][next_y])
			{
				if (checkarr[next_x][next_y] <= mid)
				{
					q.push(make_pair(next_x, next_y));
					visit[next_x][next_y] = true;
				}
			}

		}
	}

	return false;
}

void day()
{
	set<pair<int, int>> s;
	for(int i=0;i<melt.size();i++)
	{
		int x = melt[i].first;
		int y = melt[i].second;
		arr[x][y] = '.';

		for (int k = 0; k < 4; k++)
		{
			int next_x = x + direction_x[k];
			int next_y = y + direction_y[k];

			if (next_x >= 0 && next_y >= 0 && next_x < R && next_y < C && !s.count(make_pair(next_x, next_y)))
			{
				if(arr[next_x][next_y] == 'X')
					s.insert(make_pair(next_x, next_y));
			}
		}
	}
	melt.clear();
	for (auto i = s.begin(); i != s.end(); i++)
		melt.push_back(*i);
	return;
}


// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		cin >> arr[i];
		for (int j = 0; j < C; j++)
		{
			if (arr[i][j] == 'L')
				swan.push_back(make_pair(i, j));
		}
	}

	queue<pair<int, int>> q;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (arr[i][j] == 'X')
			{
				for (int k = 0; k < 4; k++)
				{
					int next_x = i + direction_x[k];
					int next_y = j + direction_y[k];

					if (next_x >= 0 && next_y >= 0 && next_x < R && next_y < C)
					{
						if (arr[next_x][next_y] == '.' || arr[next_x][next_y] == 'L')
						{
							q.push(make_pair(i, j));
							checkarr[i][j] = 1;
							visit[i][j] = true;
							break;
						}
					}
				}
			}
		}
	}

	int all_melt = -1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int next_x = x + direction_x[k];
			int next_y = y + direction_y[k];

			if (next_x >= 0 && next_y >= 0 && next_x < R && next_y < C && !visit[next_x][next_y] && arr[next_x][next_y] == 'X')
			{
				q.push(make_pair(next_x, next_y));
				visit[next_x][next_y] = true;
				checkarr[next_x][next_y] = checkarr[x][y]+1;
				all_melt = max(all_melt, checkarr[next_x][next_y]);
			}
		}
	}

	int left = 0, right = all_melt, answer = 999999999;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (promise(mid))
		{
			if (answer > mid)
				answer = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	cout << answer;

	return 0;
}