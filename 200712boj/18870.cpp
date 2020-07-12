/**
*	BOJ
*	No.18870	ÁÂÇ¥ ¾ÐÃà
*	@author	peter9378
*	@date		2020.07.12
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
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>> v;
	vector<int> answer(N);
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v.push_back({ a, i });
	}

	sort(v.begin(), v.end());

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		int index = v[i].second;
		int a = cnt;
		answer[index] = a;
		cnt++;

		while (i < N && v[i].first == v[i + 1].first)
		{
			index = v[++i].second;
			answer[index] = a;
		}
	}

	for (int i = 0; i < N; i++)
		cout << answer[i] << " ";

	return 0;
}