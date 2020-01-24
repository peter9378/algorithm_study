/**
*	BOJ
*	No.1965	상자넣기
*	@author	peter9378
*	@date		2020.01.24
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

int arr[1001];
int dp[1001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;

		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}

		answer = max(answer, dp[i]);
	}

	cout << answer;

	return 0;
}
