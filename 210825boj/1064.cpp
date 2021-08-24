/**
*	BOJ
*	No.1064	평행사변형
*	@author	peter9378
*	@date		2021.08.25
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

double a, b, c, d, e, f;

double distance(double a, double b, double c, double d) {
	return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b >> c >> d >> e >> f;

	double d1 = 9876543210;
	double db = 9876543210;

	if (a != c)
		d1 = abs(d - b) / abs(c - a);
	if (c != e)
		db = abs(f - d) / abs(e - c);

	if (d1 == db)
	{
		cout << -1;
		return 0;
	}

	double dist1 = distance(a, b, c, d);
	double dist2 = distance(a, b, e, f);
	double dist3 = distance(c, d, e, f);

	double result1 = 2 * (dist1 + dist2);
	double result2 = 2 * (dist2 + dist3);
	double result3 = 2 * (dist3 + dist1);

	cout << fixed;
	cout.precision(16);

	cout << max(result1, max(result2, result3)) - min(result1, min(result2, result3));

	return 0;
}