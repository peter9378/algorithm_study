/**
*	BOJ
*	No.1168	요세푸스 문제 2
*	@author	peter9378
*	@date		2021.03.01 - REMEMBER
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

int N, K;
int a, b;
int seg[(1 << 18)];

int init(int node, int start, int eend)
{
	if (start == eend)
		return seg[node] = 1;
	int mid = (start + eend) / 2;

	return seg[node] = init(2 * node, start, mid) + init(2 * node + 1, mid + 1, eend);
}

int update(int node, int start, int end, int target)
{
	seg[node]--;
	if (start == end)
		return 0;

	int mid = (start + end) / 2;
	if (target <= mid)
		return update(2 * node, start, mid, target);
	return update(2 * node + 1, mid + 1, end, target);
}

int query(int node, int start, int eend, int order)
{
	if (start == eend)
		return start;
	int mid = (start + eend) / 2;

	if (order <= seg[2 * node])
		return query(2 * node, start, mid, order);
	return query(2 * node + 1, mid + 1, eend, order - seg[2 * node]);
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	init(1, 1, N);

	int index = 1;
	cout << "<";
	for (int i = 0; i < N; i++)
	{
		int size = N - i;
		index += K - 1;

		if (index % size == 0)
			index = size;
		else if (index > size)
			index %= size;

		int num = query(1, 1, N, index);

		update(1, 1, N, num);

		if (i == N - 1)
			cout << num;
		else
			cout << num << ", ";
	}

	cout << ">";

	return 0;
}
