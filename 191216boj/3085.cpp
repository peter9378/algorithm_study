/**
*	BOJ
*	No.3085	ªÁ≈¡ ∞‘¿”
*	@author	peter9378
*	@date		2019.12.16
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

int N;
int arr[55][55];

int counting()
{
	int result = 1, temp = 1;
	for (int i = 0; i < N; i++)
	{
		temp = 1;
		for (int j = 1; j < N; j++)
		{
			if (arr[i][j - 1] == arr[i][j])
				temp++;
			else
			{
				result = max(result, temp);
				temp = 1;
			}
		}
		result = max(result, temp);
	}

	for (int i = 0; i < N; i++)
	{
		temp = 1;
		for (int j = 0; j < N - 1; j++)
		{
			if (arr[j + 1][i] == arr[j][i])
				temp++;
			else
			{
				result = max(result, temp);
				temp = 1;
			}
		}
		result = max(result, temp);
	}
	return result;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < N; j++)
		{
			if (s[j] == 'C')
				arr[i][j] = 1;
			else if (s[j] == 'P')
				arr[i][j] = 2;
			else if (s[j] == 'Z')
				arr[i][j] = 3;
			else
				arr[i][j] = 4;
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			swap(arr[i][j], arr[i][j + 1]);
			answer = max(answer, counting());
			swap(arr[i][j], arr[i][j + 1]);
			swap(arr[j][i], arr[j + 1][i]);
			answer = max(answer, counting());
			swap(arr[j][i], arr[j + 1][i]);
		}
	}

	cout << answer;

	return 0;
}
