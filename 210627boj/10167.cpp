/**
*	BOJ
*	No.10167	±Ý±¤
*	@author	peter9378
*	@date		2021.06.27
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

struct Coor {
	int x, y, w;
};

struct Dot {
	long long sum, left, right, total;
};

Coor arr[3001];
vector<pair<int, int> > v, vv, vvv[3001];
Dot seg[12121];

Dot update(int idx, int val, int n, int l, int r)
{
	if (r < idx || idx < l) return seg[n];

	if (l == r && l == idx)
	{
		seg[n].sum += val, seg[n].left += val, seg[n].right += val, seg[n].total += val;
		return seg[n];
	}

	int mid = (l + r) / 2;
	Dot left, right;
	left = update(idx, val, n * 2, l, mid);
	right = update(idx, val, n * 2 + 1, mid + 1, r);

	seg[n].sum = left.sum + right.sum;
	seg[n].left = max(left.left, left.sum + right.left);
	seg[n].right = max(right.right, right.sum + left.right);
	seg[n].total = max({ left.total, right.total, left.right + right.left });
	return seg[n];
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		v.push_back({ x, i });
		vv.push_back({ y, i });

		arr[i].w = w;
	}

	sort(v.begin(), v.end());
	sort(vv.begin(), vv.end());

	int temp = 0;
	for (int i = 0; i < N; i++)
	{
		if (i > 0 && v[i - 1].first != v[i].first)
			temp++;
		arr[v[i].second].x = temp;
	}

	temp = 0;
	for (int i = 0; i < N; i++)
	{
		if (i > 0 && vv[i - 1].first != vv[i].first)
			temp++;
		arr[vv[i].second].y = temp;
	}

	for (int i = 0; i < N; i++)
		vvv[arr[i].y].push_back({ arr[i].x, arr[i].w });

	long long answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 12121; j++)
		{
			Dot temp;
			temp.sum = temp.left = temp.right = temp.total = 0;
			seg[j] = temp;
		}

		for (int j = i; j < N; j++)
		{
			for (int k = 0; k < vvv[j].size(); k++)
			{
				int tempx = vvv[j][k].first;
				int tempy = j;
				int tempw = vvv[j][k].second;

				update(tempx, tempw, 1, 0, N - 1);
			}

			answer = max(answer, seg[1].total);
		}
	}

	cout << answer;

	return 0;
}
