/**
*	BOJ
*	No.10999	구간 합 구하기 2
*	@author	peter9378
*	@date		2021.07.02
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

long long init(vector<long long>& arr, vector<long long>& tree, int target, int start, int end)
{
	if (start == end)
		return tree[target] = arr[start];

	int mid = (start + end) / 2;
	return tree[target] = init(arr, tree, target * 2, start, mid) + init(arr, tree, target * 2 + 1, mid + 1, end);
}

void update_lazy(vector<long long>& tree, vector<long long>& lazy, int node, int start, int end)
{
	if (lazy[node] == 0)
		return;
	tree[node] += (end - start + 1) * lazy[node];

	if (start != end)
	{
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}

	lazy[node] = 0;
}

void update(vector<long long>& tree, vector<long long>& lazy, int target, int start, int end, int left, int right, long long value)
{
	update_lazy(tree, lazy, target, start, end);

	if (left > end || right < start)
		return;

	if (left <= start && end <= right)
	{
		tree[target] += (end - start + 1) * value;

		if (start != end)
		{
			lazy[target * 2] += value;
			lazy[target * 2 + 1] += value;
		}
		return;
	}

	int mid = (start + end) / 2;
	update(tree, lazy, target * 2, start, mid, left, right, value);
	update(tree, lazy, target * 2 + 1, mid + 1, end, left, right, value);
	tree[target] = tree[target * 2] + tree[target * 2 + 1];
}

long long go(vector<long long>& tree, vector<long long>& lazy, int target, int start, int end, int left, int right)
{
	update_lazy(tree, lazy, target, start, end);

	if (left > end || right < start)
		return 0;

	if (left <= start && end <= right)
		return tree[target];

	int mid = (start + end) / 2;
	return go(tree, lazy, target * 2, start, mid, left, right) + go(tree, lazy, target * 2 + 1, mid + 1, end, left, right);
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	int h = (int)ceil(log2(N));
	int tree_size = (1 << (1 + h));

	vector<long long> arr(N);
	vector<long long> tree(tree_size);
	vector<long long> lazy_tree(tree_size);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	init(arr, tree, 1, 0, N - 1);
	M += K;

	while (M--)
	{
		int temp;
		cin >> temp;

		if (temp == 1)
		{
			int left, right;
			long long value;

			cin >> left >> right >> value;
			update(tree, lazy_tree, 1, 0, N - 1, left - 1, right - 1, value);
		}
		else if (temp == 2)
		{
			int left, right;
			cin >> left >> right;
			cout << go(tree, lazy_tree, 1, 0, N - 1, left - 1, right - 1) << "\n";
		}
	}

	return 0;
}
