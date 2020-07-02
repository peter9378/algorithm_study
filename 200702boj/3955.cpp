/**
*	BOJ
*	No.3955	Äµµð ºÐ¹è
*	@author	peter9378
*	@date		2020.07.02
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

tuple<long long, long long, long long> gcd(long long a, long long b)
{
	if (b == 0)
		return { a, 1, 0 };
	long long g, x, y;
	tie(g, x, y) = gcd(b, a%b);
	return { g, y, x - (a / b)*y };
}

long long cl(long long a, long long b)
{
	if (a >= 0)
		return (a + b - 1) / b;
	return a / b;
}

void go(long long a, long long b)
{
	long long g, x, y;
	tie(g, x, y) = gcd(a, b);

	if (g != 1)
	{
		cout << "IMPOSSIBLE\n";
		return;
	}

	long long z = min(cl(-x, b), cl(y, a)) - 1;
	if (y > a*z + 1000000000)
	{
		cout << "IMPOSSIBLE\n";
		return;
	}

	cout << y - a * z << "\n";
	return;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--)
	{
		long long K, C;
		cin >> K >> C;
		go(K, C);
	}

	return 0;
}
