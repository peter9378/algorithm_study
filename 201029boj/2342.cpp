/**
*	BOJ
*	No.2342	Dance Dance Revolution
*	@author	peter9378
*	@date		2020.10.29
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
#include <complex>
using namespace std;

int arr[100001];
int dp[5][5][100001];
int len;

int go(int left, int right, int target)
{
	if (target == len)
		return 0;

	int& ref = dp[left][right][target];
	if (ref != -1)
		return ref;

	if (left == 0 && right == 0)
		return ref = go(arr[target], right, target + 1) + 2;

	if (left == arr[target])
		return ref = go(left, right, target + 1) + 1;
	else if (right == arr[target])
		return ref = go(left, right, target + 1) + 1;

	int temp = 0;
	if (left == 0)
		temp = go(arr[target], right, target + 1) + 2;
	else if (abs(left - arr[target]) == 2)
		temp = go(arr[target], right, target + 1) + 4;
	else
		temp = go(arr[target], right, target + 1) + 3;

	int tempp = 0;
	if (right == 0)
		tempp = go(left, arr[target], target + 1) + 2;
	else if (abs(right - arr[target]) == 2)
		tempp = go(left, arr[target], target + 1) + 4;
	else
		tempp = go(left, arr[target], target + 1) + 3;

	return ref = min(temp, tempp);
}

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		int temp;
		cin >> temp;

		if (temp)
			arr[len++] = temp;
		else
			break;
	}

	memset(dp, -1, sizeof(dp));
	cout << go(0, 0, 0);

	return 0;
}