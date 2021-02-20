/**
*	BOJ
*	No.9240	로버트 후드
*	@author	peter9378
*	@date		2021.02.20
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

typedef struct pos {
	long long x, y;
	long long cmp;
};


int N;
pos arr[100002];

double dist(pos a, pos b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}


bool cmp1(pos a, pos b)
{
	return a.x < b.x || (a.x == b.x) && (a.y < b.y);
}

long long ccw(pos a, pos b, pos c)
{
	return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
}

bool cmp2(pos a, pos b)
{
	long long temp = ccw(arr[0], a, b);
	return temp == 0 ? dist(arr[0], a) < dist(arr[0], b) : temp > 0;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i].x >> arr[i].y;

	sort(arr, arr + N, cmp1);
	sort(arr + 1, arr + N, cmp2);

	vector<pos> v;
	v.push_back(arr[0]);
	v.push_back(arr[1]);

	for (int i = 2; i < N; i++)
	{
		while (v.size() >= 2 && ccw(v[v.size() - 2], v.back(), arr[i]) <= 0)
			v.pop_back();
		v.push_back(arr[i]);
	}

	double answer = -1;
	int length = v.size();

	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j < length; j++)
			answer = max(answer, dist(v[i], v[j]));
	}

	printf("%.6f", answer);

	return 0;
}
