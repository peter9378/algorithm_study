/**
*	BOJ
*	No.2805	나무 자르기
*	@author	peter9378
*	@date		2020.01.06
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

long long arr[1000001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long N, M, answer = 0, temp = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (temp < arr[i])
			temp = arr[i];
	}

	long long left = 0, right = temp;
	while (left <= right)
	{
		long long mid = left + (right - left) / 2;
		long long sum = 0;
		for (int i = 0; i < N; i++)
		{
			if (mid < arr[i])
				sum += arr[i] - mid;
		}

		if (sum >= M)
		{
			if (answer < mid)
				answer = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << answer;

	return 0;
}