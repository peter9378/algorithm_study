/**
*	BOJ
*	No.1931	회의실 배정
*	@author	peter9378
*	@date		2019.10.17
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(b, a));
	}

	stable_sort(v.begin(), v.end());

	int answer = 1;
	int end = v[0].first;

	for (int i = 1; i < N; i++)
	{
		if (end <= v[i].second)
		{
			answer++;
			end = v[i].first;
		}
	}

	cout << answer;

	return 0;
}