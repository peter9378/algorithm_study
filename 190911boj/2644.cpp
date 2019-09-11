/**
*	BOJ
*	No.2644	촌수계산	이항 계수1
*	@author	peter9378
*	@date		2019.09.11
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M, a, b;
vector<int> chon[101];
int check[101];

int bfs()
{
	queue<int> q;
	q.push(a);

	while (!q.empty())
	{
		int temp = q.front();
		q.pop();

		if (temp == b)
			return check[b];

		for (int i = 0; i < chon[temp].size(); i++)
		{
			int n = chon[temp][i];
			if (check[n] == 0)
			{
				q.push(n);
				check[n] = check[temp] + 1;
			}
		}
	}
	return -1;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	cin >> a >> b;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int parent, child;
		cin >> parent >> child;
		chon[parent].push_back(child);
		chon[child].push_back(parent);
	}

	cout << bfs();

	return 0;
}
