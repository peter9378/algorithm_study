/**
*	BOJ
*	No.7567	±×¸©
*	@author	peter9378
*	@date		2020.05.14
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

	string s;
	cin >> s;

	stack<char> stk;
	stk.push(s[0]);

	int answer = 10;
	for (int i = 1; i < s.length(); i++)
	{
		if (stk.top() == s[i])
			answer += 5;
		else
			answer += 10;
		stk.push(s[i]);
	}

	cout << answer;

	return 0;
}