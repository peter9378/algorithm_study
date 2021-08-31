/**
*	BOJ
*	No.1781	ÄÅ¶ó¸é
*	@author	peter9378
*	@date		2021.08.31
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

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i].first >> v[i].second;
		--v[i].first;
	}

	sort(v.begin(), v.end());

	int answer = 0;
	int temp = N - 1;
	priority_queue<int> pq;
	for (int i = N - 1; i >= 0; i--)
	{
		for (; temp >= 0 && v[temp].first == i; temp--)
			pq.push(v[temp].second);

		if (!pq.empty())
		{
			answer += pq.top();
			pq.pop();
		}
	}
	cout << answer;

	return 0;
}