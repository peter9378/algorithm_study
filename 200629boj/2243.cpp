/**
*	BOJ
*	No.2243	ªÁ≈¡ªÛ¿⁄
*	@author	peter9378
*	@date		2020.06.29
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

int arr[1000001];
int tree[4000004];

void update(int target, int start, int end, int diff, int index)
{
	if (index < start || end < index)
		return;

	tree[target] += diff;
	if (start != end)
	{
		update(target * 2, start, (start + end) / 2, diff, index);
		update(target * 2 + 1, (start + end) / 2 + 1, end, diff, index);
	}
}

int query(int target, int start, int end, int pivot)
{
	if (start == end)
		return start;

	if (tree[target * 2] >= pivot)
		return query(target * 2, start, (start + end) / 2, pivot);
	return query(target * 2 + 1, (start + end) / 2 + 1, end, pivot - tree[target * 2]);
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
		int a, b, c;
		cin >> a;
		if (a == 2)
		{
			cin >> b >> c;
			arr[b] += c;
			update(1, 1, 1000000, c, b);
		}
		else
		{
			cin >> b;
			int answer = query(1, 1, 1000000, b);
			cout << answer << "\n";
			arr[answer]--;
			update(1, 1, 1000000, -1, answer);
		}
	}

	return 0;
}
