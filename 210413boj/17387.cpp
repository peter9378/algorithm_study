/**
*	BOJ
*	No.17387	선분 교차 2
*	@author	peter9378
*	@date		2021.04.13
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

int CCW(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c)
{
	long long temp = a.first * b.second + b.first * c.second + c.first * a.second;
	temp = temp - a.second * b.first - b.second * c.first - c.second * a.first;

	if (temp > 0)
		return 1;
	else if (temp == 0)
		return 0;
	return -1;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	pair<int, int> x1;
	pair<int, int> y1;
	pair<int, int> x2;
	pair<int, int> y2;

	cin >> x1.first >> x1.second;
	cin >> y1.first >> y1.second;
	cin >> x2.first >> x2.second;
	cin >> y2.first >> y2.second;

	int abc = CCW(x1, y1, x2);
	int abd = CCW(x1, y1, y2);
	int cda = CCW(x2, y2, x1);
	int cdb = CCW(x2, y2, y1);

	if (abc * abd == 0 && cda * cdb == 0)
	{
		if (x1 > y1)
			swap(x1, y1);
		if (x2 > y2)
			swap(x2, y2);

		cout << (int)(x1 <= y2 && x2 <= y1);
		return 0;
	}

	cout << (int)(abc * abd <= 0 && cda * cdb <= 0);

	return 0;
}
