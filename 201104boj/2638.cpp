/**
*	BOJ
*	No.2638	ДЎБо
*	@author	peter9378
*	@date		2020.11.04
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
#include <unordered_map>
#include <cstring>
#include <iterator>
#include <numeric>
#include <complex>
using namespace std;

int N, M;
int arr[101][101];
int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };

int check()
{
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 1 || arr[i][j] == 2)
			{
				arr[i][j] = 1;
				result++;
			}
			else
				arr[i][j] = 0;
		}
	}
	return result;
}

void dfs(int x, int y)
{
	arr[x][y] = -1;
	for (int i = 0; i < 4; i++)
	{
		int next_x = x + direction_x[i];
		int next_y = y + direction_y[i];
		if (0 <= next_x && next_x < N && 0 <= next_y && next_y < M)
		{
			if (arr[next_x][next_y] > 0)
				arr[next_x][next_y]++;
			else if (arr[next_x][next_y] == 0)
				dfs(next_x, next_y);
		}
	}
}

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}

	int answer = 0;
	while (check())
	{
		dfs(0, 0);
		answer++;
	}

	cout << answer;

	return 0;
}