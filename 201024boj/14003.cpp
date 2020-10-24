/**
*	BOJ
*	No.14003	가장 긴 증가하는 부분 수열 5
*	@author	peter9378
*	@date		2020.10.24
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

#define MAX 1000001

int N;
int arr[MAX];
int dp[MAX];
pair<int, int> answer[MAX];

int lis()
{
	int index = 0;
	dp[index] = arr[0];
	answer[0] = { 0, arr[0] };

	for (int i = 1; i < N; i++)
	{
		if (dp[index] < arr[i])
		{
			dp[++index] = arr[i];
			answer[i] = { index, arr[i] };
		}
		else
		{
			int temp = lower_bound(dp, dp + index, arr[i]) - dp;
			dp[temp] = arr[i];
			answer[i] = { temp, arr[i] };
		}
	}
	return index + 1;
}

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int result = lis();
	cout << result << "\n";

	stack<int> s;
	int index = result - 1;
	for (int i = N - 1; i >= 0; i--)
	{
		if (answer[i].first == index)
		{
			s.push(answer[i].second);
			index--;
		}
	}

	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}

	return 0;
}