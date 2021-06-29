/**
*	BOJ
*	No.2569	ÁüÁ¤¸®
*	@author	peter9378
*	@date		2021.06.29
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

bool check[1001];
pair<int, int> arr[1001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		arr[i].second = i;
		cin >> arr[i].first;
	}

	sort(arr, arr + n);
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		if (check[i])
			continue;

		int temp = 0;
		for (int j = i; !check[j]; j = arr[j].second)
		{
			check[j] = true;
			answer += arr[j].first;
			temp++;
		}

		answer += min(arr[0].first*(temp + 1) + arr[i].first, arr[i].first*(temp - 2));
	}

	cout << answer;

	return 0;
}
