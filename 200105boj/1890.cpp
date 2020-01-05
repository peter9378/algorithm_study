/**
*	BOJ
*	No.1890	มกวม
*	@author	peter9378
*	@date		2020.01.05
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

int arr[101][101];
long long dp[101][101];

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

	dp[0][0] = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j])
			{
				if (i + arr[i][j] < N)
					dp[i + arr[i][j]][j] += dp[i][j];
				if (j + arr[i][j] < N)
					dp[i][j + arr[i][j]] += dp[i][j];
			}
		}
	}

	cout << dp[N - 1][N - 1];

	return 0;
}
