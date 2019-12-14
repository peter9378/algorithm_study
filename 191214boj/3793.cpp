/**
*	BOJ
*	No.3793	Common Subsequence
*	@author	peter9378
*	@date		2019.12.14
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

string a, b;
int arr[202][202];

void init()
{
	for (int i = 0; i < 202; i++)
	{
		for (int j = 0; j < 202; j++)
			arr[i][j] = -1;
	}
}

int dfs(int x, int y)
{
	if (a.length() == x || b.length() == y)
		return 0;

	int& result = arr[x][y];
	if (result != -1)
		return result;
	result = 0;
	if (a[x] == b[y])
		result = max(result, dfs(x + 1, y + 1) + 1);
	else
		result = max(result, max(dfs(x + 1, y), dfs(x, y + 1)));
	return result;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> a >> b)
	{
		init();
		cout << dfs(0, 0) << "\n";
	}

	return 0;
}
