/**
*	BOJ
*	No.9252	LCS 2
*	@author	peter9378
*	@date		2019.09.13
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int dp[1001][1001];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	cin >> a >> b;

	int** dp = new int*[a.length() + 2];
	for (int i = 0; i < a.length() + 2; i++)
		dp[i] = new int[b.length() + 2];

	for (int i = 0; i < a.length() + 2; i++)
	{
		for (int j = 0; j < b.length() + 2; j++)
			dp[i][j] = 0;
	}


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

	cout << dp[a.length()][b.length()] << "\n";

	int aa = a.length();
	int bb = b.length();

	string answer = "";
	while (aa > 0 && bb > 0)
	{
		if (dp[aa][bb] == dp[aa - 1][bb])
			aa--;
		else if (dp[aa][bb] == dp[aa][bb - 1])
			bb--;
		else
		{
			answer += a[aa - 1];
			aa--;
			bb--;
		}
	}
	reverse(answer.begin(), answer.end());
	cout << answer;

	for (int i = 0; i < a.length(); i++)
		delete[] dp[i];
	delete[] dp;

	return 0;
}