/**
*	BOJ
*	No.1647	도시 분할 계획
*	@author	peter9378
*	@date		2021.07.31
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

#define MAX 100001

int answer = 0;
int temp = 0;
vector<pair<int, int>> v[MAX];
bool visit[MAX];

void prim()
{
	priority_queue <pair<int, int>> pq;
	for (int i = 0; i < v[1].size(); i++)
	{
		int position = v[1][i].first;
		int cost = v[1][i].second;

		pq.push({ -1 * cost, position });
	}

	visit[1] = true;

	while (!pq.empty())
	{
		int cost = pq.top().first * -1;
		int position = pq.top().second;
		pq.pop();

		if (!visit[position])
		{
			visit[position] = true;
			answer += cost;

			temp = max(temp, cost);
			for (int i = 0; i < v[position].size(); i++)
			{
				int next_position = v[position][i].first;
				int next_cost = v[position][i].second;

				if (!visit[next_position])
					pq.push({ -1 * next_cost, next_position });
			}
		}
	}
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;

		v[A].push_back(make_pair(B, C));
		v[B].push_back(make_pair(A, C));
	}

	prim();
	cout << answer - temp;

	return 0;
}
