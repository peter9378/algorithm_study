/**
*	BOJ
*	No.2042	구간 합 구하기
*	@author	peter9378
*	@date		2021.05.08
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

long long arr[4444444];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	long long target = 1;
	while (target < N)
		target *= 2;

	for (int i = 0; i < N; i++)
		cin >> arr[target + i];

	for (int i = target - 1; i > 0; i--)
		arr[i] = arr[2 * i] + arr[2 * i + 1];

	for (int i = 0; i < M + K; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
		{
			long long from = b + target - 1;
			long long temp = c - arr[from];
			while (from)
			{
				arr[from] += temp;
				from /= 2;
			}
		}
		else if (a == 2)
		{
			long long answer = 0;
			long long from = b + target - 1, to = c + target - 1;
			while (from <= to)
			{
				if (from % 2)
					answer += arr[from];
				if (!(to % 2))
					answer += arr[to];
				from = (from + 1) / 2;
				to = (to - 1) / 2;
			}
			cout << answer << "\n";
		}
	}

	return 0;
}
