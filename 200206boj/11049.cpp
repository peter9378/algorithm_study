/**
*	BOJ
*	No.11049	Çà·Ä °ö¼À ¼ø¼­
*	@author	peter9378
*	@date		2020.02.06
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

int arr[555][2];
int dp[555][555];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> arr[i][0] >> arr[i][1];

	for (int i = 1; i < N; i++)
		dp[i][i + 1] = arr[i][0] * arr[i][1] * arr[i + 1][1];

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= N - i; j++)
		{
			int p = j + i;
			for (int k = j; k < p; k++)
			{
				int temp = dp[j][k] + dp[k + 1][p] + arr[j][0] * arr[k][1] * arr[p][1];
				if (!dp[j][p] || dp[j][p] > temp)
					dp[j][p] = temp;
			}
		}
	}

	cout << dp[1][N];

	return 0;
}
