/**
*	BOJ
*	No.18251	내 생각에 A번인 단순 dfs 문제가 이 대회에서 E번이 되어버린 건에 관하여 (Easy)
*	@author	peter9378
*	@date		2020.08.02
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
using namespace std;

struct s {
	long long a, b, c;

	bool operator < (const s &target) const
	{
		if (a != target.a)
			return a < target.a;
		return b < target.b;
	}
};

int N, idx = 0;
int arr[266000];
int id[266000];
vector<s> v;

void dfs(int from, int to)
{
	if (from * 2 <= N)
		dfs(from * 2, to + 1);

	id[from] = idx;
	v.push_back({ to, idx++, 0 });

	if (from * 2 + 1 <= N)
		dfs(from * 2 + 1, to + 1);
	return;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	dfs(1, 0);

	long long answer = -1e9;
	for (int i = 1; i <= N; i++)
	{
		long long temp;
		cin >> temp;

		v[id[i]].c = temp;
		answer = max(answer, temp);
	}

	if (answer > 0)
	{
		answer = 0;
		for (int i = 0; i < 20; i++)
		{
			for (int j = i; j < 20; j++)
			{
				long long current = 0, maxi = 0;
				for (int k = 0; k < N; k++)
				{
					if (v[k].a < i || v[k].a > j)
						continue;

					current = max(0LL, current + v[k].c);
					maxi = max(maxi, current);
				}
				answer = max(answer, maxi);
			}
		}
	}
	cout << answer;

	return 0;
}