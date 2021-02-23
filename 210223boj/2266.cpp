/**
*	BOJ
*	No.2266	금고 테스트
*	@author	peter9378
*	@date		2021.02.23
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

#define MAX 500

int N, M;
int dp[505][505];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		dp[i][1] = i;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 2; j <= M; j++)
		{
			dp[i][j] = 1000000000;
			for (int k = 1; k <= i; k++)
				dp[i][j] = min(dp[i][j], max(dp[k - 1][j - 1], dp[i - k][j]) + 1);
		}
	}

	cout << dp[N][M];

	return 0;
}
