/**
*	baekjoon online judge
*	No. 14500	테트로미노
*	@author	peter9378
*	@date		2019.03.07
*/
#include <iostream>
#include <algorithm>
using namespace std;

int arr[505][505];
int N, M, answer;

// all tetromino cases
int direction_x[19][4] = { { 0, 0, 0, 0 },{ 0, 1, 2, 3 },{ 0, 0, 1, 1 },{ 0, 1, 2, 2 },{ 0, 1, 2, 2 },
{ 0, 0, 0, 1 },{ 0, 0, 0, 1 },{ 0, 0, 1, 2 },{ 0, 0, 1, 2 },{ 0, 1, 1, 1 },
{ 0, 1, 1, 1 },{ 0, 1, 1, 2 },{ 0, 1, 1, 2 },{ 0, 0, 1, 1 },{ 0, 0, 1, 1 },
{ 0, 0, 0, 1 },{ 0, 1, 1, 2 },{ 0, 1, 1, 1 },{ 0, 1, 1, 2 } };
int direction_y[19][4] = { { 0, 1, 2, 3 },{ 0, 0, 0, 0 },{ 0, 1, 0, 1 },{ 0, 0, 0, 1 },{ 1, 1, 0, 1 },
{ 0, 1, 2, 0 },{ 0, 1, 2, 2 },{ 0, 1, 1, 1 },{ 0, 1, 0, 0 },{ 2, 0, 1, 2 },
{ 0, 0, 1, 2 },{ 0, 0, 1, 1 },{ 1, 0, 1, 0 },{ 1, 2, 0, 1 },{ 0, 1, 1, 2 },
{ 0, 1, 2, 1 },{ 1, 0, 1, 1 },{ 1, 0, 1, 2 },{ 0, 0, 1, 0 } };

// check that it is still in the board
bool check(int x, int y)
{
	return x >= 0 && y >= 0 && x < N && y < M;
}

// check all directions
void tetromino(int x, int y)
{
	for (int i = 0; i < 19; i++)
	{
		bool flag = false;
		for (int j = 0; j < 4; j++)
		{
			int next_x = x + direction_x[i][j];
			int next_y = y + direction_y[i][j];
			if (!check(next_x, next_y))
			{
				flag |= true;
				break;
			}
		}

		// select more bigger one
		if (!flag)
		{
			int temp = 0;
			for (int j = 0; j < 4; j++)
			{
				int next_x = x + direction_x[i][j];
				int next_y = y + direction_y[i][j];
				temp += arr[next_x][next_y];
			}
			answer = max(temp, answer);
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
			cin >> arr[i][j];
	}

	// check all cases(brute-force)
	answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			tetromino(i, j);
	}

	// print answer
	cout << answer;
	return 0;
}
