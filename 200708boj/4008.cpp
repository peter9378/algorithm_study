/**
*	BOJ
*	No.4008	Æ¯°ø´ë
*	@author	peter9378
*	@date		2020.07.08	Happy Birthday :)
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

long long idx = 0;
long long arr[1010101];
long long temp[1010101];
long long dp[1010101];
pair<long long, long long> bkt[1010101];

double dist(long long a, long long b)
{
	return 1.0*(double)(bkt[a].second - bkt[b].second) / (bkt[b].first - bkt[a].first);
}

void insert(pair<long long, long long> p)
{
	bkt[idx] = p;
	while (1 < idx && dist(idx - 2, idx - 1) > dist(idx - 1, idx))
	{
		bkt[idx - 1] = bkt[idx];
		idx--;
	}
	idx++;
}

long long binary(long long target)
{
	long long left = 0, right = idx - 1;
	while (left < right)
	{
		long long mid = (left + right) / 2;
		if (dist(mid, mid + 1) <= target)
			left = mid + 1;
		else
			right = mid;
	}
	return bkt[left].first * target + bkt[left].second;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long N;
	cin >> N;

	long long a, b, c;
	cin >> a >> b >> c;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		temp[i] = temp[i - 1] + arr[i];
	}

	pair<long long, long long> p;
	p.first = b;
	p.second = 0;
	insert(p);
	for (int i = 1; i <= N; i++)
	{
		dp[i] = c + binary(temp[i]) + a * temp[i] * temp[i];
		p.first = a * temp[i] * -2 + b;
		p.second = dp[i] - b * temp[i] + a * temp[i] * temp[i];
		insert(p);
	}

	cout << dp[N];

	return 0;
}