/**
*	Code Forces
*	#574 C.	Basketball Exercise
*	@author	peter9378
*	@date		2019.07.18
*/
#include <iostream>
#include <algorithm>
using namespace std;

long long arr[2][100001];
long long dp[3][100001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[0][i];

	for (int i = 0; i < n; i++)
		cin >> arr[1][i];

	dp[0][0] = arr[0][0];
	dp[1][0] = arr[1][0];
	dp[2][0] = 0;

	for (int i = 1; i < n; i++)
	{
		dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]) + arr[0][i];
		dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + arr[1][i];
		dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]);
	}

	cout << max(max(dp[0][n - 1], dp[1][n - 1]), dp[2][n - 1]);

	return 0;
}