/**
*	BOJ
*	No.14428	¼ö¿­°ú Äõ¸® 16
*	@author	peter9378
*	@date		2021.05.02
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

int arr[100001], seg[400000];
int update(int current, int target, int x, int y)
{
	if (current < x || y < current)
		return seg[target];

	if (x == y)
		return seg[target] = x;

	int mid = (x + y) >> 1;
	int a = update(current, target * 2, x, mid);
	int b = update(current, target * 2 + 1, mid + 1, y);

	if (a == -1 && b == -1)
		return -1;
	else if (a == -1)
		return seg[target] = b;
	else if (b == -1)
		return seg[target] = a;
	else if (arr[a] <= arr[b])
		return seg[target] = a;
	return seg[target] = b;
}

int query(int left, int right, int target, int x, int y)
{
	if (y < left || right < x)
		return -1;
	if (left <= x && y <= right)
		return seg[target];

	int mid = (x + y) >> 1;
	int a = query(left, right, target * 2, x, mid);
	int b = query(left, right, target * 2 + 1, mid + 1, y);

	if (a == -1)
		return b;
	if (b == -1)
		return a;
	if (arr[a] <= arr[b])
		return a;
	return b;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	for (int i = 1; i <= N; i++)
		update(i, 1, 1, N);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			arr[b] = c;
			update(b, 1, 1, N);
		}
		else
			cout << query(b, c, 1, 1, N) << "\n";
	}

	return 0;
}
