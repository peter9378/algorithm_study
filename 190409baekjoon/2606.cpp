/**
*	baekjoon online judge
*	No. 2606	바이러스
*	@author	peter9378
*	@date		2019.04.09
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> arr;
bool visit[101];
int computer, answer;


void dfs(int x)
{
	answer++;
	visit[x] = true;

	for (int i = 0; i < arr[x].size(); i++)
	{
		if (!visit[arr[x][i]])
			dfs(arr[x][i]);
	}
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int N;
	cin >> computer >> N;
	arr.resize(computer + 1);

	for (int i = 0; i < N; i++)
	{
		int from, to;
		cin >> from >> to;

		arr[from].push_back(to);
		arr[to].push_back(from);
	}

	dfs(1);

	// print answer
	cout << answer - 1;

	return 0;
}