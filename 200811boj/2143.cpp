/**
*	BOJ
*	No.2143	두 배열의 합
*	@author	peter9378
*	@date		2020.08.11
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
using namespace std;

long long arr[1001], arrr[1001];;
unordered_map<long long, long long> m;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long T, N;
	cin >> T >> N;

	for (long long i = 0; i < N; i++)
		cin >> arr[i];

	long long M;
	cin >> M;
	for (long long i = 0; i < M; i++)
		cin >> arrr[i];

	for (long long i = 0; i < N; i++)
	{
		long long temp = 0;
		for (long long j = i; j < N; j++)
		{
			temp += arr[j];
			if (abs(temp) <= 1000000000)
				m[temp]++;
		}
	}

	long long answer = 0;
	for (long long i = 0; i < M; i++)
	{
		long long temp = T;
		for (long long j = i; j < M; j++)
		{
			temp -= arrr[j];
			if (abs(temp) > 1000000000)
				break;
			answer += m[temp];
		}
	}

	cout << answer;

	return 0;
}