/**
*	BOJ
*	No.2188	축사 배정
*	@author	peter9378
*	@date		2020.09.12
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

vector<int> arr[202];
int home[202];
bool visit[202];

bool dfs(int target)
{
	if (visit[target])
		return false;
	visit[target] = true;

	for (int a : arr[target])
	{
		if (!home[a] || dfs(home[a]))
		{
			home[a] = target;
			return true;
		}
	}
	return false;
}

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		int a;
		cin >> a;
		while (a--)
		{
			int b;
			cin >> b;
			arr[i].push_back(b);
		}
	}

	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		memset(visit, false, sizeof(visit));
		if (dfs(i))
			answer++;
	}

	cout << answer;

	return 0;
}