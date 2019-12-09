/**
*	BOJ
*	No.11403	경로 찾기
*	@author	peter9378
*	@date		2019.12.09
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

int N;
bool arr[101][101];
bool check[101];
bool answer[101][101];

void bfs(int target)
{
	queue<int> q;
	q.push(target);
	for (int i = 0; i < N; i++)
		check[i] = false;

	while (!q.empty())
	{
		int next = q.front();
		q.pop();

		for (int i = 0; i < N; i++)
		{
			if (arr[next][i] && !check[i])
			{
				q.push(i);
				check[i] = true;
				answer[target][i] = true;
			}
		}
	}
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < N; i++)
		bfs(i);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << answer[i][j] << " ";
		cout << "\n";
	}


	return 0;
}