/**
*	BOJ
*	No.2098	외판원 순회
*	@author	peter9378
*	@date		2020.10.19
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

int N, target = 0;
int arr[16][16];
int dp[16][66666];

int go(int current, int start)
{
	if (start == target)
	{
		if (arr[current][0] == 0)
			return 987654321;
		return arr[current][0];
	}

	int &result = dp[current][start];
	if (result != 0)
		return result;

	int temp = 987654321;
	for (int i = 0; i < N; i++)
	{
		if (((start&(1 << i)) == 0) && arr[current][i])
			temp = min(temp, go(i, (start | (1 << i))) + arr[current][i]);
	}
	return result = temp;
}

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	target = (1 << N) - 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}

	cout << go(0, 1);

	return 0;
}