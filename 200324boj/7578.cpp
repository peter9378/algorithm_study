/**
*	BOJ
*	No.7578	공장
*	@author	peter9378
*	@date		2020.03.24
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

int N;
int arr[500005];

void update(int target)
{
	while (target <= N)
	{
		arr[target] += 1;
		target += (target&-target);
	}
	return;
}

long long check(int target)
{
	long long result = 0;
	while (target > 0)
	{
		result += arr[target];
		target -= (target&-target);
	}
	return result;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	map<int, int> m;
	for (int i = 1; i <= N; i++)
	{
		int a;
		cin >> a;
		m[a] = i;
	}

	long long answer = 0;
	for (int i = 0; i < N; i++)
	{
		answer += check(N) - check(m[v[i]]);
		update(m[v[i]]);
	}

	cout << answer;

	return 0;
}