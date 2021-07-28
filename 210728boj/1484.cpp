/**
*	BOJ
*	No.1484	다이어트
*	@author	peter9378
*	@date		2021.07.28
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

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int G;
	cin >> G;

	vector<int> v, answer;
	for (int i = 1; i <= sqrt(G); i++)
	{
		if (G%i == 0)
		{
			if (G / i == i)
				continue;

			v.push_back(i);
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		int left = v[i];
		int right = G / left;
		if ((right + left) % 2 == 1)
			continue;
		answer.push_back((right + left) / 2);
	}

	sort(answer.begin(), answer.end());
	if (answer.empty())
		cout << -1;
	else
	{
		for (int i = 0; i < answer.size(); i++)
			cout << answer[i] << "\n";
	}

	return 0;
}
