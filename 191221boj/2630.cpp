/**
*	BOJ
*	No.2630	색종이 만들기
*	@author	peter9378
*	@date		2019.12.21
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

int white = 0, blue = 0;
bool arr[131][131];

void dfs(int x, int y, int xend, int yend)
{
	int check = arr[x][y];

	for (int i = x; i < xend; i++)
	{
		for (int j = y; j < yend; j++)
		{
			if (!check && arr[i][j])
				check = 2;
			else if (check && !arr[i][j])
				check = 2;

			if (check == 2)
			{
				dfs(x, y, (x + xend) / 2, (y + yend) / 2);
				dfs((x + xend) / 2, (y + yend) / 2, xend, yend);
				dfs(x, (y + yend) / 2, (x + xend) / 2, yend);
				dfs((x + xend) / 2, y, xend, (y + yend) / 2);
				return;
			}
		}
	}

	if (!check)
		white++;
	else if (check == 1)
		blue++;
	return;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}

	dfs(0, 0, N, N);

	cout << white << "\n" << blue;

	return 0;
}
