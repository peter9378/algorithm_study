/**
*	BOJ
*	No.3090	차이를 최소로
*	@author	peter9378
*	@date		2021.06.23
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

long long N, T;
vector<int> v;

bool chk(int target)
{
	long long cnt = 0;
	vector<int> arr;

	for (auto i : v)
		arr.push_back(i);

	for (int i = 1; i < N; i++)
	{
		if (arr[i - 1] + target < arr[i])
		{
			cnt += arr[i] - (arr[i - 1] + target);
			arr[i] = arr[i - 1] + target;
		}

		if (cnt > T)
			return false;
	}

	for (int i = N - 1; i > 0; i--)
	{
		if (arr[i] + target < arr[i - 1])
		{
			cnt += arr[i - 1] - (arr[i] + target);
			arr[i - 1] = arr[i] + target;
		}

		if (cnt > T)
			return false;
	}
	return true;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> T;
	v.resize(N);
	int left = 0, right = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
		right = max(right, v[i]);
	}

	int mid;
	for (int i = 0; i < 500; i++)
	{
		mid = (left + right) >> 1;
		if (chk(mid))
			right = mid;
		else
			left = mid;
	}


	vector<int> vv;
	for (auto i : v)
		vv.push_back(i);

	for (int i = 1; i < N; i++)
	{
		if (vv[i - 1] + right < vv[i])
			vv[i] = vv[i - 1] + right;
	}

	for (int i = N - 1; i > 0; i--)
	{
		if (vv[i] + right < vv[i - 1])
			vv[i - 1] = vv[i] + right;
	}

	for (auto i : vv)
		cout << i << " ";

	return 0;
}
