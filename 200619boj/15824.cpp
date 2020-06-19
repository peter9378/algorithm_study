/**
*	BOJ
*	No.15824	너 봄에는 캡사이신이 맛있단다
*	@author	peter9378
*	@date		2020.06.19
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

#define MOD 1000000007

long long arr[300003];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<long long> v(N + 1);
	for (int i = 1; i <= N; i++)
		cin >> v[i];

	sort(v.begin() + 1, v.end());
	arr[0] = 1;
	for (int i = 1; i <= N; i++)
		arr[i] = (arr[i - 1] * 2) % MOD;

	long long answer = 0;
	for (int i = 1; i <= N; i++)
		answer = (answer + (arr[i - 1] - arr[N - i])*v[i]) % MOD;

	cout << (answer < 0 ? answer + MOD : answer);

	return 0;
}
