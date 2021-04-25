/**
*	BOJ
*	No.1708	º¼·Ï ²®Áú
*	@author	peter9378
*	@date		2021.04.25
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

struct Coor {
	long long x, y;
	Coor(long long a, long long b) :x(a), y(b) {};
	Coor() {};
	bool operator<(const Coor &rhs) const {
		if (x != rhs.x)
			return x < rhs.x;
		return y < rhs.y;
	}
};
vector<Coor> v;

long long ccw(Coor a, Coor b, Coor c)
{
	long long result = a.x*b.y + b.x*c.y + c.x*a.y;
	result -= (b.x*a.y + c.x*b.y + a.x*c.y);
	return result;
}

long long dist(Coor a, Coor b)
{
	long long x = b.x - a.x;
	long long y = b.y - a.y;

	return x * x + y * y;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	v.resize(N);

	for (int i = 0; i < N; i++)
		cin >> v[i].x >> v[i].y;

	vector<Coor> hull;
	swap(v[0], *min_element(v.begin(), v.end()));
	sort(v.begin() + 1, v.end(), [](Coor x, Coor y) {
		long long cw = ccw(v[0], x, y);
		if (cw == 0)
			return dist(v[0], x) < dist(v[0], y);
		return cw > 0;
	});

	for (auto vv : v)
	{
		while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), vv) <= 0)
			hull.pop_back();
		hull.push_back(vv);
	}

	cout << hull.size();

	return 0;
}
