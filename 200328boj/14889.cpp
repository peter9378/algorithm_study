/**
*	BOJ
*	No.14889	스타트와 링크
*	@author	peter9378
*	@date		2020.03.28
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

int N, answer = 1000000000;
int arr[22][22];
bool visit[22];

// dfs
void dfs(int count, int index)
{
	if (count == N / 2)
	{
		int start, link;
		start = link = 0;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (visit[i] && visit[j])
					start += arr[i][j];
				if (!visit[i] && !visit[j])
					link += arr[i][j];
			}
		}
		int tmp = abs(start - link);
		if (tmp < answer)
			answer = tmp;
		return;
	}

	for (int i = index; i < N; i++)
	{
		visit[i] = true;
		dfs(count + 1, i + 1);
		visit[i] = false;
	}
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	}

	dfs(0, 1);

	// print answer
	cout << answer;

	return 0;
}