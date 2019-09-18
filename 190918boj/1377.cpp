/**
*	BOJ
*	No.1377	버블 소트
*	@author	peter9378
*	@date		2019.09.18
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
		int temp;
		cin >> temp;
		v.push_back(make_pair(temp, i));
	}

	stable_sort(v.begin(), v.end());
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		if (answer < v[i].second - i)
			answer = v[i].second - i;
	}
	cout << answer + 1;

	return 0;
}