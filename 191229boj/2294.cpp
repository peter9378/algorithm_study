/**
*	BOJ
*	No.2294	µ¿Àü 2
*	@author	peter9378
*	@date		2019.12.29
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

int coin[101];
int dp[100001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> coin[i];

	for (int i = 1; i <= K; i++)
		dp[i] = 100001;

	for (int i = 0; i < N; i++)
	{
		for (int j = coin[i]; j <= K; j++)
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
	}

	if (dp[K] == 100001)
		cout << "-1";
	else
		cout << dp[K];

	return 0;
}
