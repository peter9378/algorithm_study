/**
*	BOJ
*	No.2166	다각형의 면적
*	@author	peter9378
*	@date		2020.11.30
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

double go(double x1, double x2, double x3, double y1, double y2, double y3)
{
	return (x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1) / 2;
}

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<pair<double, double>> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i].first >> v[i].second;

	double answer = 0;
	for (int i = 1; i < N; i++)
		answer += go(v[0].first, v[i - 1].first, v[i].first, v[0].second, v[i - 1].second, v[i].second);

	cout.precision(1);
	cout << fixed << abs(answer);

	return 0;
}