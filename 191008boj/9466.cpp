/**
*	BOJ
*	No.9466	ер га╥на╖ф╝
*	@author	peter9378
*	@date		2019.10.08
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <bitset>

using namespace std;

int answer = 0;
int arr[100001];
bool visit[100001];
bool fin[100001];

void init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		visit[i] = false;
		fin[i] = false;
	}
}

void dfs(int target)
{
	visit[target] = true;

	int next = arr[target];
	if (!visit[next])
		dfs(next);
	else if (!fin[next])
	{
		for (int i = next; i != target; i = arr[i])
			answer++;
		answer++;
	}
	fin[target] = true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;

		for (int i = 1; i <= N; i++)
			cin >> arr[i];

		answer = 0;
		init(N);
		for (int i = 1; i <= N; i++)
		{
			if (!visit[i])
				dfs(i);
		}
		cout << N - answer << "\n";
	}
	return 0;
}