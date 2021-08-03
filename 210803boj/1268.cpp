/**
*	BOJ
*	No.1072	∞‘¿”
*	@author	peter9378
*	@date		2021.08.01
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

int arr[1005][5];
int dp[1005][1005];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 5; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < N; i++)
	{
		int maxi;
		int mini;
		int temp = 0;
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (arr[i][j] == arr[k][j])
					temp += !dp[i][k], dp[i][k] = 1;
			}
		}

		if (maxi < temp)
		{
			maxi = temp;
			mini = i;
		}
	}

	cout << c + 1 << endl;
	return 0;
}
