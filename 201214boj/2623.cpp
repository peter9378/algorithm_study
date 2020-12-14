/**
*	BOJ
*	No.2623	음악프로그램
*	@author	peter9378
*	@date		2020.12.14
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

int N, M;
int arr[1001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	vector<vector<int>> vec(N + 1);

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		for (int j = 1; j < a; j++)
		{
			int c;
			cin >> c;
			vec[b].push_back(c);
			arr[c]++;
			b = c;
		}
	}

	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		if (!arr[i])
			q.push(i);
	}

	vector<int> ans;
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		ans.push_back(t);

		for (auto next : vec[t])
		{
			arr[next]--;
			if (!arr[next])
				q.push(next);
		}
	}

	if (ans.size() != N)
	{
		printf("0");
		return 0;
	}

	for (auto a : ans)
		printf("%d\n", a);

	return 0;
}
