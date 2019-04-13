/**
*	Baekjoon Online Judge
*	No. 2163	초콜릿 자르기
*	@author	peter9378
*	@date		2019.04.13
*/
#include <iostream>
#include <algorithm>
using namespace std;

int dp[301][301];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int N, M;
	cin >> N >> M;

	for (int i = 1; i < 301; i++)
	{
		for (int j = 1; j <= i; j++)
			dp[i][j] = dp[j][i] = i*j - 1;
	}

	cout << dp[N][M];


	return 0;
}