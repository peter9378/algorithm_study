/**
*	BOJ
*	No.18138	리유나는 세일러복을 좋아해
*	@author	peter9378
*	@date		2020.7.29
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

int N, M;
vector<vector<int>> arr;
int am[1001], bm[1001];
bool visit[1001];

bool dfs(int target)
{
	if (visit[target])
		return false;

	visit[target] = true;
	for (auto ar : arr[target])
	{
		if (am[ar] == -1 || dfs(am[ar]))
		{
			am[ar] = target;
			bm[target] = ar;
			return true;
		}
	}
	return false;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	vector<int> a(N), b(M);

	for (int i = 0; i < N; i++)
		cin >> a[i];
	for (int i = 0; i < M; i++)
		cin >> b[i];

	arr.resize(M);
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (((double)b[i] >= (double)a[j] * (0.5) && (double)b[i] <= (double)a[j] * (0.75)) || (b[i] >= a[j] && (double)b[i] <= (double)a[j] * (1.25)))
				arr[i].push_back(j);
		}
	}

	for (int i = 0; i < N; i++)
		am[i] = -1;
	for (int i = 0; i < M; i++)
		bm[i] = -1;

	int answer = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < 1001; j++)
			visit[j] = false;
		if (dfs(i))
			answer++;
	}

	cout << answer;

	return 0;
}