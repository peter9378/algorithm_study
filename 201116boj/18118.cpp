/**
*	BOJ
*	No.18118	7-세그먼트 디스플레이
*	@author	peter9378
*	@date		2020.11.16
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

int n, m;
long long arr[10][100002][10];
int dp[10][100002];

long long ppow(int current, int target)
{
	if (target == 0)
		return 1;
	return ppow(current, target - 1)*current;
}

int counting(int current, int target)
{
	if (current == n)
	{
		if (target == 0)
			return 0;
		return -100;
	}
	int &result = dp[current][target];
	if (result != -1)
		return result;

	result = counting(current + 1, (100 * target + 11) % m) + 1;
	for (int i = 0; i < 10; i++)
		result = max(result, counting(current + 1, (10 * target + i) % m));

	return result;
}

long long go(int current, int target, int add)
{
	if (current == n)
	{
		if (target == 0 && add == 0) return 0;
		return -987654321 + 100;
	}
	long long &result = arr[current][target][add];
	if (result != -1)
		return result;
	if (n - current <= add)
		return result = go(current + 1, (100 * target + 11) % m, add - 1) + 11 * ppow(10, n - current - 2 + add);

	result = -987654321 + 100;

	if (add)
		result = go(current + 1, (100 * target + 11) % m, add - 1) + 11 * ppow(10, n - current - 2 + add);
	for (int i = 9; i >= 0; i--)
		result = max(result, go(current + 1, (10 * target + i) % m, add) + i * ppow(10, n - current - 1 + add));

	return result;
}

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		memset(arr, -1, sizeof(arr));
		memset(dp, -1, sizeof(dp));
		cin >> n >> m;
		cout << go(0, 0, counting(0, 0));
		cout << "\n";
	}

	return 0;
}