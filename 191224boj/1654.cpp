/**
*	BOJ
*	No.1654	랜선 자르기
*	@author	peter9378
*	@date		2019.12.24
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

int N, M;
long long arr[10001];

bool check(long long length)
{
	int temp = 0;
	for (int i = 0; i < N; i++)
		temp += arr[i] / length;

	if (temp >= M)
		return true;
	return false;
}


// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	long long big = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		big = max(big, arr[i]);
	}

	long long answer = 0, small = 1;
	while (small <= big)
	{
		long long mid = (small + big) / 2;
		if (check(mid))
		{
			if (answer < mid)
				answer = mid;
			small = mid + 1;
		}
		else
			big = mid - 1;
	}

	cout << answer;

	return 0;
}
