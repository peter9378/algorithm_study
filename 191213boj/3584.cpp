/**
*	BOJ
*	No.3584	가장 가까운 공통 조상
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
int parent[MAX];

void init(int n)
{
	for (int i = 0; i <= n; i++)
	{
		depth[i] = 0;
		parent[i] = 0;
		arr[i].clear();
		for (int j = 0; j < 22; j++)
			ancestor[i][j] = 0;
	}
}

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

	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;

		init(N);

		for (int i = 1; i < N; i++)
		{
			int a, b;
			cin >> a >> b;
			arr[a].push_back(b);
			arr[b].push_back(a);
			parent[b] = a;
		}

		int root;
		for (int i = 1; i <= N; i++)
		{
			if (!parent[i])
			{
				root = i;
				break;
			}
		}

		depth[0] = -1;
		dfs(root, 0);

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
