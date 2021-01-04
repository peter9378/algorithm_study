/**
*	BOJ
*	No.7579	¾Û
*	@author	peter9378
*	@date		2021.01.04
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

int memory[101];
int cost[101];
int dp[10001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> memory[i];

	int total = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> cost[i];
		total += cost[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = total; j >= cost[i]; j--)
			dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]);
	}

	int answer = 0;
	for (answer = 0; answer < total, dp[answer] < M; answer++);
	cout << answer << "\n";

	return 0;
}
