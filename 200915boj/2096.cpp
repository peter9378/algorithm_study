/**
*	BOJ
*	No.2096	내려가기
*	@author	peter9378
*	@date		2020.09.15
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

int dp[3];
int dpmin[3];

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < 3; i++)
	{
		cin >> dp[i];
		dpmin[i] = dp[i];
	}

	for (int i = 1; i < N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		int temp = dp[0];
		int temptemp = dp[2];
		dp[0] = max(dp[0], dp[1]) + a;
		dp[2] = max(dp[1], dp[2]) + c;
		dp[1] = max(max(temp, dp[1]), temptemp) + b;
		temp = dpmin[0]; temptemp = dpmin[2];
		dpmin[0] = min(dpmin[0], dpmin[1]) + a;
		dpmin[2] = min(dpmin[1], dpmin[2]) + c;
		dpmin[1] = min(min(temp, dpmin[1]), temptemp) + b;
	}

	cout << max(dp[0], max(dp[1], dp[2])) << " " << min(dpmin[0], min(dpmin[1], dpmin[2]));

	return 0;
}