/**
*	BOJ
*	No.12987	노트북의 주인을 찾아서
*	@author	peter9378
*	@date		2020.09.03
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

int N, M;
vector<int> v[111];
bool visit[111];
int want[111];

bool go(int target)
{
	for (int i = 0; i < v[target].size(); i++)
	{
		int idx = v[target][i];
		if (visit[idx])
			continue;
		visit[idx] = true;

		if (!want[idx] || go(want[idx]))
		{
			want[idx] = target;
			return true;
		}
	}
	return false;
}

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int owner, laptop;
		cin >> owner >> laptop;
		v[owner].push_back(laptop);
	}

	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		memset(visit, false, sizeof(visit));
		if (go(i))
			answer++;
	}

	cout << answer;

	return 0;
}