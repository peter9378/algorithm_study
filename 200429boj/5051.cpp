/**
*	BOJ
*	No.2814	최소인수
*	@author	peter9378
*	@date		2020.04.29
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
#include <cstring>
#include <iterator>
#include <numeric>
#include <complex>
using namespace std;

typedef complex<double> base;

vector<long long> arr;

void fft(vector<base> &a, bool check)
{
	int n = a.size();
	for (int i = 1, j = 0; i < n; i++)
	{
		int bit = n >> 1;
		for (; j >= bit; bit >>= 1)
			j -= bit;
		j += bit;

		if (i < j)
			swap(a[i], a[j]);
	}
	for (int len = 2; len <= n; len <<= 1)
	{
		double ang = 2 * M_PI / len * (check ? -1 : 1);
		base temp(cos(ang), sin(ang));

		for (int i = 0; i < n; i += len)
		{
			base b(1);
			for (int j = 0; j < len / 2; j++)
			{
				base u = a[i + j], v = a[i + j + len / 2] * b;
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
				b *= temp;
			}
		}
	}

	if (check)
	{
		for (int i = 0; i < n; i++)
			a[i] /= n;
	}
}

void calc(const vector<long long> &a, const vector<long long> &b, vector<long long> &result)
{
	vector<base> va(a.begin(), a.end());
	vector<base> vb(b.begin(), b.end());

	int n = 1;
	while (n < max(a.size(), b.size()))
		n <<= 1;

	va.resize(n);
	vb.resize(n);

	fft(va, false);
	fft(vb, false);

	for (int i = 0; i < n; i++) va[i] *= vb[i];
	fft(va, true);
	result.resize(n);

	for (int i = 0; i < n; i++)
		result[i] = (long long)(va[i].real() + (va[i].real() > 0 ? 0.5 : -0.5));

	return;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	arr.resize(2 * N);
	for (long long i = 1; i < N; i++)
		arr[i*i%N]++;

	vector<long long> temp(2 * N);
	for (int i = N; i < 2 * N; i++)
	{
		arr[i] = arr[i - N];
		temp[i - N] = arr[i];
	}
	vector<long long> result;

	calc(arr, temp, result);

	long long answer = 0;
	for (int i = 0; i < N; i++)
	{
		answer += arr[i] * result[i + N];
		answer += arr[i] * arr[2 * i%N];
	}

	cout << answer / 2;

	return 0;
}