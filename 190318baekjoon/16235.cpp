/**
*	baekjoon online judge
*	No. 16235		나무 재테크
*	@author	peter9378
*	@date		2019.03.18
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, K, answer = 0;
int arr[11][11];
int arr_temp[11][11];
int direction_x[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int direction_y[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
queue<pair<int, int>> q;
vector<int> v[11][11];

// check border
bool check(int x, int y)
{
	return x >= 0 && y >= 0 && x < N && y < N;
}

// check spring, summer, 8 directions
void springandsummer()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int size = v[i][j].size();

			if (size > 0)
			{
				for (int k = 0; k < size; k++)
				{
					if (arr[i][j] >= v[i][j][k])
					{
						arr[i][j] -= v[i][j][k];
						v[i][j][k]++;
						
						// check if tree is divided by 5 here
						if (!(v[i][j][k] % 5))
							q.push(make_pair(i, j));
					}
					else
					{
						int temp = size - k;

						while (temp--)
						{
							// summer
							arr[i][j] += (v[i][j][--size] / 2);
							v[i][j].pop_back();
						}
						break;
					}
				}
			}
		}
	}
}

// check automn, bfs, 8 direction
void automn()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 8; i++)
		{
			int next_x = x + direction_x[i];
			int next_y = y + direction_y[i];

			if (!check(next_x, next_y))
				continue;

			v[next_x][next_y].push_back(1);
		}
	}
}

void winter()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			arr[i][j] += arr_temp[i][j];
	}
}


// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr_temp[i][j];
			arr[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		x--;
		y--;

		v[x][y].push_back(z);
	}

	// K years
	while (K)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (v[i][j].size() > 1)
					sort(v[i][j].begin(), v[i][j].end());
			}
		}
		// sprint - summer
		springandsummer();

		// -automn
		automn();

		// -winter
		winter();
		
		// 1 year passed
		K--;
	}

	// count all remain trees
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			answer += v[i][j].size();
	}

	// print answer
	cout << answer;

	return 0;
}