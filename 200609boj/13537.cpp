/**
*	BOJ
*	No.13537	¼ö¿­°ú Äõ¸® 1
*	@author	peter9378
*	@date		2020.06.09
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
#include <cstring>
#include <iterator>
#include <numeric>
using namespace std;

vector<int> seg[500005];

void update(int current, int node, int start, int end, int target)
{
	if (node<start || node>end)
		return;

	seg[current].push_back(target);
	if (start != end)
	{
		update(current * 2, node, start, (start + end) / 2, target);
		update(current * 2 + 1, node, (start + end) / 2 + 1, end, target);
	}
	return;
}

int dfs(int node, int start, int end, int left, int right, int target)
{
	if (left > end || right < start)
		return 0;

	if (left <= start && right >= end)
		return seg[node].end() - upper_bound(seg[node].begin(), seg[node].end(), target);
	int mid = (start + end) / 2;
	return dfs(node * 2, start, mid, left, right, target) + dfs(node * 2 + 1, mid + 1, end, left, right, target);
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N;

	vector<int> arr(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		update(1, i, 1, N, arr[i]);
	}

	for (int i = 0; i < 500005; i++)
		sort(seg[i].begin(), seg[i].end());

	cin >> M;
	while (M--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		cout << dfs(1, 1, N, a, b, c) << "\n";
	}

	return 0;
}