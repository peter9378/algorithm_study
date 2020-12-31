/**
*	BOJ
*	No.11725	트리의 부모 찾기
*	@author	peter9378
*	@date		2020.12.31	Farewell 2020
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

#define MAX 100001

int N;
bool visit[MAX];
int parent[MAX];
vector<int> tree[MAX];

void go(int target)
{
	visit[target] = true;

	for (int i = 0; i < tree[target].size(); i++)
	{
		int next = tree[target][i];

		if (!visit[next])
		{
			parent[next] = target;
			go(next);
		}
	}
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	go(1);

	for (int i = 2; i <= N; i++)
		cout << parent[i] << "\n";

	return 0;
}
