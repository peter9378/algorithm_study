/**
*	BOJ
*	No.15486	퇴사2
*	@author	peter9378
*	@date		2019.09.05
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int day[1500005];
int money[1500005];
int dp[1500005];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> day[i] >> money[i];

	// dp
	int answer = 0;
	for (int i = 0; i <= N; i++)
	{
		answer = max(answer, dp[i]);
		if (i + day[i] > N)
			continue;
		dp[i + day[i]] = max(answer + money[i], dp[i + day[i]]);
	}

	// print answer
	cout << answer;

	return 0;
}