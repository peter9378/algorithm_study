/**
*	BOJ
*	No.1766	¹®Á¦Áý
*	@author	peter9378
*	@date		2020.04.09
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
#include <iterator>
#include <numeric>
using namespace std;

int arr[32323];
vector<int> v[32323];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[b]++;
		v[a].push_back(b);
	}

	for (int i = 1; i <= N; i++)
	{
		if (!arr[i])
			pq.push(i);
	}

	while (!pq.empty())
	{
		int current = pq.top();
		pq.pop();

		cout << current << " ";

		for (int i = 0; i < v[current].size(); i++)
		{
			int next = v[current][i];
			if (--arr[next] == 0)
				pq.push(next);
		}
	}

	return 0;
}