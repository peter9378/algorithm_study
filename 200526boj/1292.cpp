/**
*	BOJ
*	No.1292	쉽게 푸는 문제
*	@author	peter9378
*	@date		2020.05.26
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

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B;
	cin >> A >> B;

	vector<int> v;
	for (int i = 1; i < 100; i++)
	{
		for (int j = 1; j <= i; j++)
			v.push_back(i);
	}

	int answer = 0;
	for (int i = A - 1; i < B; i++)
		answer += v[i];

	cout << answer;

	return 0;
}