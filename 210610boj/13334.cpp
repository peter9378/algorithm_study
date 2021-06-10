/**
*	BOJ
*	No.13334	Ã¶·Î
*	@author	peter9378
*	@date		2021.06.10
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

vector<pair<int, int>> v;
vector<pair<int, int>> vv;
priority_queue<int, vector<int>, greater<int>> pq;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second != b.second)
		return a.second < b.second;
	return a.first < b.first;
}
// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int h, o;
		cin >> h >> o;

		if (h > o)
			vv.push_back({ o,h });
		else
			vv.push_back({ h,o });
	}

	int d;
	cin >> d;

	sort(vv.begin(), vv.end(), compare);

	int answer = 0;
	for (int i = 0; i < vv.size(); i++)
	{
		int left = vv[i].first;
		int right = vv[i].second;

		if (right - left <= d)
			pq.push(left);
		else
			continue;

		while (!pq.empty())
		{
			int current = pq.top();
			if (right - current <= d)
				break;
			else
				pq.pop();
		}

		answer = max(answer, (int)pq.size());
	}

	cout << answer;

	return 0;
}
