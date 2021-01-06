/**
*	BOJ
*	No.15977	조화로운 행렬
*	@author	peter9378
*	@date		2021.01.06
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

const int MAX = 2e5 + 4;
const int SMAX = (1 << 20);

int N, M, a[3][MAX], inp[3][MAX], dp[MAX];
int seg[SMAX];
vector<tuple<int, int, int>> b;
vector<pair<int, int>> c;

void update(int target, int value)
{
	target += SMAX / 2;
	seg[target] = value;
	while (target > 1)
	{
		target /= 2;
		seg[target] = max(seg[target * 2], seg[target * 2 + 1]);
	}
}

int val(int start, int end, int i, int next_start, int next_end)
{
	if (end < next_start || next_end < start)
		return 0;
	if (start <= next_start && next_end <= end)
		return seg[i];

	int mid = (next_start + next_end) / 2;
	return max(val(start, end, i * 2, next_start, mid), val(start, end, i * 2 + 1, mid + 1, next_end));
}

int val(int e)
{
	return val(0, e, 1, 0, SMAX / 2 - 1);
}

int go(int start, int end)
{
	if (start == end)
		return 0;

	int result = 0;
	int mid = (start + end) / 2;
	result = max(result, go(start, mid));

	vector<tuple<int, int, int>> temp;
	for (int i = start; i <= end; i++)
		temp.push_back({ get<1>(b[i]), get<2>(b[i]), i });

	sort(temp.begin(), temp.end());

	for (tuple<int, int, int> t : temp)
	{
		int x, y, idx;
		tie(x, y, idx) = t;

		dp[idx] = max(dp[idx], 1);

		if (idx > mid)
		{
			dp[idx] = max(dp[idx], val(y) + 1);
			result = max(result, dp[idx]);
		}
		else
			update(y, dp[idx]);
	}

	for (tuple<int, int, int> t : temp)
	{
		int x, y, idx;
		tie(x, y, idx) = t;

		if (idx <= mid)
			update(y, 0);
	}

	result = max(result, go(mid + 1, end));
	return result;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;

	for (int i = 0; i < M; i++) for (int j = 0; j < N; j++)
	{
		cin >> inp[i][j];
		a[i][j] = inp[i][j];
	}
	for (int i = 0; i < M; i++)
		sort(inp[i], inp[i] + N);

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			a[i][j] = lower_bound(inp[i], inp[i] + N, a[i][j]) - inp[i];
	}


	if (M == 3)
	{
		for (int i = 0; i < N; i++)
			b.push_back({ a[0][i], a[1][i], a[2][i] });

		sort(b.begin(), b.end());

		int ans = go(0, N - 1);
		cout << ans << '\n';
	}
	else if (M == 2)
	{
		for (int i = 0; i < N; i++)
			c.push_back({ a[0][i], a[1][i] });

		sort(c.begin(), c.end());
		vector<int> v(1, -1);

		for (int i = 0, x, y; i < N; i++)
		{
			tie(x, y) = c[i];
			if (v.back() < y)
				v.push_back(y);
			else
				*lower_bound(v.begin(), v.end(), y) = y;
		}
		cout << v.size() - 1 << '\n';
	}

	return 0;
}
