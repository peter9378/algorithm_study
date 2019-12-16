/**
*	BOJ
*	No.3109	»§Áý
*	@author	peter9378
*	@date		2019.12.16
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>
#include <cstring>
using namespace std;

int R, C;
string arr[10001];
bool visit[10001][505];
int direction_x[] = { -1, 0, 1 };

int dfs(int x, int y)
{
	visit[x][y] = true;
	if (y == C - 1)
		return 1;

	for (int i = 0; i < 3; i++)
	{
		int next_x = x + direction_x[i];
		int next_y = y + 1;

		if (next_x >= 0 && next_x < R && next_y >= 0 && next_y < C && !visit[next_x][next_y] && arr[next_x][next_y] == '.')
		{
			int temp = dfs(next_x, next_y);
			if (temp)
				return temp;
		}
	}
	return 0;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;

	for (int i = 0; i < R; i++)
		cin >> arr[i];

	int answer = 0;
	for (int i = 0; i < R; i++)
		answer += dfs(i, 0);

	cout << answer;

	return 0;
}
