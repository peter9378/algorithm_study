/**
*	BOJ
*	No.11438	LCA 2
*	@author	peter9378
*	@date		2019.12.13
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

#define MAX 100001

int maximum;
int depth[MAX];
int ancestor[MAX][22];
vector<int> arr[MAX];

void dfs(int child, int parent)
{
	depth[child] = depth[parent] + 1;
	ancestor[child][0] = parent;
	maximum = (int)floor(log2(MAX));

	for (int i = 0; i < maximum; i++)
		ancestor[child][i + 1] = ancestor[ancestor[child][i]][i];

	int length = arr[child].size();
	for (int i = 0; i < length; i++)
	{
		int temp = arr[child][i];
		if (temp != parent)
			dfs(temp, child);
	}
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	depth[0] = -1;
	dfs(1, 0);

	int M;
	cin >> M;

	while (M--)
	{
		int a, b;
		cin >> a >> b;

		if (depth[a] != depth[b])
		{
			if (depth[a] > depth[b])
				swap(a, b);

			for (int i = maximum; i > -1; i--)
			{
				if (depth[a] <= depth[ancestor[b][i]])
					b = ancestor[b][i];
			}
		}

		int answer = a;

		if (a != b)
		{
			for (int i = maximum; i > -1; i--)
			{
				if (ancestor[a][i] != ancestor[b][i])
				{
					a = ancestor[a][i];
					b = ancestor[b][i];
				}
				answer = ancestor[a][i];
			}
		}
		cout << answer << "\n";
	}

	return 0;
}
