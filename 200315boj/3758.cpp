/**
*	BOJ
*	No.3758	KCPC
*	@author	peter9378
*	@date		2020.03.15
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

int score[101][101];
int idx[101];
int submit[101];

void init()
{
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
			score[i][j] = 0;
		idx[i] = 0;
		submit[i] = 0;
	}
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
		init();
		int n, k, t, m;
		cin >> n >> k >> t >> m;

		for (int a = 0; a < m; a++)
		{
			int i, j, s;
			cin >> i >> j >> s;

			score[i][j] = max(score[i][j], s);
			idx[i]++;
			submit[i] = a;
		}

		pair<pair<int, int>, pair<int, int>> team[101];
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= k; j++)
				team[i].first.first -= score[i][j];
			team[i].first.second = idx[i];
			team[i].second.first = submit[i];
			team[i].second.second = i;
		}

		sort(team + 1, team + n + 1);
		int answer = 0;
		for (int i = 1; i <= n; i++)
		{
			if (team[i].second.second == t)
				answer = i;
		}

		cout << answer << "\n";
	}

	return 0;
}