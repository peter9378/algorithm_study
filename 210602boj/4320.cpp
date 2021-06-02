/**
*	BOJ
*	No.4320	완전 P제곱수
*	@author	peter9378
*	@date		2021.06.02
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

	long long x;
	while (cin >> x)
	{
		if (!x)
			break;

		long long answer = 1;
		for (long long i = 2; i * i <= x; i++)
		{
			if (pow(i, answer) > x)
				break;

			long long cnt = 1;
			long long temp = i;
			while (temp < x)
			{
				temp *= i;
				cnt++;

				if (temp == x)
					answer = max(answer, cnt);
			}
		}
		cout << answer << "\n";
	}

	return 0;
}
