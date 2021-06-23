/**
*	BOJ
*	No.3090	차이를 최소로
*	@author	peter9378
*	@date		2021.06.23
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

#define MAX 100001

int arr[MAX], temp[MAX];
int N, T;

bool check(int target)
{
	int answer = 0;
	for (int i = 0; i < N; i++)
		arr[i] = temp[i];

	for (int i = 0; i < N - 1; i++)
	{
		if (temp[i + 1] > temp[i] + target)
		{
			answer += temp[i + 1] - temp[i] - target;
			temp[i + 1] = temp[i] + target;
		}
	}

	for (int i = N - 1; i > 0; i--)
	{
		if (temp[i - 1] > temp[i] + target)
		{
			answer += temp[i - 1] - temp[i] - target;
			temp[i - 1] = temp[i] + target;
		}
	}

	return answer <= T;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < MAX; i++)
		arr[i] = temp[i] = 0;

	cin >> N >> T;

	for (int i = 0; i < N; i++)
		cin >> temp[i];

	int low = 0, mid, high = 1e9;
	while (low < high)
	{
		mid = (low + high) / 2;

		if (check(mid))
			high = mid;
		else
			low = mid + 1;
	}

	cout << arr[0];
	for (int i = 1; i < N; i++)
		cout << " " << arr[i];

	return 0;
}
