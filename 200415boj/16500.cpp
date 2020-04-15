/**
*	BOJ
*	No.16500	문자열 판별
*	@author	peter9378
*	@date		2020.04.15
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
#include <iterator>
#include <numeric>
using namespace std;

string arr[101];
int dp[101];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	int N;
	cin >> s >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	dp[s.length()] = 1;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		for (int j = 0; j <= N; j++)
		{
			if (s.find(arr[j], i) == i && dp[i + arr[j].length()] == 1)
			{
				dp[i] = 1;
				break;
			}
			else
				dp[i] = 0;
		}
	}

	cout << dp[0];

	return 0;
}