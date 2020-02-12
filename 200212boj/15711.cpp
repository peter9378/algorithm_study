/**
*	BOJ
*	No.15711	È¯»óÀÇ Â¦²á
*	@author	peter9378
*	@date		2020.02.12
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

vector<long long> v;
bool check[2000002];

bool isPrime(long long n)
{
	for (int i = 0; i < v.size() && v[i] * v[i] <= n; i++)
	{
		if (n%v[i] == 0)
			return false;
	}
	return true;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	check[1] = true;
	for (int i = 2; i*i < 2000002; i++)
	{
		if (!check[i])
		{
			for (int j = i * i; j < 2000002; j += i)
				check[j] = true;
		}
	}

	for (int i = 2; i < 2000002; i++)
	{
		if (!check[i])
			v.push_back(i);
	}

	while (T--)
	{
		long long A, B;
		cin >> A >> B;

		A += B;
		if (A < 4)
		{
			cout << "NO\n";
			continue;
		}

		if (A % 2)
			A -= 2;
		else
		{
			cout << "YES\n";
			continue;
		}

		if (isPrime(A))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
