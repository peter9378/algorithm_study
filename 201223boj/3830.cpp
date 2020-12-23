/**
*	BOJ
*	No.3830	교수님은 기다리지 않는다
*	@author	peter9378
*	@date		2020.12.23
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

int N, M;
int arr[100001];
long long dist[100001];

int update(int target)
{
	if (arr[target] == target)
		return target;

	int result = update(arr[target]);
	dist[target] += dist[arr[target]];
	return arr[target] = result;
}

void merge(int a, int b, int diff)
{
	int ar = arr[a];
	int br = arr[b];

	if (ar == br)
		return;

	arr[br] = ar;
	dist[br] = dist[a] + diff - dist[b];
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;

		for (int i = 1; i <= N; i++)
		{
			arr[i] = i;
			dist[i] = 0;
		}

		for (int i = 0; i < M; i++)
		{
			char c;
			int a, b, w;
			cin >> c >> a >> b;
			update(a);
			update(b);

			if (c == '!')
			{
				cin >> w;
				merge(a, b, w);
			}
			else
			{
				if (arr[a] == arr[b])
					cout << dist[b] - dist[a] << "\n";
				else
					cout << "UNKNOWN\n";
			}
		}
	}

	return 0;
}
