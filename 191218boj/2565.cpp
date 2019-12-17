/**
*	BOJ
*	No.2656	ภüฑ๊มู
*	@author	peter9378
*	@date		2019.12.18
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
using namespace std;

int dp[101];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end());

	int answer = 0;
	dp[0] = 1;
	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		for (int j = 0; j < i; j++)
		{
			if (v[i].second > v[j].second)
				temp = max(dp[j], temp);
		}
		dp[i] = temp + 1;
	}

	for (int i = 0; i < N; i++)
		answer = max(answer, dp[i]);

	cout << N - answer;

	return 0;
}
