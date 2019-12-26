/**
*	BOJ
*	No.1976	여행 가자
*	@author	peter9378
*	@date		2019.12.26
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

int N, M;
bool flag;
bool arr[202][202];
int route[1001];
bool check[202];

void dfs(int n)
{
	check[n] = true;
	for (int i = 1; i <= N; i++)
	{
		if (arr[n][i] && !check[i])
		{
			check[i] = true;
			dfs(i);
		}
	}
	return;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < M; i++)
		cin >> route[i];

	dfs(route[0]);

	for (int i = 1; i < M && !flag; i++)
	{
		if (!check[route[i]])
		{
			flag = true;
			break;
		}
	}

	if (flag)
		cout << "NO";
	else
		cout << "YES";

	return 0;
}
