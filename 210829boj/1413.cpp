/**
*	BOJ
*	No.1413	박스 안의 열쇠
*	@author	peter9378
*	@date		2021.08.29
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

long long gcd(long long a, long long b)
{
	return b ? gcd(b, a % b) : a;
}

long long dfs(int a, int b)
{
	if (b == 0)
		return 1;
	if (a == 0)
		return 0;
	return (b - 1) * dfs(a, b - 1) + dfs(a - 1, b - 1);
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	long long A = dfs(M, N);
	long long B = 1;

	for (int i = 2; i < N + 1; i++)
		B *= i;

	long long temp = gcd(A, B);
	cout << A / temp << "/" << B / temp;

	return 0;
}