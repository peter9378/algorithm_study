/**
*	baekjoon online judge
*	No. 15685	드래곤 커브
*	@author	peter9378
*	@date		2019.03.14
*/
#include <iostream>
#include <vector>
using namespace std;

int arr[101][101];
int direction_x[4] = { 1, 0, -1, 0 };
int direction_y[4] = { 0, -1, 0, 1 };

// turn functions
int turn_x(int hold_x, int hold_y, int move_y)
{
	return hold_x + hold_y - move_y;
}

int turn_y(int hold_x, int hold_y, int move_x)
{
	return hold_y - hold_x + move_x;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int N;
	cin >> N;

	// bfs
	for (int n = 0; n < N; n++)
	{
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		vector<pair<int, int>> v;

		v.push_back({ x,y });
		v.push_back({ x + direction_x[d], y + direction_y[d] });

		while (g--)
		{
			pair<int, int> hold = v.at(v.size() - 1);

			for (int i = v.size() - 1; i >= 0; i--)
				v.push_back({ turn_x(hold.first, hold.second, v.at(i).second), turn_y(hold.first, hold.second, v.at(i).first) });
		}

		for (int i = 0; i < v.size(); i++)
			arr[v.at(i).first][v.at(i).second] = 1;

	}

	int answer = 0;
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			int check = arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1];
			if (check == 4)
				answer++;
		}
	}

	// print answer
	cout << answer;

	return 0;
}