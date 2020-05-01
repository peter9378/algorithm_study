/**
*	BOJ
*	No.2482	»ö»óÈ¯
*	@author	peter9378
*	@date		2020.05.01
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

#define MOD 1000000003;

int arr[1001][1001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i <= N; i++)
	{
		arr[i][0] = 1;
		arr[i][1] = i;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 2; j <= K; j++)
			arr[i][j] = (arr[i - 2][j - 1] + arr[i - 1][j]) % MOD;
	}

	cout << (arr[N - 1][K] + arr[N - 3][K - 1]) % MOD;

	return 0;
}