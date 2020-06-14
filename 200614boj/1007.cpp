/**
*	BOJ
*	No.1007	º¤ÅÍ ¸ÅÄª
*	@author	peter9378
*	@date		2020.06.14
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

long long arr[101];
unordered_set<long long> visit;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	pair <long long, long long> arr[33];
	cout.precision(10);
	while (T--)
	{
		int N;
		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> arr[i].first >> arr[i].second;

		long long answer = 0x7fffffffffffffffLL;
		vector<int> v(N);
		fill(v.begin() + N / 2, v.end(), 1);

		do {
			pair<long long, long long> temp = { 0, 0 };

			for (int i = 0; i < N; i++)
			{
				if (v[i])
				{
					temp.first += arr[i].first;
					temp.second += arr[i].second;
				}
				else
				{
					temp.first -= arr[i].first;
					temp.second -= arr[i].second;
				}
			}
			answer = min(answer, temp.first*temp.first + temp.second*temp.second);
		} while (next_permutation(v.begin(), v.end()));

		cout << fixed << sqrt((double)answer) << "\n";
	}

	return 0;
}