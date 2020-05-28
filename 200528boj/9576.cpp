/**
*	BOJ
*	No.9576	Ã¥ ³ª´²ÁÖ±â
*	@author	peter9378
*	@date		2020.05.28
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

bool visit[1001];

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		for (int i = 0; i < 1001; i++)
			visit[i] = false;

		int N, M;
		cin >> N >> M;

		vector<pair<int, int>> v;
		for (int i = 0; i < M; i++)
		{
			int a, b;
			cin >> a >> b;
			v.push_back({ a, b });
		}

		sort(v.begin(), v.end(), compare);
		int answer = 0;
		for (int i = 0; i < M; i++)
		{
			for (int j = v[i].first; j <= v[i].second; j++)
			{
				if (!visit[j])
				{
					visit[j] = true;
					answer++;
					break;
				}
			}
		}

		cout << answer << "\n";
	}

	return 0;
}