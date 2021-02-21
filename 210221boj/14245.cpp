/**
*	BOJ
*	No.14245	XOR
*	@author	peter9378
*	@date		2021.02.21
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


long long arr[1000001];
long long seg[3000001];

long long calc(int origin_left, int origin_right, int target, int left, int right, int value)
{
	if (origin_left <= left && right <= origin_right)
		return seg[target] ^= value;

	if (right < origin_left || left > origin_right)
		return 0;

	return calc(origin_left, origin_right, target * 2, left, (left + right) / 2, value) + calc(origin_left, origin_right, target * 2 + 1, (left + right) / 2 + 1, right, value);
}


// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, K, temp = 1;
	cin >> N;

	while (temp < N)
		temp <<= 1;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		seg[temp + i - 1] = arr[i];
	}


	for (int i = temp + N; i < temp * 2; i++)
		seg[i] = 0;


	cin >> M;

	while (M--)
	{
		int a, b, c, d;

		cin >> a >> b;
		if (a == 1)
		{
			cin >> c >> d;

			b++;
			c++;
			calc(b, c, 1, 1, temp, d);
		}
		else
		{
			b++;
			int idx = temp + b - 1;
			int val = seg[idx];
			idx >>= 1;

			while (idx > 0)
			{
				val ^= seg[idx];
				idx >>= 1;
			}

			cout << val << "\n";
		}
	}

	return 0;
}
