/**
*	BOJ
*	No.1325	효율적인 해킹
*	@author	peter9378
*	@date		2020.01.18
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

int N, M, maxi = 0;
vector<int> arr[10001];
int hack[10001];
bool visit[10001];

void dfs(int target)
{
	visit[target] = true;

	for (int i = 0; i < arr[target].size(); i++)
	{
		int next = arr[target][i];
		if (!visit[next])
		{
			maxi++;
			dfs(next);
		}
	}
	return;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[b].push_back(a);
	}

	int count = 0;
	vector<int> answer;
	for (int i = 1; i <= N; i++)
	{
		for (int i = 0; i < 10001; i++)
			visit[i] = false;

		maxi = 0;
		dfs(i);

		if (count == maxi)
			answer.push_back(i);
		else if (count < maxi)
		{
			count = maxi;
			answer.clear();
			answer.push_back(i);
		}
	}

	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";

	return 0;
}
