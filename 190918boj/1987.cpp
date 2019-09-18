/**
*	BOJ
*	No.1987	알파벳
*	@author	peter9378
*	@date		2019.09.18
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int R, C;
int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };
string arr[22];
int answer = 1;
int cnt = 1;
bool check[26];

void dfs(int x, int y)
{
	check[arr[x][y] - 65] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + direction_x[i];
		int ny = y + direction_y[i];
		if (nx >= 0 && ny >= 0 && nx < R && ny < C)
		{
			if (!check[arr[nx][ny] - 65])
			{
				cnt++;
				if (answer < cnt)
					answer = cnt;
				dfs(nx, ny);
			}
		}
	}
	check[arr[x][y] - 65] = false;
	cnt--;
	return;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
		cin >> arr[i];

	dfs(0, 0);
	cout << answer;

	return 0;
}