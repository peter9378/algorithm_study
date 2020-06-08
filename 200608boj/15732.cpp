/**
*	BOJ
*	No.15732	도토리 숨기기
*	@author	peter9378
*	@date		2020.06.08
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

int N, K, D;
pair<int, pair<int, int>> arr[10001];

bool check(int target)
{
	long long result = 0;
	for (int i = 0; i < K; i++)
	{
		int right = min(arr[i].second.first, target);
		if (arr[i].first <= right)
			result += ((right - arr[i].first) / arr[i].second.second + 1);
	}

	return result >= D;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K >> D;

	for (int i = 0; i < K; i++)
		cin >> arr[i].first >> arr[i].second.first >> arr[i].second.second;

	int left = 0, right = N, answer = 0;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (check(mid))
		{
			answer = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	cout << answer;

	return 0;
}