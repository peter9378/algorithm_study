/**
*	BOJ
*	No.16287	Parcel
*	@author	peter9378
*	@date		2020.09.04
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

int arr[5005];
int we[800008];

bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int w, n;
	cin >> w >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] + arr[j] > w)
				continue;
			if (we[w - arr[i] - arr[j]])
			{
				cout << "YES";
				return 0;
			}
		}

		for (int j = 0; j < i; j++)
		{
			if (arr[i] + arr[j] < w)
				we[arr[i] + arr[j]] = 1;
		}
	}

	cout << "NO";

	return 0;
}