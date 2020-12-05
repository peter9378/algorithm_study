/**
*	BOJ
*	No.17104	°ñµå¹ÙÈå ÆÄÆ¼¼Ç 2
*	@author	peter9378
*	@date		2020.12.05
*/
#define _USE_MATH_DEFINES
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

const int MAX = 1 << 21;

void fft(complex<double> f[], bool flag)
{
	int n = MAX;
	for (int i = 1, j = 0; i < n; i++)
	{
		int temp = n / 2;
		while (!((j ^= temp)&temp))
			temp /= 2;

		if (i < j)
			swap(f[i], f[j]);
	}

	for (int i = 1; i < n; i *= 2)
	{
		double a = (flag ? M_PI / i : -M_PI / i);
		complex<double> w(cos(a), sin(a));
		for (int j = 0; j < n; j += i * 2)
		{
			complex<double> wp(1, 0);
			for (int k = 0; k < i; k++)
			{
				complex<double> x = f[j + k];
				complex<double> y = f[i + j + k] * wp;
				f[j + k] = x + y;
				f[i + j + k] = x - y;
				wp *= w;
			}
		}
	}

	if (flag)
	{
		for (int i = 0; i < n; i++)
			f[i] /= n;
	}
}

void pw(complex<double> f[])
{
	fft(f, false);
	for (int i = 0; i < MAX; i++)
		f[i] *= f[i];
	fft(f, true);
}

bool check[MAX >> 1];
complex<double> f[MAX];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	check[0] = check[1] = true;
	for (long long i = 2; i < 1000000; i++)
	{
		if (check[i])
			continue;
		f[i] = complex<double>(1, 0);

		for (long long j = i * i; j < 1000000; j += i)
			check[j] = true;
	}

	pw(f);

	int t;
	cin >> t;
	while (t--)
	{
		int temp;
		cin >> temp;
		int answer = round(f[temp].real());
		bool flag = !check[temp / 2];
		if (temp / 2 % 2 == 0 && temp / 2 > 2)
			flag = false;
		if (flag)
			answer--;
		cout << answer / 2 + flag << "\n";
	}

	return 0;
}
