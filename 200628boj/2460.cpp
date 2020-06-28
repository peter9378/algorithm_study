/**
*	BOJ
*	No.17401	일하는 세포
*	@author	peter9378
*	@date		2020.06.27
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

#define MOD 1000000007;

typedef vector<vector<long long>> mat;

mat operator * (const mat& a, const mat& b)
{
	int len = a.size();
	mat result(len);
	for (int i = 0; i < len; i++)
		result[i].resize(len);

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			for (int k = 0; k < len; k++)
				result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
		}
	}
	return result;
}

mat pow(mat a, int b)
{
	int len = a.size();
	mat result(len);
	for (int i = 0; i < len; i++)
		result[i].resize(len);

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
			result[i][j] = i == j;
	}

	while (b)
	{
		if (b % 2)
			result = result * a;
		a = a * a;
		b >>= 1;
	}
	return result;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n, d;
	cin >> t >> n >> d;

	vector<mat> arr(t);
	for (int i = 0; i < t; i++)
	{
		arr[i].resize(n);
		for (int j = 0; j < n; j++)
			arr[i][j].resize(n);
	}

	for (int i = 0; i < t; i++)
	{
		int temp;
		cin >> temp;
		for (int j = 0; j < temp; j++)
		{
			int x, y;
			long long z;
			cin >> x >> y >> z;
			x--;
			y--;
			arr[i][x][y] = z;
		}
	}

	mat answer(n);
	mat dp(n);
	for (int i = 0; i < n; i++)
	{
		answer[i].resize(n);
		dp[i].resize(n);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			answer[i][j] = i == j;
			dp[i][j] = i == j;
		}
	}

	for (int i = 0; i < t; i++)
		dp = dp * arr[i];

	answer = answer * pow(dp, d / t);
	for (int i = 0; i < d%t; i++)
		answer = answer * arr[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << answer[i][j] << " ";
		cout << "\n";
	}

	return 0;
}
