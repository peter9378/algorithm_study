/**
*	SW Expert Academy
*	No. 2819	격자판의 숫자 이어 붙이기
*	@author	peter9378
*	@date		2019.04.14
*/
#include <iostream>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };
int arr[5][5];
set<int> s;

void init()
{
	s.clear();
}

// bfs
void bfs(int x, int y, int count, int make)
{
	if (count == 7)
	{
		s.insert(make);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + direction_x[i];
		int next_y = y + direction_y[i];

		if (next_x < 0 || next_x >= 4 || next_y < 0 || next_y >= 4)
			continue;

		bfs(next_x, next_y, count + 1, (make*10) + arr[next_x][next_y]);
	}
	return;
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

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				cin >> arr[i][j];
		}

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				bfs(i, j, 1,arr[i][j]);
			}
		}

		// print answer
		cout << "#" << test_case << " " << s.size() << "\n";
	}


	return 0;
}