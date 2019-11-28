/**
*	BOJ
*	No.10973	이전 순열
*	@author	peter9378
*	@date		2019.11.28
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

using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	int i;
	for (i = N - 2; i >= 0; i--)
	{
		if (v[i] > v[i + 1])
			break;
	}

	if (i == -1)
		cout << -1;
	else
	{
		int maxi = -1;
		int index = -1;
		for (int j = i; j < N; j++)
		{
			if (v[j] < v[i] && v[j] < v[i])
			{
				maxi = v[j];
				index = j;
			}
		}
		swap(v[i], v[index]);
		sort(v.begin() + i + 1, v.end(), greater<int>());

		for (i = 0; i < v.size(); i++)
			cout << v[i] << " ";
	}

	return 0;
}
