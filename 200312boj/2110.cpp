/**
*	BOJ
*	No.2110	공유기 설치
*	@author	peter9378
*	@date		2020.03.12
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

int N, C;
int arr[200002];

bool check(int dist)
{
	int counting = 1;
	int pre = arr[0];
	for (int i = 1; i < N; i++)
	{
		if (dist + pre <= arr[i])
		{
			counting++;
			pre = arr[i];
		}
	}
	if (counting <= C)
		return true;
	return false;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> C;

	sort(arr, arr + N);
	int left = 1, right = arr[N - 1] - arr[0], answer = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (check(mid))
		{
			answer = max(answer, mid);
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << answer;

	return 0;
}
