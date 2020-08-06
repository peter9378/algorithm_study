/**
*	BOJ
*	No.12851	¼û¹Ù²ÀÁú 2
*	@author	peter9378
*	@date		2020.08.07
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

int answer, mini;
bool visit[100001];

int dfs(int a, int b)
{
	queue<pair<int, int>> q;
	q.push({ a, 0 });
	visit[a] = true;

	while (!q.empty())
	{
		int first = q.front().first;
		int second = q.front().second;
		q.pop();

		visit[first] = true;
		if (mini && mini == second && first == b)
			answer++;
		if (!mini && first == b)
		{
			mini = second;
			answer++;
		}

		if (first < 100000 && !visit[first + 1])
			q.push({ first + 1, second + 1 });
		if (first >= 1 && !visit[first - 1])
			q.push({ first - 1, second + 1 });
		if (first * 2 < 100001 && !visit[first * 2])
			q.push({ first * 2, second + 1 });
	}

	return mini;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;
	cout << dfs(N, K) << "\n" << answer;

	return 0;
}