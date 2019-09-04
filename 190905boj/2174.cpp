/**
*	BOJ
*	No.2174	로봇 시뮬레이션
*	@author	peter9378
*	@date		2019.09.05
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int arr[101][101];
int A, B;

struct robot {
	int x, y, index;
	int direction;
};

int direction_x[] = { 0, -1, 0, 1 };
int direction_y[] = { 1, 0, -1, 0 };

void print()
{
	cout << endl;
	for (int i = 1; i <= B; i++)
	{
		for (int j = 1; j <= A; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	cin >> A >> B;

	int N, M;
	cin >> N >> M;

	vector<robot> v;
	for (int i = 1; i <= N; i++)
	{
		int x, y;
		char d;
		cin >> x >> y >> d;

		switch (d)
		{
		case 'E':
			d = 0;
			break;
		case 'S':
			d = 1;
			break;
		case 'W':
			d = 2;
			break;
		case 'N':
			d = 3;
			break;
		}

		arr[y][x] = i;
		v.push_back(robot{ y, x, i, d });
	}

	for (int i = 0; i < M; i++)
	{
		int target, repeat;
		char cmd;
		cin >> target >> cmd >> repeat;

		robot r = v[target - 1];
		//print();
		switch (cmd)
		{
		case 'R':
			v[target - 1].direction = (r.direction + repeat % 4) % 4;
			//print();
			break;
		case 'L':
			v[target - 1].direction = ((r.direction - repeat % 4) + 4) % 4;
			//print();
			break;
		case 'F':
			while (repeat--)
			{
				if (r.x + direction_x[r.direction] > 0 && r.x + direction_x[r.direction] <= B && r.y + direction_y[r.direction] > 0 && r.y + direction_y[r.direction] <= A)
				{
					if (arr[r.x + direction_x[r.direction]][r.y + direction_y[r.direction]])
					{
						cout << "Robot " << r.index << " crashes into robot " << arr[r.x + direction_x[r.direction]][r.y + direction_y[r.direction]];
						return 0;
					}
					arr[r.x + direction_x[r.direction]][r.y + direction_y[r.direction]] = r.index;
					arr[r.x][r.y] = 0;
					r.x += direction_x[r.direction];
					r.y += direction_y[r.direction];
				}
				else
				{
					cout << "Robot " << r.index << " crashes into the wall";
					return 0;
				}
				//print();
			}
			v[target - 1] = r;
			break;
		}
	}
	cout << "OK";

	return 0;
}