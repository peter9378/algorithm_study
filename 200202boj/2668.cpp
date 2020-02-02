/**
*	BOJ
*	No.2668	숫자고르기
*	@author	peter9378
*	@date		2020.02.02
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

int N, answer;
int arr[101];
bool visit[101];
bool check[101];

bool dfs(int start, int index)
{
	if (visit[index])
		return false;

	visit[index] = true;

	if (start == index || dfs(start, arr[index]))
	{
		answer++;
		check[index] = true;
		return true;
	}
	return false;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			visit[j] = check[j];
		dfs(i, arr[i]);
	}

	cout << answer << "\n";

	for (int i = 1; i <= N; i++)
	{
		if (check[i])
			cout << i << "\n";
	}

	return 0;
}
