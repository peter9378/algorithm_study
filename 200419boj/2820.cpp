/**
*	BOJ
*	No.2820	자동차 공장
*	@author	peter9378
*	@date		2020.04.19
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

#define MAX 500005

int N, M, counting;
int num[MAX];
int team[MAX];
int cost[MAX];
int salary[MAX];

vector<int> arr[MAX];

void dfs(int target)
{
	num[target] = ++counting;
	for (int i : arr[target])
		dfs(i);
	team[target] = counting;
	return;
}

void update(int a, int b)
{
	for (; a <= N; a += a & -a)
		salary[a] += b;
	return;
}

int process(int a)
{
	int result = 0;
	for (; a; a -= a & -a)
		result += salary[a];
	return result;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> cost[1];

	for (int i = 2, a; i <= N; i++)
	{
		cin >> cost[i] >> a;
		arr[a].push_back(i);
	}

	dfs(1);

	for (int i = 1; i <= N; i++)
	{
		update(num[i], cost[i]);
		update(num[i] + 1, -cost[i]);
	}

	for (int i = 0, a, b; i < M; i++)
	{
		char c;
		cin >> c;
		if (c == 'p')
		{
			cin >> a >> b;
			update(num[a] + 1, b);
			update(team[a] + 1, -b);
		}
		else
		{
			cin >> a;
			cout << process(num[a]) << "\n";
		}
	}

	return 0;
}