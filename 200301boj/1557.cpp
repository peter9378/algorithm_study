/**
*	BOJ
*	No.1557	Á¦°ö ¤¤¤¤
*	@author	peter9378
*	@date		2020.03.01	3.1DAY
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

const int MAX = 100001;
int arr[MAX];

long long check(long long N)
{
	long long result = 0;
	for (int i = 1; i*i <= N; i++)
		result += arr[i] * (N / (i*i));
	return result;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K;
	cin >> K;

	for (int i = 0; i < MAX; i++)
		arr[i] = 1;

	for (int i = 2; i*i <= MAX; i++)
	{
		if (arr[i] == 1)
		{
			for (int j = i; j <= MAX; j += i)
				arr[j] *= -i;
			for (int j = i * i; j <= MAX; j += i * i)
				arr[j] = 0;
		}
	}

	for (int i = 2; i <= MAX; i++)
	{
		if (arr[i] == i)
			arr[i] = 1;
		else if (arr[i] == -i)
			arr[i] = -1;
		else if (arr[i] < 0)
			arr[i] = 1;
		else if (arr[i] > 0)
			arr[i] = -1;
	}

	long long left = 1;
	long long right = 2222222222;

	while (left < right)
	{
		long long mid = left + (right - left) / 2;
		long long val = check(mid);

		if (val > K)
			right = mid - 1;
		else if (val == K)
			right = mid;
		else
			left = mid + 1;
	}

	cout << left;

	return 0;
}