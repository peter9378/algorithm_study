/**
*	SW Expert Academy
*	No. 5656	벽돌 깨기
*	@author	peter9378
*	@date		2019.04.12
*/
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int arr[21][15];
int N, W, H;
int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };
int answer = 123456789;

// init array
void init()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 15; j++)
			arr[i][j] = 0;
	}
	answer = 987654321;
}

// bricks fall down because of gravity
void down()
{
	for (int i = 0; i < W; i++)
	{
		queue<int> q;
		for (int j = H - 1; j >= 0; j--)
		{
			if (arr[j][i] != 0)
				q.push(arr[j][i]);
		}

		int count = 0;
		while (!q.empty())
		{
		arr[H - 1 - count][i] = q.front();
		q.pop();
		count++;
		}

		for (int j = 0; j < H - count; j++)
		arr[j][i] = 0;
	}
}

//
void boom(int index)
{
	queue<pair<int, pair<int, int>>> q;

	for (int i = 0; i < H; i++)
	{
		if (arr[i][index])
		{
			q.push(make_pair(i, make_pair(index, arr[i][index] - 1)));
			arr[i][index] = 0;
			break;
		}
	}


	// boom all bomb
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second.first;
		int power = q.front().second.second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = x;
			int next_y = y;

			for (int j = 0; j < power; j++)
			{
				next_x += direction_x[i];
				next_y += direction_y[i];

				if (next_x < 0 || next_x >= H || next_y < 0 || next_y >= W)
					continue;

				if (arr[next_x][next_y] != 0)
					q.push(make_pair(next_x, make_pair(next_y, arr[next_x][next_y] - 1)));
				arr[next_x][next_y] = 0;
			}
		}
	}

	down();
}

int check()
{
	int count = 0;


	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (arr[i][j])
				count++;
		}
	}

	return count;
}

void dfs(int count)
{
	if (count == N)
	{
		answer = min(answer, check());
		return;
	}

	int temp_arr[20][15];

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
			temp_arr[i][j] = arr[i][j];
	}

	for (int i = 0; i < W; i++)
	{
		boom(i);
		dfs(count + 1);
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
				arr[i][j] = temp_arr[i][j];
		}
	}
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		init();

		// input data
		cin >> N >> W >> H;

		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
				cin >> arr[i][j];
		}

		dfs(0);

		// print answer
		cout << "#" << test_case << " " << answer << "\n";
	}


	return 0;
}