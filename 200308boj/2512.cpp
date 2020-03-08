/**
*	BOJ
*	No.2512	¿¹»ê
*	@author	peter9378
*	@date		2020.03.07
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

int arr[10001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int right = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		right = max(right, arr[i]);
	}

	int M;
	cin >> M;

	int left = 0;
	int mid = (left + right) / 2;
	int sum = 0;
	while (left <= right)
	{
		sum = 0;
		for (int i = 0; i < N; i++)
			sum += arr[i] > mid ? mid : arr[i];

		if (sum == M)
			break;
		else if (sum > M)
			right = mid - 1;
		else
			left = mid + 1;
		mid = (left + right) / 2;
	}

	cout << mid;

	return 0;
}
