/**
*	BOJ
*	No.1126	°°Àº Å¾
*	@author	peter9378
*	@date		2020.09.30
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

#define MAX 55

int N;
int arr[MAX];
int dp[MAX][250025];

int dfs(int index, int diff)
{
	if (diff > 250000 || (index == N && diff))
		return -987654321;

	if (index == N && diff == 0)
		return 0;

	int &result = dp[index][diff];
	if (result != -1)
		return result;

	result = max(-987654321, dfs(index + 1, diff));
	result = max(result, dfs(index + 1, diff + arr[index]));

	if (arr[index] > diff)
		result = max(result, diff + dfs(index + 1, arr[index] - diff));
	else
		result = max(result, arr[index] + dfs(index + 1, diff - arr[index]));
	return result;
}

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	memset(dp, -1, sizeof(dp));
	int answer = dfs(0, 0);

	if (answer)
		cout << answer;
	else
		cout << -1;

	return 0;
}