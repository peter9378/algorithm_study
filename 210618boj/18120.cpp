/**
*	BOJ
*	No.18120	¥Î≥Û∫Œ ±ËªÛ«ı
*	@author	peter9378
*	@date		2021.06.18
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

bool compare(pair<double, int>a, pair<double, int>b) {
	return a < b;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, A;
	cin >> N >> A;

	double temp = 0;
	double worth = 0;
	vector<pair<double, int>> p(N);
	for (int i = 1; i <= N; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		p[i - 1].first = sqrt(x*x + y * y);
		p[i - 1].second = w;
		temp += w * sqrt(x*x + y * y);
		worth += w;
	}

	sort(p.begin(), p.end(), compare);
	double answer = pow(worth, 2) / (4 * A) - temp;

	worth = 0;
	temp = 0;
	double r = 0;
	for (int i = 1; i <= N; i++)
	{
		double r1 = worth / (2 * A);
		if (r <= r1 && r1 <= p[i - 1].first)
			answer = max(-A * r1*r1 + r1 * worth - temp, answer);

		r = p[i - 1].first;
		answer = max((-A)*r*r + r * worth - temp, answer);

		worth += p[i - 1].second;
		temp += p[i - 1].first*p[i - 1].second;
		answer = max((-A)*r*r + r * worth - temp, answer);
	}

	cout << fixed;
	cout.precision(6);
	cout << ((answer < 0) ? 0 : answer);


	return 0;
}
