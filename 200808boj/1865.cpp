/**
*	BOJ
*	No.1865	¿úÈ¦
*	@author	peter9378
*	@date		2020.08.08
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

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		int N, M, W;
		cin >> N >> M >> W;
		vector<vector<pair<int, int>>> arr(N + 1);

		vector<int> v(N + 1, 987654321);
		v[1] = 0;

		for (int i = 0; i < M; i++)
		{
			int from, to, weight;
			cin >> from >> to >> weight;
			arr.at(from).push_back({ to , weight });
			arr.at(to).push_back({ from , weight });
		}

		for (int i = 0; i < W; i++)
		{
			int from, to, weight;
			cin >> from >> to >> weight;
			arr.at(from).push_back({ to , -weight });
		}

		int answer = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				for (int k = 0; k < arr[j].size(); k++)
				{
					int from = j;
					int to = arr[j][k].first;
					int weight = arr[j][k].second;

					if (v[from] + weight < v[to])
					{
						v[to] = v[from] + weight;
						if (i == N)
							answer = 1;
					}
				}
			}
		}

		cout << (answer ? "YES\n" : "NO\n");
	}

	return 0;
}