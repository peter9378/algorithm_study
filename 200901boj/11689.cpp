/**
*	BOJ
*	No.11689	GCD(n, k) = 1
*	@author	peter9378
*	@date		2020.09.01
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

vector<long long> prime, arr;
int check[1000001];
unordered_set<long long> s;

void init()
{
	for (int i = 2; i <= 1000000; i++)
	{
		if (check[i])
			continue;
		prime.push_back(i);

		for (int j = 2 * i; j <= 1000000; j += i)
			check[j] = true;
	}
}

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;
	cin >> n;

	init();
	long long m = n;
	while (true)
	{
		bool flag = true;
		for (auto i : prime)
		{
			if (n%i == 0)
			{
				flag = false;
				s.insert(i);
				n /= i;
			}
		}
		if (flag)
			break;
	}

	if (n != 1)
		s.insert(n);

	for (auto i : s)
		arr.push_back(i);

	long long answer = 0;
	int k = arr.size();
	for (int i = 1; i < (1 << k); i++)
	{
		long long current = 1, temp = 0;
		for (int j = 0; j < k; j++)
		{
			if (i &(1 << j))
			{
				current *= arr[j];
				temp++;
			}
		}

		if (temp & 1)
			answer += (m / current);
		else
			answer -= (m / current);
	}

	cout << (m - answer);

	return 0;
}