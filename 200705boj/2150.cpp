/**
*	BOJ
*	No.2150	Strongly Connected Component
*	@author	peter9378
*	@date		2020.07.05
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

bool visit[10001];
stack<int> stk;
vector<int> v[10001];
vector<int> rev[10001];
vector<int> answer[10001];

void dfs(int start)
{
	visit[start] = true;
	for (auto i : v[start])
	{
		if (!visit[i])
			dfs(i);
	}
	stk.push(start);
	return;
}

void rdfs(int start, int target)
{
	visit[start] = true;
	answer[target].push_back(start);
	for (auto i : rev[start])
	{
		if (!visit[i])
			rdfs(i, target);
	}
	return;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, T;
	cin >> N >> T;

	for (int i = 0; i < T; i++)
	{
		int A, B;
		cin >> A >> B;
		v[A].push_back(B);
		rev[B].push_back(A);
	}

	for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
			dfs(i);
	}

	memset(visit, 0, sizeof(visit));

	int cnt = 0;
	while (!stk.empty())
	{
		int current = stk.top();
		stk.pop();
		if (visit[current])
			continue;
		rdfs(current, cnt++);
	}

	vector<pair<int, int>> p;
	cout << cnt << "\n";
	for (int i = 0; i < cnt; i++)
	{
		sort(answer[i].begin(), answer[i].end());
		p.push_back({ answer[i][0], i });
	}
	sort(p.begin(), p.end());
	for (auto i : p)
	{
		for (auto j : answer[i.second])
			cout << j << " ";
		cout << "-1\n";
	}

	return 0;
}