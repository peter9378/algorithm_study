/**
*	BOJ
*	No.1516	게임 개발
*	@author	peter9378
*	@date		2021.02.11
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

int N;
int arr[505];
int ind[505];
int answer[505];

vector<int> v[505];

void bfs()
{
	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		if (ind[i] == 0)
		{
			q.push(i);
			answer[i] = arr[i];
		}
	}

	while (!q.empty())
	{
		int next = q.front();
		q.pop();

		for (int i = 0; i < v[next].size(); i++)
		{
			int e = v[next][i];
			answer[e] = max(answer[e], answer[next] + arr[e]);

			if (--ind[e] == 0)
				q.push(e);
		}
	}
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int temp;
		cin >> arr[i];

		while (cin >> temp, temp != -1)
		{
			v[temp].push_back(i);
			ind[i]++;
		}
	}

	bfs();

	for (int i = 1; i <= N; i++)
		cout << answer[i] << "\n";

	return 0;
}
