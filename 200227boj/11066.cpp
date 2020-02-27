/**
*	BOJ
*	No.11066	파일 합치기
*	@author	peter9378
*	@date		2020.02.27
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

int arr[505];
int sum[505];
int dp[505][505];
int dpp[505][505];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;

		for (int i = 1; i <= N; i++)
		{
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];
		}

		for (int i = 1; i <= N; i++)
			dp[i - 1][i] = i;

		for (int k = 2; k <= N; k++)
		{
			for (int i = 0; i <= N - k; i++)
			{
				int j = i + k;
				dpp[i][j] = 987654321;
				for (int a = dp[i][j - 1]; a <= dp[i + 1][j]; a++)
				{
					int temp = dpp[i][a] + dpp[a][j] + sum[j] - sum[i];
					if (dpp[i][j] > temp)
					{
						dpp[i][j] = temp;
						dp[i][j] = a;
					}
				}
			}
		}
		cout << dpp[0][N] << "\n";
	}

	return 0;
}