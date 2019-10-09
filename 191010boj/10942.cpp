/**
*	BOJ
*	No.10942	ÆÓ¸°µå·Ò?
*	@author	peter9378
*	@date		2019.10.10
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <bitset>

using namespace std;

int arr[2002];
int dp[2002][2002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++)
		dp[i][i] = 1;

	for (int i = 0; i < N - 1; i++)
	{
		if (arr[i] == arr[i + 1])
			dp[i][i + 1] = 1;
	}

	for (int i = 3; i <= N; i++)
	{
		for (int j = 0; j <= N - i; j++)
		{
			int k = i + j - 1;
			if (arr[j] == arr[k] && dp[j + 1][k - 1])
				dp[j][k] = 1;
		}
	}

	int M;
	cin >> M;

	while (M--)
	{
		int a, b;
		cin >> a >> b;
		cout << dp[a - 1][b - 1] << "\n";
	}


	return 0;
}