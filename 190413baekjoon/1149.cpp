/**
*	SW Expert Academy
*	No. 1149	RGB 거리
*	@author	peter9378
*	@date		2019.04.13
*/
#include <iostream>
#include <algorithm>
using namespace std;

int house[1001][4];
int dp[1001][4];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> house[i][0] >> house[i][1] >> house[i][2];

	dp[0][0] = house[0][0];
	dp[0][1] = house[0][1];
	dp[0][2] = house[0][2];

	for (int i = 1; i < N; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + house[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + house[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + house[i][2];
	}

	cout << min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2]));

	return 0;
}