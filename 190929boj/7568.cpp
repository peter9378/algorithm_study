/**
*	BOJ
*	No.7568	덩치
*	@author	peter9378
*	@date		2019.09.29
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	vector<int> answer;
	for (int i = 0; i < v.size(); i++)
	{
		int cnt = 1;
		for (int j = 0; j < v.size(); j++)
		{
			if (i == j)
				continue;
			if (v[i].first < v[j].first && v[i].second < v[j].second)
				cnt++;
		}
		answer.push_back(cnt);
	}

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";

	return 0;
}