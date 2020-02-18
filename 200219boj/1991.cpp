/**
*	BOJ
*	No.1911	트리 순회
*	@author	peter9378
*	@date		2020.02.19
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

vector<pair<int, bool>> tree[33];

void pre(int node)
{
	cout << char(node + 'A');
	for (int i = 0; i < tree[node].size(); i++)
		pre(tree[node][i].first);
}

void post(int node)
{
	for (int i = 0; i < tree[node].size(); i++)
		post(tree[node][i].first);

	cout << char(node + 'A');
	return;
}

void in(int node)
{
	if (tree[node].size() && tree[node][0].second)
		in(tree[node][0].first);

	cout << char(node + 'A');

	if (tree[node].size() && !tree[node][0].second)
		in(tree[node][0].first);
	else if (tree[node].size() == 2)
		in(tree[node][1].first);
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
		char a, b, c;
		cin >> a >> b >> c;

		if (b != '.')
			tree[a - 'A'].push_back({ b - 'A', true });
		if (c != '.')
			tree[a - 'A'].push_back({ c - 'A', false });
	}



	pre(0);
	cout << "\n";

	in(0);
	cout << "\n";

	post(0);
	cout << "\n";

	return 0;
}
