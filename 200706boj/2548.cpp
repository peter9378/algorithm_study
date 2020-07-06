/**
*	BOJ
*	No.2548	대표 자연수
*	@author	peter9378
*	@date		2020.07.06
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

	int N;
	cin >> N;

	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	if (N % 2)
		cout << v[N / 2];
	else
		cout << min(v[N / 2], v[N / 2 - 1]);

	return 0;
}