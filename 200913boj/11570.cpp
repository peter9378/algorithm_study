/**
*	BOJ
*	No.11570	»ØªÛ¿« µ‡øß
*	@author	peter9378
*	@date		2020.09.13
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
using namespace std;

int arr[2002];
int dp[2002][2002];

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
			dp[i][j] = 987654321;
	}

	dp[0][1] = dp[1][0] = 0;
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			if (i == j)
				continue;
			int current = max(i, j) + 1;
			if (!(i && j))
				arr[0] = arr[current];
			dp[current][j] = min(dp[current][j], dp[i][j] + abs(arr[current] - arr[i]));
			dp[i][current] = min(dp[i][current], dp[i][j] + abs(arr[current] - arr[j]));
		}
	}

	int answer = 987654321;
	for (int i = 0; i < N; i++)
		answer = min(answer, min(dp[i][N], dp[N][i]));
	cout << answer;

	return 0;
}