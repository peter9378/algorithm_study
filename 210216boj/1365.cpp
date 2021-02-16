/**
*	BOJ
*	No.1365	≤ø¿Œ ¿¸±Í¡Ÿ
*	@author	peter9378
*	@date		2021.02.16
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

int lower_bound(vector<int> v, int target)
{
	int left = 0, right = v.size() - 1;

	while (left < right)
	{
		int mid = (left + right) / 2;
		if (v[mid] >= target)
			right = mid;
		else
			left = mid + 1;
	}
	return right;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> v;
	v.push_back(-1);

	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		if (temp > v[v.size() - 1])
			v.push_back(temp);
		else
			v[lower_bound(v, temp)] = temp;
	}

	cout << N - v.size() + 1;

	return 0;
}
