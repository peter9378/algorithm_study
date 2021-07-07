/**
*	BOJ
*	No.1671	상어의 저녁식사
*	@author	peter9378
*	@date		2021.07.07
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

struct Node {
	int a, b, c;
};

vector<int> g[111];
vector<Node> v;

int par[111];
int check[111];

int compare(Node a, Node b)
{
	int cnt = 0;
	if (a.a < b.a)
		return 0;
	else if (a.a == b.a)
		cnt++;

	if (a.b < b.b)
		return 0;
	else if (a.b == b.b)
		cnt++;

	if (a.c < b.c)
		return 0;
	else if (a.c == b.c)
		cnt++;

	if (cnt == 3)
		return 2;
	return 1;
}

bool dfs(int target)
{
	for (auto a : g[target])
	{
		if (check[a])
			continue;

		check[a] = 1;
		if (par[a] == -1 || dfs(par[a]))
		{
			par[a] = target;
			return true;
		}
	}
	return false;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	v.resize(N);
	for (auto &vv : v)
		cin >> vv.a >> vv.b >> vv.c;

	int temp = 50;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int res = compare(v[i], v[j]);
			if (!res)
				continue;
			if (res == 1)
				g[i].push_back(j + temp);
			else if (res == 2 && i < j)
				g[i].push_back(j + temp);
		}
	}

	memset(par, -1, sizeof par);
	for (int i = 0; i < N; i++)
	{
		memset(check, 0, sizeof check);
		dfs(i);
		memset(check, 0, sizeof check);
		dfs(i);
	}

	int answer = 0;
	for (int i = temp + 0; i < temp + N; i++)
		answer += par[i] == -1;
	cout << answer;

	return 0;
}
