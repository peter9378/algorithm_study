/**
*	BOJ
*	No.8235	Prefixuffix
*	@author	peter9378
*	@date		2021.05.19
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

#define mod 993244853
#define p 917

struct H {
	vector<long long> a, b;
	H() { }
	H(string &s) {
		int n = s.size();
		a.resize(n + 1); b.resize(n + 1);
		b[0] = 1, b[1] = p;
		for (int i = n - 1; i >= 0; i--) a[i] = (a[i + 1] * p + s[i]) % mod;
		for (int i = 2; i <= n; i++) b[i] = b[i - 1] * p % mod;
	}

	int substr(int from, int to)
	{
		long long result = a[from] - a[to + 1] * b[to - from + 1];
		result %= mod;
		result += mod;
		result %= mod;
		return result;
	}
}h;

inline int same(int from, int to, int next_from, int next_to) {
	return h.substr(from, to) == h.substr(next_from, next_to);
}


// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; string s;
	cin >> n >> s;

	s = "!" + s;
	h = H(s);

	int answer = 0;
	for (int i = n / 2, j = 0; i; i--)
	{
		j = min(n / 2 - i, j + 2);
		if (same(1, i, n - i + 1, n))
		{
			answer = max(answer, i);
			while (j >= 0 && !same(i + 1, i + j, n - i + 1 - j, n - i))
				j--;
			answer = max(answer, i + j);
		}
	}
	cout << answer;

	return 0;
}
