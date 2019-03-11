/**
*	baekjoon online judge
*	No. 14503	로봇 청소기
*	@author	peter9378
*	@date		2019.03.11
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[55][55];

int direction_x(int d)
{
	int direction[] = { -1, 0, 1, 0 };
	if (d < 0)
		return direction_x(d+4);
	else if (d > 3)
		return direction_x(d-4);
	else
		return direction[d];
}
int direction_y(int d)
{
	int direction[] = { 0, 1, 0, -1 };
	if (d < 0)
		return direction_y(d + 4);
	else if (d > 3)
		return direction_y(d - 4);
	else
		return direction[d];
}


// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int N, M;
	cin >> N >> M;

	int r, c, d;
	cin >> r >> c >> d;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}

	int answer = 0;
	bool flag = true;
	while (true)
	{
		// 1. clean current location
		if (arr[r][c] == 0 && flag)
		{
			answer++;
			arr[r][c] = -1;
		}

		// 2.3 all direction is clean or wall, maintain direction and backward and go to 2.
		if (arr[r+direction_x(d)][c+direction_y(d)] && arr[r + direction_x(d+1)][c + direction_y(d+1)] && arr[r + direction_x(d+2)][c + direction_y(d+2)] && arr[r + direction_x(d+3)][c + direction_y(d+3)])
		{
			// 2.4 and backside is wall, stop
			if (arr[r + direction_x(d + 2)][c + direction_y(d + 2)] == 1)
				break;

			r += direction_x(d + 2);
			c += direction_y(d + 2);
			flag = false;
			continue;
		}

		// 2.1 if left side is dirty, rotate and forward and go back to 1.
		if (arr[r+direction_x(d - 1)][c+direction_y(d-1)] == 0)
		{
			d--;
			r += direction_x(d);
			c += direction_y(d);
			flag = true;
		}
		// 2.2 there is no space to clean on left side, rotate and go to 2.
		else
		{
			d--;
			flag = false;
		}
	}

	// print answer
	cout << answer;
	return 0;
}
