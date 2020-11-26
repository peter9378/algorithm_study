/**
*	BOJ
*	No.3273	두 수의 합
*	@author	peter9378
*	@date		2020.11.26
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

int arr[100001];

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);
	int answer = 0, x;
	cin >> x;

	for (int i = 0; i < N; i++)
	{
		int left = 0, right = N - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (arr[mid] == x - arr[i])
			{
				answer++;
				break;
			}
			else if (arr[mid] < x - arr[i])
				left = mid + 1;
			else right = mid - 1;
		}
	}

	cout << answer / 2;

	return 0;
}