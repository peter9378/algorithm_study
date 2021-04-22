/**
*	BOJ
*	No.3653	영화 수집
*	@author	peter9378
*	@date		2021.04.22
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

int n, m;
int arr[100001];
int tree[200005];

void update(int idx, int val)
{
	while (idx < 200005)
	{
		tree[idx] += val;
		idx += idx & (-idx);
	}
}

int query(int idx)
{
	int result = 0;
	while (idx > 0)
	{
		result += tree[idx];
		idx -= idx & (-idx);
	}
	return result;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--)
	{
		memset(arr, 0, sizeof(arr));
		memset(tree, 0, sizeof(tree));

		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			arr[i] = i + m;
			update(i + m, 1);
		}
		for (int i = 0; i < m; i++)
		{
			int in;
			cin >> in;
			cout << query(arr[in]) - 1 << " ";
			update(arr[in], -1);
			arr[in] = m - i;
			update(arr[in], 1);
		}
	}

	return 0;
}
