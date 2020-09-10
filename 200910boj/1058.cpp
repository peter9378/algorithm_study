/**
*	BOJ
*	No.1058	Ä£±¸
*	@author	peter9378
*	@date		2020.09.10
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

const int MOD[2] = { 100000007,1000000009 };
const int BASE = 31;

int N;
string S;
long long arr[2], arrr[2];

unordered_set<long long> s;

bool check(int m)
{
	s.clear();
	for (int i = 0; i < 2; i++)
		arr[i] = 1, arrr[i] = S[0];
	for (int i = 1; i < m; ++i)
	{
		for (int j = 0; j < 2; j++)
		{
			arrr[j] = (arrr[j] * BASE + S[i]) % MOD[j];
			arr[j] = arr[j] * BASE % MOD[j];
		}
	}

	s.emplace(arrr[0] << 32 | arrr[1]);
	for (int i = m; i < N; ++i)
	{
		for (int j = 0; j < 2; j++)
		{
			arrr[j] = (arrr[j] - S[i - m] * arr[j] % MOD[j] + MOD[j]) % MOD[j];
			arrr[j] = (arrr[j] * BASE + S[i]) % MOD[j];
		}

		long long temp = arrr[0] << 32 | arrr[1];

		if (s.find(temp) == s.end())
			s.emplace(temp);
		else
			return true;
	}
	return false;
}

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> S;

	int left = 0, right = N, answer;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (check(mid))
		{
			answer = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << answer;

	return 0;
}