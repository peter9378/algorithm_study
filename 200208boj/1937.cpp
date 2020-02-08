/**
*	BOJ
*	No.1937	øÂΩ…¿Ô¿Ã ∆«¥Ÿ
*	@author	peter9378
*	@date		2020.02.08
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

int n;
int arr[555][555];
int dp[555][555];
int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };

int dfs(int x, int y)
{

	if (dp[x][y])
		return dp[x][y];

	dp[x][y] = 1;

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + direction_x[i];
		int next_y = y + direction_y[i];

		if (next_x >= 0 && next_y >= 0 && next_x < n && next_y < n && arr[x][y] < arr[next_x][next_y])
			dp[x][y] = max(dp[x][y], dfs(next_x, next_y) + 1);
	}

	return dp[x][y];
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			answer = max(answer, dfs(i, j));
	}

	cout << answer;

	return 0;
}
