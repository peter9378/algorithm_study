/**
*	BOJ
*	No.5676	음주 코딩
*	@author	peter9378
*	@date		2020.04.25
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

int N, K;
int arr[1000001], segment[400000];
char a;

int update(int index, int value, int current, int a, int b)
{
	if (b < index || index < a)
		return segment[current];

	if (a == b)
		return segment[current] = value;

	int mid = (a + b) >> 1;

	return segment[current] = update(index, value, current * 2, a, mid) * update(index, value, current * 2 + 1, mid + 1, b);
}

int query(int left, int right, int current, int a, int b)
{
	if (b < left || right < a)
		return 1;

	if (left <= a && b <= right)
		return segment[current];

	int mid = (a + b) >> 1;

	return query(left, right, current * 2, a, mid) * query(left, right, current * 2 + 1, mid + 1, b);
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> N >> K)
	{
		for (int i = 1; i <= N; i++)
		{
			int a;
			cin >> a;

			if (a > 0)
				update(i, 1, 1, 1, N);
			else if (!a)
				update(i, 0, 1, 1, N);
			else
				update(i, -1, 1, 1, N);
		}

		for (int i = 0; i < K; i++)
		{
			char a;
			int b, c;

			cin >> a >> b >> c;

			if (a == 'C')
			{
				if (c > 0)
					update(b, 1, 1, 1, N);
				else if (!c)
					update(b, 0, 1, 1, N);
				else
					update(b, -1, 1, 1, N);
			}
			else
			{
				int a = query(b, c, 1, 1, N);
				if (!a)
					cout << "0";
				else
					cout << (a > 0 ? '+' : '-');
			}
		}
		cout << "\n";
	}

	return 0;
}