/**
*	BOJ
*	No.17353	하늘에서 떨어지는 1, 2, ..., R-L+1개의 별
*	@author	peter9378
*	@date		2021.03.07
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

int N, M, H;
vector<long long> v, diff, seg, lazy_seg;

long long init(int target, int start, int eend)
{
	if (start == eend)
		return seg[target] = diff[start];
	int mid = start + eend >> 1;
	return seg[target] = init(target << 1, start, mid) + init(target << 1 | 1, mid + 1, eend);
}

void lazy(int target, int start, int eend)
{
	if (lazy_seg[target])
	{
		if (start ^ eend)
		{
			lazy_seg[target << 1] += lazy_seg[target];
			lazy_seg[target << 1 | 1] += lazy_seg[target];
		}
		seg[target] += (eend - start + 1) * lazy_seg[target];
		lazy_seg[target] = 0;
	}
	return;
}

long long update(int left, int right, int val, int target, int start, int eend)
{
	lazy(target, start, eend);

	if (left > eend || right < start)
		return seg[target];

	if (left <= start && eend <= right)
	{
		lazy_seg[target] = val;
		lazy(target, start, eend);
		return seg[target];
	}

	int mid = start + eend >> 1;
	return seg[target] = update(left, right, val, target << 1, start, mid) + update(left, right, val, target << 1 | 1, mid + 1, eend);
}

long long query(int left, int right, int target, int start, int eend)
{
	lazy(target, start, eend);
	if (left > eend || right < start)
		return 0;
	if (left <= start && eend <= right)
		return seg[target];
	int m = start + eend >> 1;
	return query(left, right, target << 1, start, m) + query(left, right, target << 1 | 1, m + 1, eend);
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	v.resize(N + 1);
	diff.resize(N + 1);

	H = 1 << (int)ceil(log2(N)) + 1;
	seg.resize(H);
	lazy_seg.resize(H);

	for (int i = 1; i < N + 1; i++)
	{
		cin >> v[i];
		diff[i] = v[i] - v[i - 1];
	}

	init(1, 1, N);
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b;

		if (a == 1)
		{
			cin >> c;
			update(b, c, 1, 1, 1, N);
			update(c + 1, c + 1, -(c - b + 1), 1, 1, N);
		}
		else
			cout << query(1, b, 1, 1, N) << "\n";
	}

	return 0;
}
