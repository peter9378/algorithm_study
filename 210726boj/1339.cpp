/**
*	BOJ
*	No.1339	단어 수학
*	@author	peter9378
*	@date		2021.07.26
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

long long arr[27];
vector<long long> v;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		int temp = 1;
		for (int j = s.size() - 1; j >= 0; j--)
		{
			arr[s[j] - 'A'] += temp;
			temp *= 10;
		}
	}

	for (int i = 0; i < 27; i++)
	{
		if (arr[i] != 0)
			v.push_back(arr[i]);
	}

	sort(v.begin(), v.end());

	int temp = 9;
	long long answer = 0;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		answer += v[i] * temp;
		temp--;
	}

	cout << answer;

	return 0;
}
