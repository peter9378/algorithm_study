/**
*	BOJ
*	No.10971	외판원 순회 2
*	@author	peter9378
*	@date		2020.04.05
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

int N, answer = 987654321, counting = 0;
int arr[11][11];
bool visit[11];

void dfs(int from, int to, int sum)
{
	if (counting == N && from == to)
	{
		answer = min(answer, sum);
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (visit[i] == false && arr[to][i] != 0)
		{
			visit[i] = true;
			sum += arr[to][i];
			counting++;

			dfs(from, i, sum);
			visit[i] = false;
			sum -= arr[to][i];
			counting--;
		}
	}
	return;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < N; i++)
		dfs(i, i, 0);

	cout << answer;

	return 0;
}