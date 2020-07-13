/**
*	BOJ
*	No.18111	마인크래프트
*	@author	peter9378
*	@date		2020.07.14
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

int arr[505][505];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, B;
	cin >> N >> M >> B;

	int low = 987654321, high = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			low = min(low, arr[i][j]);
			high = max(high, arr[i][j]);
		}
	}

	int cnt = 987654321, answer = 0;
	bool flag = false;
	for (int i = low; i <= high; i++)
	{
		int plus = 0, minus = 0;
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				int temp = i - arr[j][k];
				if (temp >= 0)
					plus += temp;
				else
					minus -= temp;
			}
		}

		if (plus <= minus + B)
		{
			int temp = plus + minus * 2;
			if (cnt > temp)
			{
				cnt = temp;
				answer = i;
			}
			if (cnt == temp)
				answer = max(answer, i);
		}
	}

	cout << cnt << " " << answer;

	return 0;
}