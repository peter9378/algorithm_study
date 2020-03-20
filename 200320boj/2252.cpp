/**
*	BOJ
*	No.2252	줄 세우기
*	@author	peter9378
*	@date		2020.03.20
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

	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		arr[B]++;
		v[A].push_back(B);
	}

	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		if (!arr[i])
			q.push(i);
	}

	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		cout << current << " ";

		for (int i = 0; i < v[current].size(); i++)
		{
			if (--arr[v[current][i]] == 0)
				q.push(v[current][i]);
		}
	}

	return 0;
}