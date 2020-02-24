/**
*	BOJ
*	No.2563	»öÁ¾ÀÌ
*	@author	peter9378
*	@date		2020.02.24
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
using namespace std;

bool arr[101][101];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;

		for (int j = a; j < a + 10; j++)
		{
			for (int k = b; k < b + 10; k++)
				arr[j][k] = true;
		}
	}

	int answer = 0;
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
			answer += arr[i][j];
	}

	cout << answer;

	return 0;
}
