/**
*	BOJ
*	No.2449	Àü±¸
*	@author	peter9378
*	@date		2020.04.03
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

int arr[202];
int dp[202][202];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		for (int j = i; j--;)
		{
			dp[j][i] = 987654321;
			for (int k = j; k < i; k++)
				dp[j][i] = min(dp[j][i], dp[j][k] + dp[k + 1][i] + (arr[j] != arr[k + 1]));
		}
	}

	cout << dp[0][N - 1];

	return 0;
}