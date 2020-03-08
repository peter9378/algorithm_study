/**
*	BOJ
*	No.13305	¡÷¿Øº“
*	@author	peter9378
*	@date		2020.03.08
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

long long arr[100001];
long long cost[100001];
long long dp[100001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N - 1; i++)
		cin >> arr[i];

	for (int i = 0; i < N - 1; i++)
		cin >> cost[i];

	dp[0] = arr[0] * cost[0];
	long long mini = cost[0];
	for (int i = 1; i < N; i++)
	{
		mini = min(mini, cost[i]);
		dp[i] = dp[i - 1] + mini * arr[i];
	}

	cout << dp[N - 1];

	return 0;
}
