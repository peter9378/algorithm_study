/**
*	BOJ
*	No.13261	Å»¿Á
*	@author	peter9378
*	@date		2021.07.21
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

long long arr[8005];
long long bucket[8005];
long long dp[805][8005];

long long get(long long a, long long b)
{
	return (a - b) * (bucket[a] - bucket[b]);
}

void go(int target, int start, int end, int left, int right) {
	if (start > end)
		return;

	int mid = (start + end) >> 1;
	int temp = -1;
	long long& result = dp[target][mid];

	for (int i = left; i < min(mid, right); i++)
	{
		long long val = dp[target - 1][i] + (mid - i) * (bucket[mid] - bucket[i]);
		if (temp == -1 || result > val)
		{
			temp = i;
			result = val;
		}
	}

	go(target, start, mid - 1, left, temp + 1);
	go(target, mid + 1, end, temp, right);
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int L, G;
	cin >> L >> G;

	if (G >= L)
		G = L;

	for (int i = 1; i <= L; ++i)
		cin >> arr[i];
	for (int i = 1; i <= L; ++i)
		bucket[i] = bucket[i - 1] + arr[i];
	for (int i = 1; i <= L; ++i)
		dp[1][i] = bucket[i] * i;
	for (int i = 2; i <= G; ++i)
		go(i, 1, L, 0, L);
	cout << dp[G][L];

	return 0;
}
