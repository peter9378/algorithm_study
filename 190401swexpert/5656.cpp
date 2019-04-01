/**
*	SW Expert Academy
*	No. 5656	벽돌 깨기
*	@author	peter9378
*	@date		2019.04.01
*/
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int arr[20][20];
int N, W, H;
int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };
queue<pair<int, int>> bombq;

// init array
void init()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
			arr[i][j] = 0;
	}
}

// bricks fall down because of gravity
void down()
{
	for (int i = 0; i < W; i++)
	{
		queue<int> q;
		for (int j = H - 1; j > 0; j--)
		{
			if (arr[j][i])
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
void bomb_drop(int w)
{
	for (int i = 0; i < H; i++)
	{
		if (arr[i][w])
		{
			explode(i, w, arr[i][w]);
		}
	}
}

void explode(int x, int y, int power)
{
	bombq.push(make_pair(x, y));

	// check 4 direction
	for (int i = 0; i < 4; i++)
	{
		int next_x = x + direction_x[i];
		int next_y = y + direction_y[i];
		int count = power - 1;
		
		// border check
		while (next_x >= 0 && next_x < H && next_y >= 0 && next_y < H && count)
		{
			if (arr[next_x][next_y])
				explode(next_x, next_y, arr[next_x][next_y]);
			else
				break;

			count--;
			next_x += direction_x[i];
			next_y += direction_y[i];
		}
	}
}

//
void boom()
{
	// boom all bomb
	while (!bombq.empty())
	{
		arr[bombq.front().first][bombq.front().second] = 0;
		bombq.pop();
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


}

void dfs(int d)
{
	if (d == N)
	{
		explode();
		return;
	}

	for (int i = 0; i < W; i++)
	{
		dfs(d + 1);
	}
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int test_case = 1; test_case < T; test_case++)
	{
		// input data
		cin >> N >> W >> H;

		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
				cin >> arr[i][j];
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < W; j++)
				bomb_drop(i);
		}

		// print answer
		cout << "#" << test_case << " " << answer << "\n";
	}

	
	return 0;
}