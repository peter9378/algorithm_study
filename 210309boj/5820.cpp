/**
*	BOJ
*	No.5820	∞Ê¡÷
*	@author	peter9378
*	@date		2021.03.09
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

int K, answer;
int arr[200002], kill[200002];
vector<vector<pair<int, int> > >v;
map<int, int> m;

int get_size(int current, int parent)
{
	arr[current] = 1;
	for (int i = 0; i < v[current].size(); i++)
	{
		int target = v[current][i].first;
		if (parent == target || kill[target])
			continue;
		arr[current] += get_size(target, current);
	}
	return arr[current];
}

int find_mid(int current, int parent, int diff)
{
	for (int i = 0; i < v[current].size(); i++)
	{
		int there = v[current][i].first;
		if (kill[there] || there == parent)
			continue;
		if (arr[there] > diff)
			return find_mid(there, current, diff);
	}
	return current;
}

void go(int current, int parent, int distance, int depth)
{
	if (distance > K)
		return;

	auto temp = m.find(K - distance);
	if (temp != m.end())
		answer = min(answer, temp->second + depth);

	for (int i = 0; i < v[current].size(); i++)
	{
		int there = v[current][i].first;
		int w = v[current][i].second;
		if (kill[there] || parent == there)
			continue;
		if (!kill[there] && there != parent)
			go(there, current, distance + w, depth + 1);
	}
}

void add(int current, int parent, int distance, int depth)
{
	if (distance > K)
		return;

	auto temp = m.find(distance);
	if (temp != m.end())
		temp->second = min(temp->second, depth);
	else
		m[distance] = depth;

	for (int i = 0; i < v[current].size(); i++)
	{
		int there = v[current][i].first;
		int w = v[current][i].second;

		if (kill[there] || there == parent)
			continue;
		add(there, current, distance + w, depth + 1);
	}
}

void dfs(int current)
{
	int diff = get_size(current, -1) / 2;
	int mid = find_mid(current, -1, diff);
	kill[mid] = 1;
	m.clear(); m[0] = 0;

	for (int i = 0; i < v[mid].size(); i++)
	{
		int there = v[mid][i].first;
		int w = v[mid][i].second;
		if (!kill[there])
		{
			go(there, mid, w, 1);
			add(there, mid, w, 1);
		}
	}

	for (int i = 0; i < v[mid].size(); i++)
	{
		int there = v[mid][i].first;
		if (!kill[there])
			dfs(there);
	}
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N >> K;

	answer = 1e9;
	v.resize(N + 1);

	for (int i = 0; i < N - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a++;
		b++;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	dfs(1);
	cout << (answer >= 1e9 ? -1 : answer);

	return 0;
}
