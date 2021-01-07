/**
*	BOJ
*	No.2336	±²ÀåÇÑ ÇÐ»ý
*	@author	peter9378
*	@date		2021.01.07
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

#define MAX 500000

struct student {
	int x, y, z;
};

bool compare(student a, student b) {
	return a.x < b.x;
}

student arr[MAX];
int N, answer;
int seg[4 * MAX];

int update(int target, int value, int node, int x, int y)
{
	if (y < target || target < x)
		return seg[node];

	if (x == y)
		return seg[node] = value;
	int mid = (x + y) >> 1;

	return seg[node] = min(update(target, value, node * 2, x, mid), update(target, value, node * 2 + 1, mid + 1, y));
}

int query(int left, int right, int node, int x, int y)
{
	if (y < left || right < x)
		return 987654321;

	if (left <= x && y <= right)
		return seg[node];

	int mid = (x + y) >> 1;

	return min(query(left, right, node * 2, x, mid), query(left, right, node * 2 + 1, mid + 1, y));
}


// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int a;
		cin >> a;
		arr[a].x = i;
	}

	for (int i = 1; i <= N; i++)
	{
		int a;
		cin >> a;
		arr[a].y = i;
	}

	for (int i = 1; i <= N; i++)
	{
		int a;
		cin >> a;
		arr[a].z = i;
	}

	sort(arr + 1, arr + 1 + N, compare);

	for (int i = 1; i <= N; i++)
		update(i, 987654321, 1, 1, N);

	for (int i = 1; i <= N; i++)
	{
		if (query(1, arr[i].y, 1, 1, N) > arr[i].z)
			answer++;

		update(arr[i].y, arr[i].z, 1, 1, N);
	}

	cout << answer;

	return 0;
}
