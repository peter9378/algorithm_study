/**
*	BOJ
*	No.1135	뉴스 전하기
*	@author	peter9378
*	@date		2020.04.12
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

vector<pair<int, int>> v[55];

bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.first > b.first;
}

int dfs(int current)
{
	int result = 0;

	for (int i = 0; i < v[current].size(); i++)
	{
		int next = v[current][i].second;
		v[current][i].first = dfs(next) + 1;
	}

	sort(v[current].begin(), v[current].end(), compare);

	for (int i = 0; i < v[current].size(); i++)
	{
		v[current][i].first += i;
		result = max(result, v[current][i].first);
	}

	return result;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;

		if (a == -1)
			continue;

		v[a].push_back({ 0, i });
	}

	cout << dfs(0);

	return 0;
}