/**
*	BOJ
*	No.2631	줄세우기
*	@author	peter9378
*	@date		2020.05.18
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

int arr[202];
int dp[202];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
				temp = max(temp, dp[j]);
		}
		dp[i] = temp + 1;
		answer = max(answer, dp[i]);
	}

	cout << N - answer;

	return 0;
}