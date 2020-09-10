/**
*	BOJ
*	No.1058	Ä£±¸
*	@author	peter9378
*	@date		2020.09.10
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

#define MOD 1000000000000000;
#define MAX_SIZE 500000;

int n;
char arr[55][55];
bool visit[55];

int bfs(int vertex) 
{
	memset(visit, 0, sizeof(visit));

	queue<pair<int, int> > q;

	q.push(make_pair(vertex, 0));
	visit[vertex] = 1;

	while (!q.empty()) 
	{
		int now = q.front().first;
		int breath = q.front().second;
		q.pop();

		if (breath == 2) break;

		for (int i = 0; i < n; i++)
		{
			if (arr[now][i] == 'Y' && !visit[i])
			{
				visit[i] = 1;
				q.push(make_pair(i, breath + 1));
			}
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++) 
		result += visit[i];

	return result - 1;
}

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	int answer = 0;
	for (int i = 0; i < n; i++)
		answer = max(answer, bfs(i));

	cout << answer;

	return 0;
}