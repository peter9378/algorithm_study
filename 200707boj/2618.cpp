/**
*	BOJ
*	No.2548	대표 자연수
*	@author	peter9378
*	@date		2020.07.06
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

int N, W;
pair<int, int> arr[1001];
int dp[1001][1001];
int answer[1001];

int dist(pair<int, int> a, pair<int, int> b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int dfs(int a, int b)
{
	if (a == W || b == W)
		return 0;

	int &result = dp[a][b];

	if (result != -1)
		return result;
	int first, second;

	if (a)
		first = dfs(max(a, b) + 1, b) + dist(arr[max(a, b) + 1], arr[a]);
	else
		first = dfs(max(a, b) + 1, b) + dist(arr[max(a, b) + 1], { 1, 1 });
	if (b)
		second = dfs(a, max(a, b) + 1) + dist(arr[max(a, b) + 1], arr[b]);
	else
		second = dfs(a, max(a, b) + 1) + dist(arr[max(a, b) + 1], { N, N });

	return result = min(first, second);
}

void go(int a, int b)
{
	if (a == W || b == W)
		return;

	int first, second;
	if (a)
		first = dfs(max(a, b) + 1, b) + dist(arr[max(a, b) + 1], arr[a]);
	else
		first = dfs(max(a, b) + 1, b) + dist(arr[max(a, b) + 1], { 1,1 });
	if (b)
		second = dfs(a, max(a, b) + 1) + dist(arr[max(a, b) + 1], arr[b]);
	else
		second = dfs(a, max(a, b) + 1) + dist(arr[max(a, b) + 1], { N, N });

	if (first < second)
	{
		answer[max(a, b) + 1] = 1;
		go(max(a, b) + 1, b);
	}
	else
	{
		answer[max(a, b) + 1] = 2;
		go(a, max(a, b) + 1);
	}
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp, -1, sizeof(dp));
	cin >> N >> W;

	for (int i = 1; i <= W; i++)
		cin >> arr[i].first >> arr[i].second;

	cout << dfs(0, 0) << "\n";
	go(0, 0);
	for (int i = 1; i <= W; i++)
		cout << answer[i] << "\n";

	return 0;
}