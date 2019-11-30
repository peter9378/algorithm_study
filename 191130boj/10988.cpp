/**
*	BOJ
*	No.10988	팰린드롬인지 확인하기
*	@author	peter9378
*	@date		2019.11.30
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

using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	bool flag = false;
	for (int i = 0; i < s.length() / 2; i++)
	{
		if (s[i] != s[s.length() - i - 1])
		{
			flag = true;
			break;
		}
	}

	cout << !flag;

	return 0;
}
