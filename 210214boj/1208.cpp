/**
*	BOJ
*	No.1208	부분수열의 합 2
*	@author	peter9378
*	@date		2021.02.14
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


// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, S;
	cin >> N >> S;

	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	int half = N / 2;
	vector<int> vv(1 << (N - half));

	for (int i = 0; i < 1 << (N - half); i++)
	{
		for (int j = 0; j < N - half; j++)
		{
			if (i&(1 << j))
				vv[i] += v[j];
		}
	}

	vector<int> vvv(1 << half);

	for (int i = 0; i < 1 << half; i++)
	{
		for (int j = 0; j < half; j++)
		{
			if (i&(1 << j))
				vvv[i] += v[j + (N - half)];
		}
	}

	sort(vv.begin(), vv.end());

	sort(vvv.begin(), vvv.end(), greater<int>());
	int idx = 0, idx2 = 0;
	long long answer = 0;

	while (idx < 1 << (N - half) && idx2 < 1 << half)
	{
		if (vv[idx] + vvv[idx2] == S)
		{
			long long a = 1, b = 1;
			idx++;
			idx2++;

			while (idx < 1 << (N - half) && vv[idx] == vv[idx - 1])
			{
				idx++;
				a++;
			}

			while (idx2 < 1 << half && vvv[idx2] == vvv[idx2 - 1])
			{
				idx2++;
				b++;
			}
			answer += a * b;
		}

		else if (vv[idx] + vvv[idx2] < S)
			idx++;
		else if (vv[idx] + vvv[idx2] > S)
			idx2++;
	}

	if (S == 0)
		answer--;

	cout << answer << "\n";

	return 0;
}
