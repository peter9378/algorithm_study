/**
*	BOJ
*	No.1069	ÁýÀ¸·Î
*	@author	peter9378
*	@date		2021.07.29
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

	int X, Y, D, T;
	cin >> X >> Y >> D >> T;

	double distance = sqrt((double)(X * X + Y * Y));
	double answer = distance;
	int count = distance / D;
	distance -= count * D;

	if (count == 0)
	{
		answer = min(answer, (double)T + ((double)D - distance));
		answer = min(answer, 2.0 * (double)T);
	}
	else
	{
		answer = min(answer, (double)count * T + distance);
		answer = min(answer, (double)((count + 1) * T));
	}

	cout << fixed;
	cout.precision(13);
	cout << answer;

	return 0;
}
