/**
*	BOJ
*	No.1235	학생 번호
*	@author	peter9378
*	@date		2021.07.19
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

string arr[1005];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		reverse(arr[i].begin(), arr[i].end());
	}

	long long answer = 1;
	while (true)
	{
		map<string, long long> m;
		long long check = 1;

		for (int i = 0; i < N; i++)
		{
			if (m.find(arr[i].substr(0, answer)) != m.end())
			{
				check = 0;
				break;
			}

			m[arr[i].substr(0, answer)] = 1;
		}

		if (check)
			break;

		answer++;
	}

	cout << answer;

	return 0;
}
