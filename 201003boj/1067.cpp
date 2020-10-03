/**
*	BOJ
*	No.1067	¿Ãµø
*	@author	peter9378
*	@date		2020.10.03
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

#define pi acos(-1)

void fft(vector<complex<double>> &f, complex<double> w)
{
	int n = f.size();
	if (n == 1)
		return;

	vector<complex<double>> even(n >> 1), odd(n >> 1);
	for (int i = 0; i < n; i++)
	{
		if (i & 1)
			odd[i >> 1] = f[i];
		else
			even[i >> 1] = f[i];
	}

	fft(even, w*w);
	fft(odd, w*w);

	complex<double> c(1, 0);
	for (int i = 0; i < n / 2; i++)
	{
		f[i] = even[i] + c * odd[i];
		f[i + n / 2] = even[i] - c * odd[i];
		c *= w;
	}

	return;
}

vector<complex<double>> mul(vector<complex<double>> a, vector<complex<double>> b)
{
	int n = 1;
	while (n <= a.size() || n <= b.size())
		n <<= 1;
	n <<= 1;

	a.resize(n);
	b.resize(n);
	vector<complex<double>> c(n);
	complex<double> w(cos(2 * pi / n), sin(2 * pi / n));

	fft(a, w);
	fft(b, w);

	for (int i = 0; i < n; i++)
		c[i] = a[i] * b[i];
	fft(c, complex<double>(1, 0) / w);

	for (int i = 0; i < n; i++)
	{
		c[i] /= complex<double>(n, 0);
		c[i] = complex<double>(round(c[i].real()), round(c[i].imag()));
	}

	return c;
}

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> A(2 * N), B(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];

	for (int i = N - 1; i >= 0; i--)
		cin >> B[i];

	for (int i = 0; i < N; i++)
		A[N + i] = A[i];

	vector<complex<double>> a, b;
	for (auto i : A)
		a.push_back(complex<double>(i, 0));
	for (auto i : B)
		b.push_back(complex<double>(i, 0));

	vector<complex<double>> c = mul(a, b);
	long long answer = 0;
	for (int i = 0; i < c.size(); i++)
		answer = max<long long>(answer, round(c[i].real()));

	cout << answer;

	return 0;
}