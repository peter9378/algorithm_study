/**
*	BOJ
*	No.18512	점프 점프
*	@author	peter9378
*	@date		2020.03.05
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
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int X, Y, P1, P2;
	cin >> X >> Y >> P1 >> P2;

	set<int> s1;
	set<int> s2;

	for (int i = 0; i < 1000; i++)
	{
		s1.insert(P1 + X * i);
		s2.insert(P2 + Y * i);
	}

	set<int> result;
	set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(result, result.begin()));

	if (result.empty())
		cout << -1;
	else
		cout << *result.begin();

	return 0;
}