/**
*	BOJ
*	No.2399	거리의 합
*	@author	peter9378
*	@date		2020.01.28
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

int arr[10001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	long long answer = 0;
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
			answer += abs(arr[i] - arr[j]);
	}

	cout << answer * 2;

	return 0;
}
