/**
*	BOJ
*	No.12849	본대 산책
*	@author	peter9378
*	@date		2020.09.21
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

#define N 1000000007

int matrix[64] = {
	0,1,1,0,0,0,0,0,
	1,0,1,1,0,0,0,0,
	1,1,0,1,1,0,0,0,
	0,1,1,0,1,1,0,0,
	0,0,1,1,0,1,0,1,
	0,0,0,1,1,0,1,0,
	0,0,0,0,0,1,0,1,
	0,0,0,0,1,0,1,0
};
int *arr[30] = { matrix, };

int sum(int* m1, int* m2, int a, int b)
{
	long long result = 0;
	for (int i = 0; i < 8; i++)
	{
		result += (long long)m1[8 * a + i] * (long long)m2[b + i * 8];
		result %= N;
	}

	return result;

}

int* mul(int* m1, int* m2)
{
	int *result = new int[64];

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			result[i + j * 8] = sum(m1, m2, j, i);
	}
	return result;
}


// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int D;
	cin >> D;

	for (int i = 0; i < 30; i++)
		arr[i + 1] = mul(arr[i], arr[i]);

	int *answer;
	bool flag = false;
	for (int i = 0; i < 30; i++)
	{
		if (D&(1 << i))
		{
			if (flag)
				answer = mul(answer, arr[i]);
			else
			{
				answer = arr[i];
				flag = true;
			}
		}
	}

	cout << *answer;

	return 0;
}