/**
*	BOJ
*	No.1086	¹Ú¼º¿ø
*	@author	peter9378
*	@date		2019.12.25 - Merry Christmas
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

int N, K;
int arr[15];
int len[15];
int dp[52];
string arrstring[15];
long long counting[1 << 15][101];

long long gcd(long long a, long long b)
{
	return b ? gcd(b, a%b) : a;
}

long long factorial(int N)
{
	long long val = 1;
	while (N)
		val *= (N--);
	return val;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arrstring[i];

	cin >> K;
	dp[0] = 1;
	for (int i = 1; i < 52; i++)
		dp[i] = (dp[i - 1] * 10) % K;

	for (int i = 0; i < N; i++)
	{
		len[i] = arrstring[i].length();
		for (int j = 0; j < len[i]; j++)
			arr[i] = ((arr[i] * 10) + arrstring[i][j] - '0') % K;
	}

	counting[0][0] = 1;
	for (int bit = 0; bit < (1 << N) - 1; bit++)
	{
		for (int i = 0; i < N; i++)
		{
			if (bit&(1 << i))
				continue;
			for (int j = 0; j < K; j++)
			{
				if (counting[bit][j] == 0)
					continue;
				counting[bit | (1 << i)][(arr[i] + j * dp[len[i]]) % K] += counting[bit][j];
			}
		}
	}

	long long a = counting[(1 << N) - 1][0];
	long long b = factorial(N);
	long long g = gcd(a, b);

	cout << a / g << '/' << b / g;

	return 0;
}
