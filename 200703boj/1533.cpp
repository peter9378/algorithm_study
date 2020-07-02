/**
*	BOJ
*	No.1533	길의 개수
*	@author	peter9378
*	@date		2020.07.03
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

#define MOD 1000003;
typedef vector<vector<long long>> mat;

mat operator * (const mat& a, const mat& b)
{
	int len = a.size();
	mat result(len);
	for (int i = 0; i < len; i++)
		result[i].resize(len);

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			for (int k = 0; k < len; k++)
				result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
		}
	}
	return result;
}

mat pow(mat a, long long b)
{
	if (b == 1)
		return a;

	mat result = pow(a, b / 2);
	result = result * result;
	if (b % 2)
		result = result * a;
	return result;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, S, E, T;
	cin >> N >> S >> E >> T;

	S--;
	E--;
	mat m(5 * N);
	for (int i = 0; i < 5 * N; i++)
		m[i].resize(5 * N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < 5; j++)
			m[i * 5 + j][i * 5 + j - 1] = 1;
	}

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < N; j++)
		{
			int temp = s[j] - '0';

			if (temp == 1)
				m[i * 5][j * 5] = 1;
			else if (temp > 1)
				m[i * 5][j * 5 + temp - 1] = 1;
		}
	}

	mat answer = pow(m, T);
	cout << answer[S * 5][E * 5];

	return 0;
}
