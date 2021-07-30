/**
*	BOJ
*	No.1947	선물 전달
*	@author	peter9378
*	@date		2021.07.30
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

#define MOD 1000000000

long long dp[1000001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	dp[2] = 1;
	dp[3] = 2;

	for (int i = 4; i <= N; i++)
		dp[i] = ((dp[i - 1] + dp[i - 2]) * (i - 1)) % MOD;

	cout << dp[N];

	return 0;
}
