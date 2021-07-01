/**
*	BOJ
*	No.1916	최소비용 구하기
*	@author	peter9378
*	@date		2021.07.01
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

int arr[1001];
vector<pair<int, int>> v[100001];

void go(int start)
{
	arr[start] = 0;

	priority_queue<pair<int, int>>pq;
	pq.push({ arr[start] , start });

	while (!pq.empty())
	{
		int current = pq.top().second;
		int distance = pq.top().first * -1;
		pq.pop();

		if (arr[current] < distance)
			continue;

		for (int i = 0; i < v[current].size(); i++)
		{
			int next = v[current][i].first;
			int nextd = distance + v[current][i].second;

			if (nextd < arr[next])
			{
				arr[next] = nextd;
				pq.push({ nextd * -1 , next });
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

	for (int i = 1; i <= N; i++)
		arr[i] = 987654321;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		v[a].push_back({ b,c });
	}

	int start, end;
	cin >> start;
	cin >> end;

	go(start);

	cout << arr[end];

	return 0;
}
