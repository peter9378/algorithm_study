/**
*	BOJ
*	No.1006	습격자 초라기
*	@author	peter9378
*	@date		2020.03.11
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

int N, W;
int arr[10001][2];
int dp[10001][4][4];

void init()
{
	for (int i = 0; i < 10001; i++)
	{
		arr[i][0] = 0;
		arr[i][1] = 0;
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
				dp[i][j][k] = -1;
		}
	}
	return;
}

int dfs(int index, int current, int next)
{
	int &answer = dp[index][current][next];
	if (answer != -1)
		return answer;

	bool inside, outside, common;
	inside = (arr[index][0] + arr[index ? index - 1 : N - 1][0] <= W);
	outside = (arr[index][1] + arr[index ? index - 1 : N - 1][1] <= W);
	common = (arr[index][0] + arr[index][1] <= W);

	if (index == N - 1)
	{
		if (index == 0)
			return common ? 1 : 2;

		answer = 2;

		if (next == 0)
		{
			if ((inside && !(current & 1) || (outside && current < 2) || common))
				answer = 1;
			if (inside && outside && current == 0)
				answer = 0;
		}
		else if ((next == 1 && outside && current < 2) || (next == 2 && inside && !(current & 1)))
			answer = 1;

		return answer;
	}

	answer = 2 + dfs(index + 1, 0, index ? next : 0);
	if (inside && !(current & 1))
		answer = min(answer, 1 + dfs(index + 1, 1, index ? next : 1));
	if (outside && current < 2)
		answer = min(answer, 1 + dfs(index + 1, 2, index ? next : 2));
	if (inside && outside && current == 0)
		answer = min(answer, dfs(index + 1, 3, index ? next : 3));
	if (common)
		answer = min(answer, 1 + dfs(index + 1, 3, index ? next : 0));

	return answer;
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
		cin >> N >> W;

		for (int i = 0; i < N; i++)
			cin >> arr[i][0];
		for (int i = 0; i < N; i++)
			cin >> arr[i][1];
		cout << dfs(0, 0, 0) << "\n";
	}

	return 0;
}
