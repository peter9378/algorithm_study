/**
*	BOJ
*	No.2660	»∏¿Â ªÃ±‚
*	@author	peter9378
*	@date		2020.04.16
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
#include <iterator>
#include <numeric>
using namespace std;

int arr[55][55];
int dp[55];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 55; i++)
	{
		for (int j = 0; j < 55; j++)
			arr[i][j] = 63;
	}

	int N;
	cin >> N;

	int a, b;
	while (true)
	{
		cin >> a >> b;
		if (a == -1 && b == -1)
			break;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= N; k++)
				arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
		}
	}

	int result = 999999999;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j)
				continue;
			dp[i] = max(dp[i], arr[i][j]);
		}
		result = min(result, dp[i]);
	}

	int check = 0;
	for (int i = 1; i <= N; i++)
	{
		if (result == dp[i])
			check++;
	}

	cout << result << " " << check << "\n";
	for (int i = 1; i <= N; i++)
	{
		if (result == dp[i])
			cout << i << " ";
	}

	return 0;
}