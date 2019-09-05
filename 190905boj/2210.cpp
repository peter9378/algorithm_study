/**
*	BOJ
*	No.2210	숫자판 점프
*	@author	peter9378
*	@date		2019.09.05
*/
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int arr[5][5];

int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };
set<string> s;

void dfs(int x, int y, int count, string str)
{
	if (count == 5)
	{
		s.insert(str);
		return;
	}

	for (int k = 0; k < 4; k++)
	{
		int next_x = x + direction_x[k];
		int next_y = y + direction_y[k];

		if (next_x >= 0 && next_y >= 0 && next_x < 5 && next_y < 5)
			dfs(next_x, next_y, count + 1, str + (char)(arr[next_x][next_y] + 48));
	}
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			dfs(i, j, 0, to_string(arr[i][j] + 48));
		}
	}

	cout << s.size();

	return 0;
}