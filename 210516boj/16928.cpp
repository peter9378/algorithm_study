/**
*	BOJ
*	No.16928	뱀과 사다리 게임
*	@author	peter9378
*	@date		2021.05.16
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

int arr[101];
int d[101];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		int a, b;
		cin >> a >> b;
		arr[a] = b;
	}

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		arr[a] = b;
	}

	queue<int> q;
	memset(d, -1, sizeof(d));
	q.push(1);
	d[1] = 0;
	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		for (int i = 1; i <= 6; ++i)
		{
			int next = current + i;
			if (next > 100)
				continue;

			if (arr[next] != 0)
				next = arr[next];

			if (d[next] == -1)
			{
				d[next] = d[current] + 1;
				q.push(next);
			}
		}
	}

	cout << d[100];

	return 0;
}
