/**
*	BOJ
*	No.1648	격자판 채우기
*	@author	peter9378
*	@date		2021.07.14
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

#define MOD 9901
#define MAX 15

int n, m;
int dp[MAX * MAX][(1 << MAX) - 1];

int go(int target, int status)
{
	if (target >= n * m)
	{
		if (target == n * m && status == 0)
			return 1;
		return 0;
	}

	int& result = dp[target][status];
	if (result != -1)
		return result;
	result = 0;

	if (status & (1 << 0))
		result += go(target + 1, status >> 1);
	else
	{
		if (target % m < (m - 1) && (status & (1 << 1)) == 0)
			result += go(target + 2, status >> 2);
		result += go(target + 1, (status >> 1) | (1 << (m - 1)));
	}
	result %= MOD;
	return result;
}


// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	cout << go(0, 0);

	return 0;
}
