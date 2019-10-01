/**
*	BOJ
*	No.6064	카잉 달력
*	@author	peter9378
*	@date		2019.10.01
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int gcd(int a, int b)
{
	int temp;
	if (a < b)
	{
		temp = a;
		a = b;
		b = temp;
	}

	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		int maxi = (M*N) / gcd(M, N);
		while (x <= maxi & ((x - 1) % N) + 1 != y)
			x += M;
		if (x > maxi)
			cout << -1 << "\n";
		else
			cout << x << "\n";
	}

	return 0;
}