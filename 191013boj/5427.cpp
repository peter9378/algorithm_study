/**
*	BOJ
*	No.5427	บา
*	@author	peter9378
*	@date		2019.10.13
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define MAX 1001

int R, C;
string arr[MAX];
bool visit[MAX][MAX];
bool visit2[MAX][MAX];
vector<pair<int, int>> v;
queue<pair<int, int>> water;
vector<pair<int, int>> cave;

int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };


void print()
{
	cout << endl;
	for (int i = 0; i < R; i++)
	{
		cout << arr[i] << endl;
	}
	cout << endl;
}

void init()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			visit[i][j] = false;
			visit2[i][j] = false;
		}
		arr[i] = "";
		v.clear();
		while (!water.empty())
			water.pop();
		cave.clear();
	}
}

bool isEscape(pair<int, int> target)
{
	for (int i = 0; i < cave.size(); i++)
	{
		if (cave[i] == target)
			return true;
	}
	return false;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		init();
		cin >> C >> R;

		for (int i = 0; i < R; i++)
		{
			cin >> arr[i];
			for (int j = 0; j < C; j++)
			{
				switch (arr[i][j])
				{
				case '*':
					water.push(make_pair(i, j));
					visit[i][j] = true;
					break;
				case '@':
					v.push_back(make_pair(i, j));
					arr[i][j] = '.';
					visit2[i][j] = true;
					break;
				case '#':
					visit[i][j] = true;
					visit2[i][j] = true;
					break;
				}
			}
		}

		for (int i = 0; i < R; i++)
		{
			if (arr[i][0] != '#')
				cave.push_back(make_pair(i, 0));
			if (arr[i][C - 1] != '#')
				cave.push_back(make_pair(i, C - 1));
		}

		for (int i = 1; i < C - 1; i++)
		{
			if (arr[0][i] != '#')
				cave.push_back(make_pair(0, i));
			if (arr[R - 1][i] != '#')
				cave.push_back(make_pair(R - 1, i));
		}

		if (find(cave.begin(), cave.end(), v[0]) != cave.end())
		{
			cout << "1\n";
			continue;
		}

		int count = 1;
		bool flag = false;
		while (true)
		{


			// flood
			queue<pair<int, int>> temp;
			while (!water.empty())
			{
				int x = water.front().first;
				int y = water.front().second;
				water.pop();

				for (int k = 0; k < 4; k++)
				{
					int next_x = x + direction_x[k];
					int next_y = y + direction_y[k];

					if (next_x >= 0 && next_y >= 0 && next_x < R && next_y < C && !visit[next_x][next_y])
					{
						if (arr[next_x][next_y] == '.')
						{
							arr[next_x][next_y] = '*';
							temp.push(make_pair(next_x, next_y));
							visit[next_x][next_y] = true;
						}
					}
				}
			}

			int size = v.size();
			vector<pair<int, int>> vtemp;
			for (int i = 0; i < size; i++)
			{
				int x = v[i].first;
				int y = v[i].second;

				for (int k = 0; k < 4; k++)
				{
					int next_x = x + direction_x[k];
					int next_y = y + direction_y[k];

					if (next_x >= 0 && next_y >= 0 && next_x < R && next_y < C && !visit2[next_x][next_y] && arr[next_x][next_y] != '*')
					{
						if (isEscape(make_pair(next_x, next_y)))
						{
							flag = true;
							i = size;
							break;
						}
						else if (arr[next_x][next_y] == '.')
						{
							vtemp.push_back(make_pair(next_x, next_y));
							visit2[next_x][next_y] = true;
						}
					}
				}
			}
			v.clear();
			for (int i = 0; i < vtemp.size(); i++)
				v.push_back(vtemp[i]);

			if (flag)
				break;
			if (v.empty())
				break;
			water = temp;

			//print();

			count++;
		}

		if (flag)
			cout << count + 1 << "\n";
		else
			cout << "IMPOSSIBLE\n";
	}

	return 0;
}