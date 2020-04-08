/**
*	BOJ
*	No.5620	가장 가까운 두 점의 거리
*	@author	peter9378
*	@date		2020.04.07
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
#include <cstring>
#include <iterator>
#include <numeric>
using namespace std;

int get_distance(pair<int, int> a, pair<int, int> b)
{
	return pow((a.first - b.first), 2) + pow((a.second - b.second), 2);
}

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
	if (a.first < b.first)
		return true;
	else if (a.first == b.first)
	{
		if (a.second < b.second)
			return true;
		return false;
	}
	return false;
}

int get_result3(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
	int result = 987654321;
	result = min(result, get_distance(a, b));
	result = min(result, get_distance(b, c));
	result = min(result, get_distance(c, a));
	return result;
}

int get_result4(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d)
{
	int result = 987654321;
	result = min(result, get_distance(a, b));
	result = min(result, get_distance(b, c));
	result = min(result, get_distance(c, d));
	result = min(result, get_distance(d, a));
	result = min(result, get_distance(a, c));
	result = min(result, get_distance(b, d));
	return result;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;

	if (n == 2)
		cout << get_distance(v[0], v[1]);
	else if (n == 3)
		cout << get_result3(v[0], v[1], v[2]);
	else
	{
		sort(v.begin(), v.end(), compare);

		int answer = 987654321;
		for (int i = 0; i < n - 3; i++)
			answer = min(answer, get_result4(v[i], v[i + 1], v[i + 2], v[i + 3]));
		cout << answer;
	}
	return 0;
}