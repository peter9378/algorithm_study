/**
*	BOJ
*	No.2399	거리의 합
*	@author	peter9378
*	@date		2020.01.28
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

	int N;
	cin >> N;

	vector<long long> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	long long answer = 0;
	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
		answer += (v[i] * (2 * i - N + 1));

	cout << answer * 2;

	return 0;
}
