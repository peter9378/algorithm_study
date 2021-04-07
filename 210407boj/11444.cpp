/**
*	BOJ
*	No.11444	피보나치 수 6
*	@author	peter9378
*	@date		2021.04.07
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

typedef vector<vector<long long>> matrix;
#define mod 1000000007


matrix operator * (matrix& a, matrix& b)
{
	matrix result(2, vector<long long>(2));

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
				result[i][j] += a[i][k] * b[k][j];
			result[i][j] %= mod;
		}
	}
	return result;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;
	cin >> n;

	matrix answer = { {1,0}, {0,1} };
	matrix a = { {1,1}, {1,0} };

	while (n > 0)
	{
		if (n % 2 == 1)
			answer = answer * a;
		a = a * a;
		n /= 2;
	}

	cout << answer[0][1];

	return 0;
}
