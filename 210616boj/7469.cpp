/**
*	BOJ
*	No.7469	K¹øÂ° ¼ö
*	@author	peter9378
*	@date		2021.06.16
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

#define MAX 1000000

int height;
vector<int> v[MAX];

void init()
{
	for (int i = height - 1; i >= 1; i--)
	{
		vector<int> &vv = v[i], &left = v[i * 2], &right = v[i * 2 + 1];
		v[i].resize(left.size() + right.size());

		for (int j = 0, k = 0, p = 0; j < vv.size(); j++)
		{
			if (p == right.size() || (k < left.size() && left[k] < right[p]))
				vv[j] = left[k++];
			else
				vv[j] = right[p++];
		}
	}
}

int go(int target, int left, int right, int start, int end, int value)
{
	if (right < start || end < left)
		return 0;
	if (start <= left && right <= end)
		return lower_bound(v[target].begin(), v[target].end(), value) - v[target].begin();
	int mid = (left + right) / 2;
	return go(target * 2, left, mid, start, end, value) + go(target * 2 + 1, mid + 1, right, start, end, value);
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	height = 1 << (int)ceil(log2(n));
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v[i + height].push_back(temp);
	}

	init();
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;

		int left = -1000000000, right = 1000000000;
		int answer = -1000000007;

		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (go(1, 0, height - 1, a, b, mid) < c)
			{
				answer = max(answer, mid);
				left = mid + 1;
			}
			else
				right = mid - 1;
		}
		cout << answer << "\n";
	}

	return 0;
}
