/**
*	BOJ
*	No.2673	교차하지 않는 원의 현들의 최대집합
*	@author	peter9378
*	@date		2020.09.07
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
using namespace std;

int arr[101][101];
int dp[101][101];

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = arr[b][a] = 1;
	}

	for (int i = 1; i <= 100; i++)
	{
		for (int j = i - 1; j > 0; j--)
		{
			int temp = 0;
			for (int k = j; k <= i; k++)
				temp = max(temp, dp[j][k - 1] + dp[k + 1][i - 1] + arr[k][i]);
			dp[j][i] = temp;
		}
	}

	cout << dp[1][100];

	return 0;
}