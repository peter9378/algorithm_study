/**
*	BOJ
*	No.1051	숫자 정사각형
*	@author	peter9378
*	@date		2020.01.12
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

int arr[55][55];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < M; j++)
			arr[i][j] = (s[j] - '0');
	}

	int mini = min(N, M), answer = 0;
	for (int length = 1; length <= mini; length++)
	{
		for (int i = 0; i <= N - length; i++)
		{
			for (int j = 0; j <= M - length; j++)
			{
				if (arr[i][j] == arr[i][j + length - 1] && arr[i][j] == arr[i + length - 1][j] && arr[i][j] == arr[i + length - 1][j + length - 1])
					answer = max(answer, length*length);
			}
		}
	}

	cout << answer;

	return 0;
}
