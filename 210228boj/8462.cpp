/**
*	BOJ
*	No.8462	¹è¿­ÀÇ Èû
*	@author	peter9378
*	@date		2021.02.28
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

int n, t, sqt;
long long sum = 0;
long long arr[100001];
long long cnt[1000001];

void add(long long a)
{
	sum = sum - cnt[a] * cnt[a] * a;
	cnt[a]++;
	sum = sum + cnt[a] * cnt[a] * a;
}

void sub(long long a)
{
	sum = sum - cnt[a] * cnt[a] * a;
	cnt[a]--;
	sum = sum + cnt[a] * cnt[a] * a;
}

struct mo {
	int idx, a, b;
};

bool compare(mo& a, mo& b)
{
	if (a.a / sqt != b.a / sqt)
		return a.a / sqt < b.a / sqt;
	return a.b < b.b;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> t;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	vector<mo> v(t);
	vector<long long>answer(t);
	for (int a = 0; a < t; a++)
	{
		int l, r;
		cin >> l >> r;
		v[a] = { a, l - 1, r - 1 };
	}

	sqt = (int)sqrt(n);
	sort(v.begin(), v.end(), compare);

	int start = v[0].a, eend = v[0].b;
	for (int i = start; i <= eend; i++)
		add(arr[i]);
	answer[v[0].idx] = sum;

	for (int a = 1; a < t; a++)
	{
		while (v[a].a < start)
			add(arr[--start]);
		while (v[a].b > eend)
			add(arr[++eend]);
		while (v[a].a > start)
			sub(arr[start++]);
		while (v[a].b < eend)
			sub(arr[eend--]);

		answer[v[a].idx] = sum;
	}

	for (int i = 0; i < t; i++)
		cout << answer[i] << '\n';

	return 0;
}
