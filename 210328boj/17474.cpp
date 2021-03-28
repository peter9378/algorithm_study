/**
*	BOJ
*	No.17474	¼ö¿­°ú Äõ¸® 26
*	@author	peter9378
*	@date		2021.03.28
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

typedef struct node {
	long long value, maxi, maxi_cnt, sum;
} node;

vector<long long>arr;
vector<node> tree;

node fusion(node left, node right)
{
	if (left.value == right.value)
		return { left.value, max(left.maxi, right.maxi), left.maxi_cnt + right.maxi_cnt, left.sum + right.sum };
	else if (left.value > right.value)
		return { left.value, max(right.value, left.maxi), left.maxi_cnt, left.sum + right.sum };
	return { right.value, max(left.value, right.maxi), right.maxi_cnt, left.sum + right.sum };
}

node init(int target, int left, int right)
{
	if (left == right)
		return tree[target] = { arr[left], -987654321, 1, arr[left] };

	int mid = (left + right) / 2;
	return tree[target] = fusion(init(2 * target, left, mid), init(2 * target + 1, mid + 1, right));
}

void lazy(int target, int left, int right)
{
	if (left == right)
		return;

	for (int j = 2 * target; j <= 2 * target + 1; j++)
	{
		if (tree[target].value < tree[j].value)
		{
			tree[j].sum -= tree[j].maxi_cnt * (tree[j].value - tree[target].value);
			tree[j].value = tree[target].value;
		}
	}
	return;
}

void range(int target, int left, int right, int lleft, int rright, long long val)
{
	lazy(target, left, right);
	if (right < lleft || rright < left || tree[target].value <= val)
		return;

	if (lleft <= left && right <= rright && tree[target].maxi < val)
	{
		tree[target].sum -= tree[target].maxi_cnt * (tree[target].value - val);
		tree[target].value = val;
		lazy(target, left, right);
		return;
	}

	int mid = (left + right) / 2;
	range(2 * target, left, mid, lleft, rright, val);
	range(2 * target + 1, mid + 1, right, lleft, rright, val);
	tree[target] = fusion(tree[2 * target], tree[2 * target + 1]);
	return;
}

long long query(int target, int left, int right, int lleft, int rright)
{
	lazy(target, left, right);
	if (right < lleft || rright < left)
		return -987654321;

	if (lleft <= left && right <= rright)
		return tree[target].value;
	int mid = (left + right) / 2;
	return max(query(target * 2, left, mid, lleft, rright), query(target * 2 + 1, mid + 1, right, lleft, rright));
}

long long query_sum(int target, int left, int right, int lleft, int rright)
{
	lazy(target, left, right);
	if (right < lleft || rright < left)
		return 0;
	if (lleft <= left && right <= rright)
		return tree[target].sum;

	int mid = (left + right) / 2;
	return query_sum(2 * target, left, mid, lleft, rright) + query_sum(2 * target + 1, mid + 1, right, lleft, rright);
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, L, R;
	long long val;
	cin >> N;

	arr.resize(N);
	tree.resize(4 * N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	init(1, 0, N - 1);
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int q;
		cin >> q;

		if (q == 1)
		{
			cin >> L >> R >> val;
			range(1, 0, N - 1, L - 1, R - 1, val);
		}
		else if (q == 2)
		{
			cin >> L >> R;
			cout << query(1, 0, N - 1, L - 1, R - 1) << "\n";
		}
		else
		{
			cin >> L >> R;
			cout << query_sum(1, 0, N - 1, L - 1, R - 1) << "\n";
		}
	}

	return 0;
}
