/**
*	BOJ
*	No.2239	½ºµµÄí
*	@author	peter9378
*	@date		2020.12.02
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

string arr[10];
bool row[10][10];
bool col[10][10];
bool sudoku[10][10];

void dfs(int target)
{
	if (target == 81)
	{
		for (int i = 0; i < 9; i++)
			cout << arr[i] << "\n";
		exit(0);
	}

	int x = target / 9, y = target % 9;
	if (arr[x][y] == '0')
	{
		for (int i = 1; i <= 9; i++)
		{
			if (!row[x][i] && !col[y][i] && !sudoku[(x / 3) * 3 + y / 3][i])
			{
				row[x][i] = col[y][i] = sudoku[(x / 3) * 3 + y / 3][i] = true;
				arr[x][y] = i + '0';
				dfs(target + 1);
				row[x][i] = col[y][i] = sudoku[(x / 3) * 3 + y / 3][i] = false;
				arr[x][y] = '0';
			}
		}
	}
	else
		dfs(target + 1);
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] != '0')
				row[i][arr[i][j] - '0'] = col[j][arr[i][j] - '0'] = sudoku[(i / 3) * 3 + j / 3][arr[i][j] - '0'] = true;
		}
	}

	dfs(0);
	return 0;
}
