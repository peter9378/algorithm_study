/**
*	BOJ
*	No.1336	최고인 대장장이 토르비욘
*	@author	peter9378
*	@date		2021.01.10
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

vector<long> v;
vector < pair<long, long >> vv;
vector<long> graph[505050];
vector<long> tree;
bool visit[505050];

void compare()
{
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (auto &p : vv)
	{
		p.first = lower_bound(v.begin(), v.end(), p.first) - v.begin();
		p.second = lower_bound(v.begin(), v.end(), p.second) - v.begin();

		graph[p.first].push_back(p.second);
		graph[p.second].push_back(p.first);
	}
}

void dfs(int target)
{
	tree.push_back(target);
	visit[target] = true;

	for (auto a : graph[target])
	{
		if (!visit[a])
			dfs(a);
	}
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;

		v.push_back(a);
		v.push_back(b);
		vv.push_back({ a, b });
	}

	compare();

	int vs = v.size();
	long long answer = 0;
	for (int i = 0; i < vs; i++)
	{
		if (visit[i])
			continue;

		dfs(i);

		int temp = 0;
		for (auto a : tree)
			temp += graph[a].size();

		temp /= 2;

		for (auto a : tree)
			answer += v[a] * (graph[a].size() - 1);

		if (tree.size() > temp)
			answer += v[*max_element(tree.begin(), tree.end())];

		tree.clear();
	}

	cout << answer;

	return 0;
}
