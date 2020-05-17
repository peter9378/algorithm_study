/**
*	BOJ
*	No.2780	비밀번호
*	@author	peter9378
*	@date		2020.05.17
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

#define MOD 1234567

int arr[10][1001];

int near[10][10] = {
		{0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
		{0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
		{0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
		{0, 0, 1, 0, 1, 0, 1, 0, 1, 0},
		{0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
		{0, 0, 0, 0, 0, 0, 1, 0, 1, 0}
};

int check(int index, int length)
{
	int& result = arr[index][length];
	if (result != -1)
		return result;
	result = 0;

	for (int i = 0; i < 10; i++)
	{
		if (near[index][i])
			result += (check(i, length - 1) % MOD);
	}
	return result;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 1001; j++)
				arr[i][j] = -1;
		}

		for (int i = 0; i < 10; i++)
			arr[i][1] = 1;

		long long answer = 0;
		for (int i = 0; i < 10; i++)
		{
			answer += check(i, N);
			answer %= MOD;
		}

		cout << answer << "\n";
	}

	return 0;
}