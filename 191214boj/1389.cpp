/**
*	BOJ
*	No.1389	케빈 베이컨의 6단계 법칙
*	@author	peter9378
*	@date		2019.12.14
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

int arr[101][101];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = arr[b][a] = 1;
	}

	for (int a = 1; a <= N; a++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (i == j)
					continue;
				if (arr[i][a] && arr[a][j])
					arr[i][j] = arr[i][j] ? min(arr[i][j], arr[i][a] + arr[a][j]) : arr[i][a] + arr[a][j];
			}
		}
	}

	int temp = 987654321;
	int answer;
	for (int i = 1; i <= N; i++)
	{
		int sum = 0;
		for (int j = 1; j <= N; j++)
			sum += arr[i][j];
		if (temp > sum)
		{
			temp = sum;
			answer = i;
		}
	}

	cout << answer;

	return 0;
}
