/**
*	BOJ
*	No.3055	탈출
*	@author	peter9378
*	@date		2019.09.03
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int R, C;
string arr[55];
bool visit[55][55];
bool visit2[55][55];
vector<pair<int, int>> v;
queue<pair<int, int>> water;
pair<int, int> cave;

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
			switch (arr[i][j])
			{
			case '*':
				water.push(make_pair(i, j));
				visit[i][j] = true;
				break;
			case 'S':
				v.push_back(make_pair(i, j));
				arr[i][j] = '.';
				visit2[i][j] = true;
				break;
			case 'D':
				cave = make_pair(i, j);
				break;
			}
		}
	}

	int count = 1;
	bool flag = false;
	while (true)
	{
		int size = v.size();

		// goseum move
		vector<pair<int, int>> vtemp;
		for (int i = 0; i < size; i++)
		{
			int x = v[i].first;
			int y = v[i].second;

			if (arr[x][y] == '.')
			{
				for (int k = 0; k < 4; k++)
				{
					int next_x = x + direction_x[k];
					int next_y = y + direction_y[k];

					if (next_x >= 0 && next_y >= 0 && next_x < R && next_y < C && !visit2[next_x][next_y])
					{
						if (arr[next_x][next_y] == '.')
						{
							vtemp.push_back(make_pair(next_x, next_y));
							visit2[next_x][next_y] = true;
						}
						else if (arr[next_x][next_y] == 'D')
						{
							flag = true;
							i = size;
							break;
						}
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
		water = temp;
		//print();

		count++;
	}

	if (flag)
		cout << count;
	else
		cout << "KAKTUS";

	return 0;
}