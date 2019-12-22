/**
*	BOJ
*	No.15681	Æ®¸®¿Í Äõ¸®
*	@author	peter9378
*	@date		2019.12.23
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

int num[100001];
vector<int> arr[100001];

int dfs(int previous, int current)
{
	num[current] = 1;
	for (auto next : arr[current])
	{
		if (previous == next)
			continue;
		num[current] += dfs(current, next);
	}
	return num[current];
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, R, Q;
	cin >> N >> R >> Q;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	dfs(0, R);

	while (Q--)
	{
		int U;
		cin >> U;
		cout << num[U] << "\n";
	}

	return 0;
}