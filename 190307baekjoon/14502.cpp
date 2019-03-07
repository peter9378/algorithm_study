/**
*	baekjoon online judge
*	No. 14502	연구소
*	@author	peter9378
*	@date		2019.03.07
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int direction_x[] = { -1, 0, 1, 0 };
int direction_y[] = { 0, 1, 0, -1 };

int N, M;
int arr[8][8];
int temp_arr[8][8];
vector<pair<int, int>> v;

// dfs for 4 direction virus
void dfs(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int next_x = x + direction_x[i];
		int next_y = y + direction_y[i];
		if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < M)
		{
			if (temp_arr[next_x][next_y] == 0)
			{
				temp_arr[next_x][next_y] = 2;
				dfs(next_x, next_y);
			}
		}
	}
}


// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			temp_arr[i][j] = arr[i][j];

			// only safe area to set the stick
			if (!arr[i][j])
				v.push_back(make_pair(i, j));
		}
	}

	int answer = 0, size = v.size();
	for (int i = 0; i < size - 2; i++)
	{
		for (int j = i + 1; j < size - 1; j++)
		{
			for (int k = j + 1; k < size; k++)
			{
				// set 3 location for 3 stick
				pair<int, int> sticka = v[i];
				pair<int, int> stickb = v[j];
				pair<int, int> stickc = v[k];

				// copy
				for (int i = 0; i < N; i++)
				{
					for (int j = 0; j < M; j++)
						temp_arr[i][j] = arr[i][j];
				}

				// set the stick
				temp_arr[sticka.first][sticka.second] = 1;
				temp_arr[stickb.first][stickb.second] = 1;
				temp_arr[stickc.first][stickc.second] = 1;

				// virus after set the stick
				for (int x = 0; x < N; x++)
				{
					for (int y = 0; y < M; y++)
					{
						if (temp_arr[x][y] == 2)
							dfs(x, y);
					}
				}

				// check the safe area
				int count = 0;
				for (int x = 0; x < N; x++)
				{
					for (int y = 0; y < M; y++)
					{
						if (temp_arr[x][y] == 0)
							count++;
					}
				}

				// bigger value is the answer
				answer = max(answer, count);
			}
		}
	}

	// print answer
	cout << answer;
	return 0;
}
