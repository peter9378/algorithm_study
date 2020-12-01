/**
*	BOJ
*	No.2568	ภüฑ๊มู - 2
*	@author	peter9378
*	@date		2020.12.01
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

vector<int> arr;
vector<int> dp;
vector<pair<int, int>> v;
int temp[1000001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}

	sort(v.begin(), v.end());
	arr.push_back(v[0].second);


	for (int i = 1; i < N; i++)
	{
		if (arr.back() < v[i].second)
		{
			arr.push_back(v[i].second);
			temp[i] = arr.size() - 1;
		}
		else
		{
			auto it = lower_bound(arr.begin(), arr.end(), v[i].second);
			*it = v[i].second;
			temp[i] = it - arr.begin();
		}
	}

	int cnt = arr.size();
	cout << N - cnt << "\n";
	cnt--;

	for (int i = N - 1; i >= 0; i--)
	{
		if (temp[i] == cnt)
		{
			cnt--;
			continue;
		}

		dp.push_back(v[i].first);
	}

	for (int i = dp.size() - 1; i >= 0; i--)
		cout << dp[i] << "\n";

	return 0;
}
