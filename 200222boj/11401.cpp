/**
*	BOJ
*	No.11401	이항 계수 3
*	@author	peter9378
*	@date		2020.02.22
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

const int MOD = 1000000007;
long long arr[4000000];
long long nxt, pre;

void euc(long long mod, long long target)
{
	long temp;
	if (mod%target > 0)
	{
		euc(target, mod%target);
		temp = nxt;
		nxt = pre - (mod / target)*nxt;
		pre = temp;
	}
	else
	{
		nxt = 1;
		pre = 0;
	}
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	arr[0] = arr[1] = 1;
	for (int i = 2; i <= N; i++)
		arr[i] = (arr[i - 1] * i) % MOD;

	long long target = (arr[K] * arr[N - K]) % MOD;

	euc(MOD, target);
	long long answer = ((arr[N] % MOD)*nxt%MOD) % MOD;
	if (answer < 0)
		answer += MOD;
	cout << answer;

	return 0;
}
