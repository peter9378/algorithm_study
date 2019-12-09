/**
*	BOJ
*	No.1041	¡÷ªÁ¿ß
*	@author	peter9378
*	@date		2019.12.09
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
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long N;
	cin >> N;

	vector<int> v(6);
	for (int i = 0; i < 6; i++)
		cin >> v[i];

	long long answer = 0;
	if (N == 1)
	{
		sort(v.begin(), v.end());
		for (int i = 0; i < 5; i++)
			answer += v[i];
	}
	else
	{
		vector<int> use;
		use.push_back(min(v[0], v[5]));
		use.push_back(min(v[1], v[4]));
		use.push_back(min(v[2], v[3]));

		sort(use.begin(), use.end());

		answer += use[0] * N*(N - 1) * 4;
		answer += use[0] * (N - 2)*(N - 2);
		answer += use[1] * N * 4;
		answer += use[1] * (N - 2) * 4;
		answer += use[2] * 4;
	}
	cout << answer;

	return 0;
}