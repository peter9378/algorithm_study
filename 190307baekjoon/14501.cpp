/**
*	baekjoon online judge
*	No. 14501	퇴사
*	@author	peter9378
*	@date		2019.03.07
*/
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 55

int day[MAX];
int money[MAX];
int dp[MAX];


// main function
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
	for (int i = 0; i < N; i++)
	{
		// check next day and the day after next day
		int next = i + day[i];
		int nextnext = i + 1;

		if (next < N + 1)
			dp[next] = max(dp[next], dp[i] + money[i]);
		if (nextnext < N + 1)
			dp[nextnext] = max(dp[nextnext], dp[i]);

		// get the biggest value
		answer = max(max(answer, dp[next]), dp[nextnext]);
	}

	// print answer
	cout << answer;
	return 0;
}
