/**
*	BOJ
*	No.13263	나무 자르기
*	@author	peter9378
*	@date		2021.07.09
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

struct Log {
	long long height, cost;
};

Log stk[1010101];
long long temp = 0;
long long arr[1010101];
long long arrr[1010101];
long long dp[1010101];

double get(long long a, long long b)
{
	return 1.0 * (double)(stk[a].cost - stk[b].cost) / (stk[b].height - stk[a].height);
}

void cut(Log v)
{
	stk[temp] = v;
	while (1 < temp&&get(temp - 2, temp - 1) > get(temp - 1, temp))
	{
		stk[temp - 1] = stk[temp];
		temp--;
	}

	temp++;
}

long long go(long long x)
{
	long long lo = 0, hi = temp - 1;
	while (lo < hi) {
		long long mid = (lo + hi) / 2;
		if (get(mid, mid + 1) <= x) lo = mid + 1;
		else hi = mid;
	}
	return stk[lo].height*x + stk[lo].cost;
}

void init()
{
	temp = 0;
}


// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, m;
	cin >> n;
	for (long long i = 1; i <= n; i++)
		cin >> arr[i];
	for (long long i = 1; i <= n; i++)
		cin >> arrr[i];

	Log log;
	log.height = arrr[1];
	log.cost = 0;
	cut(log);

	for (long long i = 2; i <= n; i++)
	{
		dp[i] = go(arr[i]);

		log.height = arrr[i];
		log.cost = dp[i];
		cut(log);
	}
	cout << dp[n];

	return 0;
}
