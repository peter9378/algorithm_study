/**
*	BOJ
*	No.17404	RGB°Å¸® 2
*	@author	peter9378
*	@date		2020.11.06
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

int arr[1001][3];
int dp[1001][3];

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];
	}

	int answer = 987654321;
	for (int a = 0; a < 3; a++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (a == i)
				dp[1][i] = arr[1][i];
			else
				dp[1][i] = 987654321;
		}

		for (int i = 2; i <= N; i++)
		{
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
		}

		for (int i = 0; i < 3; i++)
		{
			if (i == a)
				continue;
			answer = min(answer, dp[N][i]);
		}
	}

	cout << answer;

	return 0;
}