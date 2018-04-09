/**
*	baekjoon_stepbystep
*	No. 9251 LCS
*	@author	peter9378
*	@date		2018.04.10
*/
#include <iostream>
#include <string>
using namespace std;

// dp 배열
int dp[1001][1001];

// max 함수 구현
int max(int a, int b)
{
	return a > b ? a : b;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 두 문자열 입력
	string a, b;
	cin >> a >> b;

	// LCS(Longest Common Sequence)적용
	for (int i = 0; i < a.length(); i++)
	{
		for (int j = 0; j < b.length(); j++)
		{
			if (a[i] == b[j])
				dp[i + 1][j + 1] = dp[i][j] + 1;
			else
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
		}
	}

	// 출력
	cout << dp[a.length()][b.length()];

	return 0;
}