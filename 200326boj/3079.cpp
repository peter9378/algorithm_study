/**
*	BOJ
*	No.3079	입국심사
*	@author	peter9378
*	@date		2020.03.26
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

long long arr[100001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	long long maxi = -1;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		maxi = max(maxi, arr[i]);
	}

	long long left = 0, right = maxi * M;
	long long mid, sum, answer = right;
	while (left <= right)
	{
		mid = (left + right) / 2;
		sum = 0;

		for (int i = 0; i < N; i++)
			sum += (mid / arr[i]);

		if (sum >= M)
		{
			right = mid - 1;
			answer = min(answer, mid);
		}
		else
			left = mid + 1;
	}

	cout << answer;

	return 0;
}