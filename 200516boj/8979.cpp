/**
*	BOJ
*	No.8979	¿Ã¸²ÇÈ
*	@author	peter9378
*	@date		2020.05.16
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

struct country {
	vector<int> num;
	int gold, silver, bronze;
};

bool compare(const country& a, const country& b)
{
	if (a.gold == b.gold)
	{
		if (a.silver == b.silver)
		{
			return a.bronze > b.bronze;
		}
		return a.silver > b.silver;
	}
	return a.gold > b.gold;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<country> v;
	for (int i = 0; i < N; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		bool flag = true;
		for (int j = 0; j < v.size(); j++)
		{
			if (v[j].gold == b && v[j].silver == c && v[j].bronze == d)
			{
				v[j].num.push_back(a);
				flag = false;
				break;
			}
		}
		if (flag)
		{
			vector<int> temp;
			temp.push_back(a);
			v.push_back({ temp, b, c, d });
		}
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].num.size(); j++)
		{
			if (v[i].num[j] == K)
			{
				int temp = 0;
				for (int k = 0; k < i; k++)
					temp += (v[k].num.size() - 1);
				cout << i + 1 + temp;
				break;
			}
		}
	}

	return 0;
}