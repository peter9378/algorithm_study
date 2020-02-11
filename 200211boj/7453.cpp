/**
*	BOJ
*	No.7453	합이 0인 네 정수
*	@author	peter9378
*	@date		2020.02.11
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

int a[4444], b[4444], c[4444], d[4444], ab[16000001], cd[16000001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ab[N*i + j] = a[i] + b[j];
			cd[N*i + j] = -(c[i] + d[j]);
		}
	}

	sort(cd, cd + N * N);

	int low, high;
	long long answer = 0;
	for (int i = 0; i < N*N; i++)
	{
		low = lower_bound(begin(cd), begin(cd) + N * N, ab[i]) - begin(cd);
		high = upper_bound(begin(cd), begin(cd) + N * N, ab[i]) - begin(cd);
		answer += (high - low);
	}

	cout << answer;

	return 0;
}
