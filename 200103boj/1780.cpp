/**
*	BOJ
*	No.1780	종이의 개수
*	@author	peter9378
*	@date		2020.01.03
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

int N;
int arr[2222][2222];
int answer[3];

void dfs(int n, int x, int y)
{
	if (n == 1)
	{
		answer[arr[x][y] + 1]++;
		return;
	}

	bool a, b, c;
	a = b = c = true;
	for (int i = x; i < x + n; i++)
	{
		for (int j = y; j < y + n; j++)
		{
			if (arr[i][j] == -1)
			{
				b = false;
				c = false;
			}
			else if (arr[i][j] == 0)
			{
				a = false;
				c = false;
			}
			else
			{
				a = false;
				b = false;
			}
		}
	}

	if (a)
		answer[0]++;
	else if (b)
		answer[1]++;
	else if (c)
		answer[2]++;
	else
	{
		int temp = n / 3;
		dfs(temp, x, y);
		dfs(temp, x, y + temp);
		dfs(temp, x, y + 2 * temp);

		dfs(temp, x + temp, y);
		dfs(temp, x + temp, y + temp);
		dfs(temp, x + temp, y + 2 * temp);

		dfs(temp, x + 2 * temp, y);
		dfs(temp, x + 2 * temp, y + temp);
		dfs(temp, x + 2 * temp, y + 2 * temp);
	}
	return;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}

	dfs(N, 0, 0);

	for (int i = 0; i < 3; i++)
		cout << answer[i] << "\n";

	return 0;
}
