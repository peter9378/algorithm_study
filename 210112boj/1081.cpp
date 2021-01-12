/**
*	BOJ
*	No.1081	гу
*	@author	peter9378
*	@date		2021.01.12
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

long long go(long long target)
{
	if (target <= 0)
		return 0;

	long long arr[10] = { 0, }, s = 1, result = 0, temp, o;
	while (target > 0)
	{
		temp = target / (s * 10);
		o = target % (s * 10);
		for (int i = 0; i < 10; i++)
			arr[i] += temp * s;

		for (int i = 1; i <= o / s; i++)
			arr[i] += s;

		arr[(o / s + 1) % 10] += o % s;
		target -= 9 * s;
		s *= 10;
	}

	for (int i = 1; i < 10; i++)
		result += i * arr[i];

	return result;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long L, U;
	cin >> L >> U;
	cout << go(U) - go(L - 1);

	return 0;
}
