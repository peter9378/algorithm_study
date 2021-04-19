/**
*	BOJ
*	No.1563	°³±Ù»ó
*	@author	peter9378
*	@date		2021.04.19
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

#define MOD 1000000

int N;
int dp[1001][3][4];

int go(int target, int a, int b)
{
	if (a > 1 || b > 2)
		return 0;
	if (target == N)
		return 1;

	int& result = dp[target][a][b];
	if (result != -1)
		return result;
	return result = (go(target + 1, a, 0) + go(target + 1, a + 1, 0) + go(target + 1, a, b + 1)) % MOD;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	memset(dp, -1, sizeof(dp));
	cout << go(0, 0, 0);

	return 0;
}
