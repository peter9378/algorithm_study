/**
*	BOJ
*	No.13925	¼ö¿­°ú Äõ¸® 13
*	@author	peter9378
*	@date		2020.10.18
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

#define MOD 1000000007
int N, M, H;
vector<int> arr;
vector<long long> tree;
vector<vector<long long>> seg;

long long init(int target, int start, int end)
{
	if (start == end)
		return tree[target] = arr[start];

	int temp = start + end >> 1;
	return tree[target] = (init(2 * target, start, temp) + init(2 * target + 1, temp + 1, end)) % MOD;
}

void updateLazy(int target, int start, int end)
{
	if (seg[target][0] == 1 && seg[target][1] == 0)
		return;

	if (start != end)
	{
		for (int i = 2 * target; i <= 2 * target + 1; i++)
		{
			seg[i][0] = seg[target][0] * seg[i][0] % MOD;
			seg[i][1] = (seg[target][0] * seg[i][1] % MOD + seg[target][1]) % MOD;
		}
	}

	tree[target] = (seg[target][0] * tree[target] % MOD + seg[target][1] * (end - start + 1) % MOD) % MOD;
	seg[target][0] = 1;
	seg[target][1] = 0;
	return;
}

long long update(int left, int right, int mul, int sum, int target, int start, int end)
{
	updateLazy(target, start, end);

	if (left > end || right < start)
		return tree[target];

	if (left <= start && end <= right)
	{
		seg[target][0] = seg[target][0] * mul % MOD;
		seg[target][1] = seg[target][1] * mul % MOD;
		seg[target][1] = (seg[target][1] + sum) % MOD;
		updateLazy(target, start, end);

		return tree[target];
	}
	int temp = start + end >> 1;
	return tree[target] = (update(left, right, mul, sum, 2 * target, start, temp) + update(left, right, mul, sum, 2 * target + 1, temp + 1, end)) % MOD;
}

long long query(int left, int right, int target, int start, int end)
{
	updateLazy(target, start, end);

	if (left > end || right < start)
		return 0;

	if (left <= start && end <= right)
		return tree[target];

	int temp = start + end >> 1;
	return (query(left, right, 2 * target, start, temp) + query(left, right, 2 * target + 1, temp + 1, end)) % MOD;
}


// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	arr.resize(N + 1);
	for (int i = 1; i < N + 1; i++)
		cin >> arr[i];

	H = 1 << (int)ceil(log2(N)) + 1;
	tree.resize(H);
	seg.resize(H, vector<long long>(2));

	for (int i = 1; i < H; i++)
	{
		seg[i][0] = 1;
		seg[i][1] = 0;
	}

	init(1, 1, N);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int q, a, b, c;
		cin >> q >> a >> b;
		if (q == 1)
		{
			cin >> c;
			update(a, b, 1, c, 1, 1, N);
		}
		else if (q == 2)
		{
			cin >> c;
			update(a, b, c, 0, 1, 1, N);
		}
		else if (q == 3)
		{
			cin >> c;
			update(a, b, 0, c, 1, 1, N);
		}
		else if (q == 4)
			cout << query(a, b, 1, 1, N) << "\n";
	}

	return 0;
}