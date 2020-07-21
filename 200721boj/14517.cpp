/**
*	BOJ
*	No.14517	팰린드롬 개수 구하기 (Large)
*	@author	peter9378
*	@date		2020.07.21
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

#define MOD 10007

int arr[1001][1001];
int dp[1001][1001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int N = s.length();
	int answer = N;
	s = "*" + s;

	for (int i = 1; i < N; i++)
	{
		for (int j = N; i + 1 <= j; j--)
		{
			if (s[i] == s[j])
				dp[i][j] = (arr[i - 1][j + 1] + 1) % MOD;
			arr[i][j] = (arr[i][j + 1] + arr[i - 1][j] + dp[i][j] + MOD - arr[i - 1][j + 1]) % MOD;
			answer = (dp[i][j] * (j - i) + answer + MOD) % MOD;
		}
	}

	cout << answer % MOD;

	return 0;
}