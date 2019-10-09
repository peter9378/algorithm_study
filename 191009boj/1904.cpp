/**
*	BOJ
*	No.1904	01≈∏¿œ
*	@author	peter9378
*	@date		2019.10.09
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <bitset>

using namespace std;

#define MOD 15746

int arr[1000001];

int fibo(int n)
{
	if (arr[n])
		return arr[n];
	return arr[n] = (fibo(n - 1) + fibo(n - 2)) % MOD;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	arr[0] = arr[1] = 1;
	arr[2] = 2;
	cout << fibo(N);

	return 0;
}