/**
*	BOJ
*	No.11001	±èÄ¡
*	@author	peter9378
*	@date		2021.07.22
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

int D;
vector<long long> T, V, dp;

long long get(long long a, long long b)
{
	return V[a] + (b - a) * T[b];
}

void go(int start, int end, int left, int right)
{
	if (start > end)
		return;

	int mid = (start + end) >> 1;
	int target = mid;
	dp[mid] = V[mid];

	pair<long long, int> result = { V[mid], mid };
	for (int i = left; i <= min(right, mid + D); ++i)
	{
		long long temp = V[mid] + (i - mid) * T[i];

		if (dp[mid] < temp)
		{
			dp[mid] = temp;
			target = i;
		}
	}

	go(start, mid - 1, left, target);
	go(mid + 1, end, target, right);
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N >> D;

	T.resize(N + 1);
	V.resize(N + 1);
	dp.resize(N + 1);

	for (int i = 1; i <= N; i++)
		cin >> T[i];
	for (int i = 1; i <= N; i++)
		cin >> V[i];

	go(1, N, 1, N);


	long long answer = 0;
	for (int i = 1; i <= N; i++)
		answer = max(answer, dp[i]);
	cout << answer;

	return 0;
}
