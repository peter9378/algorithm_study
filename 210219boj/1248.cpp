/**
*	BOJ
*	No.1248	¸ÂÃçºÁ
*	@author	peter9378
*	@date		2021.02.19
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

int N;
char arr[11][11];
int answer[11], sum[11];
bool flag = false;

bool check(int target)
{
	for (int i = 1; i < target; i++)
	{
		if (arr[i][target] == '+' && sum[target] <= sum[i - 1])
			return false;
		if (arr[i][target] == '-' && sum[target] >= sum[i - 1])
			return false;
		if (arr[i][target] == '0' && sum[target] != sum[i - 1])
			return false;
	}

	return true;
}

void dfs(int target)
{
	if (flag)
		return;

	if (target > N)
	{
		flag = true;
		for (int i = 1; i <= N; i++)
			cout << answer[i] << " ";

		return;
	}

	if (arr[target][target] == '0')
	{
		answer[target] = 0;
		sum[target] = sum[target - 1];
		dfs(target + 1);
	}
	else
	{
		int temp = 1;
		if (arr[target][target] == '-')
			temp = -1;

		for (int i = 1; i <= 10; i++)
		{
			answer[target] = i * temp;
			sum[target] = sum[target - 1] + answer[target];

			if (check(target))
				dfs(target + 1);
		}
	}
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int j = 1; j <= N; j++)
	{
		for (int i = j; i <= N; i++)
			cin >> arr[j][i];
	}

	dfs(1);

	return 0;
}
