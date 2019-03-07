/**
*	baekjoon online judge
*	No. 14499	주사위 굴리기
*	@author	peter9378
*	@date		2019.03.04
*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map;
int dice[6];
const int arr[5][6] = { {1, 2, 3, 4, 5, 6}, {4, 2, 1, 6, 5, 3}, {3, 2, 6, 1, 5, 4}, {5, 1, 3, 4, 6, 2}, {2, 6, 3, 4, 1, 5} };
const int direction_x[] = { 0, 0, 0, -1, 1 };
const int direction_y[] = { 0, 1, -1, 0, 0 };

// update fuinction(swap)
void update(int direction)
{
	int temp[6];
	for (int i = 0; i < 6; i++)
		temp[i] = dice[i];
	for (int i = 0; i < 6; i++)
		dice[arr[direction][i] - 1] = temp[i];
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int N, M, x, y, K;
	cin >> N >> M >> x >> y >> K;

	map.assign(N + 2, vector<int>(M + 2, -1));

	// input data
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			cin >> map[i][j];
	}
	// to make index properly
	x++;
	y++;

	// copy values
	if (map[x][y] == 0)
		map[x][y] = dice[5];
	else
	{
		dice[5] = map[x][y];
		map[x][y] = 0;
	}

	int command, next_x, next_y;

	// move dice
	while (K--)
	{
		// get command
		cin >> command;
		
		// move
		next_x = x + direction_x[command];
		next_y = y + direction_y[command];

		// check
		if (map[next_x][next_y] == -1)
			continue;
		else
		{
			x = next_x;
			y = next_y;
		}

		// update
		update(command);

		// copy values
		if (map[x][y] == 0)
			map[x][y] = dice[5];
		else
		{
			dice[5] = map[x][y];
			map[x][y] = 0;
		}

		// print upside value of the dice
		cout << dice[0] << '\n';
	}
	return 0;
}
