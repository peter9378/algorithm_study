/**
*	BOJ
*	No.14490	¹é´ë¿­
*	@author	peter9378
*	@date		2019.11.19
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

long long gcd(long long a, long long b)
{
	long long temp;
	while (b)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int index;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ':')
		{
			index = i;
			break;
		}
	}

	long long n = stoi(s.substr(0, index));
	long long m = stoi(s.substr(index + 1));

	if (n > m)
	{
		long long g = gcd(n, m);
		cout << n / g << ":" << m / g;
	}
	else
	{
		long long g = gcd(m, n);
		cout << n / g << ":" << m / g;
	}

	return 0;
}
