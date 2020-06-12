/**
*	BOJ
*	No.1485	정사각형
*	@author	peter9378
*	@date		2020.06.12
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

int go(pair<int, int> a, pair<int, int> b)
{
	return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
}

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		vector<pair<int, int>> v;
		set<int> s;

		for (int i = 0; i < 4; i++)
		{
			int a, b;
			cin >> a >> b;
			v.push_back({ a, b });
		}

		sort(v.begin(), v.end(), compare);

		s.insert(go(v[0], v[1]));
		s.insert(go(v[1], v[3]));
		s.insert(go(v[2], v[3]));
		s.insert(go(v[2], v[0]));

		if (go(v[0], v[3]) == go(v[1], v[2]))
			cout << (s.size() == 1 ? 1 : 0) << "\n";
		else
			cout << "0\n";
	}

	return 0;
}