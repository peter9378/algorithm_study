/**
*	BOJ
*	No.1048	À¯´ÏÄÜ
*	@author	peter9378
*	@date		2020.12.25	Merry Christmas
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

int len(int x1, int x2, int y1, int y2)
{
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	scanf("%d", &n);

	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &v[i].first, &v[i].second);

	int min = 999999999;
	int mini = 0;

	for (int i = 0; i < n; i++)
	{
		int max = -1;
		int maxi = i;
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;

			if (max < len(v[i].first, v[j].first, v[i].second, v[j].second))
			{
				max = len(v[i].first, v[j].first, v[i].second, v[j].second);
				maxi = i;
			}
		}

		if (min > max)
		{
			min = max;
			mini = maxi;
		}
	}

	cout << v[mini].first << " " << v[mini].second << "\n";

	return 0;
}
