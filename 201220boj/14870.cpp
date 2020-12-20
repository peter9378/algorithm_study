/**
*	BOJ
*	No.14870	조개 줍기
*	@author	peter9378
*	@date		2020.12.20
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

int N;

struct BTREE {
	long long tree[1515];

	void update(int l, int r, int v)
	{
		for (; l <= N; l += l & -l)
			tree[l] += v;
		for (r++; r <= N; r += r & -r)
			tree[r] -= v;
	}

	long long query(int x)
	{
		long long ret = 0;
		for (; x; x ^= x & -x)
			ret += tree[x];
		return ret;
	}
} tree[1515];

long long ans = 0;
int arr[1515][1515];
int dp[1515][1515];
int start[1515], end_[1515];

inline long long get(int i, int j)
{
	return dp[i][j] + tree[i].query(j);
}

void init()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
			ans += dp[i][j];
		}
	}
}

void query(int a, int b, int c)
{
	start[a] = end_[a] = b;
	for (int i = a + 1; i <= N; i++)
	{
		start[i] = N + 1;
		end_[i] = 0;
	}

	for (int i = a, j = b;;)
	{
		if (j < N && max(get(i - 1, j + 1), get(i, j)) + c == max(get(i - 1, j + 1), get(i, j) + c))
			j++;
		else
			i++;

		if (i > N)
			break;

		end_[i] = j;
	}

	for (int i = a, j = b;;)
	{
		if (i < N && max(get(i + 1, j - 1), get(i, j)) + c == max(get(i + 1, j - 1), get(i, j) + c))
			i++;
		else
			j++;

		if (j > N || end_[i] < j)
			break;

		start[i] = min(start[i], j);
	}

	for (int i = a; i <= N; i++)
	{
		if (start[i] > end_[i])
			continue;
		tree[i].update(start[i], end_[i], c);
		ans += c * (end_[i] - start[i] + 1);
	}

	cout << ans << "\n";
	return;
}


// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	}

	init();
	cout << ans << "\n";

	for (int i = 1; i <= N; i++)
	{
		int a, b;
		char op;
		cin >> op >> a >> b;

		if (op == 'U')
			query(a, b, 1);
		else
			query(a, b, -1);
	}

	return 0;
}
