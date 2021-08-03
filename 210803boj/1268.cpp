/**
*	BOJ
*	No.1268	임시 반장 정하기
*	@author	peter9378
*	@date		2021.08.03
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

int arr[1001][5];
bool check[1001][1001];

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

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				if (arr[j][i] == arr[k][i])
					check[j][k] = check[k][j] = true;
			}
		}
	}

	int answer = -1;
	int temp = -1;
	for (int i = 0; i < N; i++)
	{
		int current = 0;
		for (int j = 0; j < N; j++)
		{
			if (check[i][j])
				current++;
		}

		if (temp < current)
		{
			answer = i + 1;
			temp = current;
		}
	}

	cout << answer;

	return 0;
}
