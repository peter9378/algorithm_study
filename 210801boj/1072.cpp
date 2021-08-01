/**
*	BOJ
*	No.1072	∞‘¿”
*	@author	peter9378
*	@date		2021.08.01
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

#define MAX 1000000000

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long X, Y, Z;
	cin >> X >> Y;
	Z = 100 * Y / X;
	if (Z >= 99)
	{
		cout << -1;
		return 0;
	}


	long long  left = 0, right = MAX;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long temp = 100 * (Y + mid) / (X + mid);

		if (Z < temp)
			right = mid - 1;
		else
			left = mid + 1;
	}

	cout << left;
	return 0;
}
