/**
*	BOJ
*	No.12865	Æò¹üÇÑ ¹è³¶
*	@author	peter9378
*	@date		2019.11.01
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

int dp[101][100001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<pair<int, int>> v;
	v.push_back(make_pair(0, 0));
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	//sort(v.begin(), v.end());

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (v[i].first > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].first] + v[i].second);
		}
	}

	cout << dp[N][K];

	return 0;
}