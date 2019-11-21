/**
*	BOJ
*	No.1918	후위 연산자
*	@author	peter9378
*	@date		2019.11.21
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

using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	stack<char> stk;
	string answer = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			answer += s[i];
		else
		{
			if (s[i] == '(')
				stk.push(s[i]);
			else if (s[i] == ')')
			{
				while (stk.top() != '(')
				{
					answer += stk.top();
					stk.pop();
				}
				stk.pop();
			}
			else if (s[i] == '*' || s[i] == '/')
			{
				while (!stk.empty() && (stk.top() == '*' || stk.top() == '/'))
				{
					answer += stk.top();
					stk.pop();
				}
				stk.push(s[i]);
			}
			else
			{
				while (!stk.empty() && stk.top() != '(')
				{
					answer += stk.top();
					stk.pop();
				}
				stk.push(s[i]);
			}
		}
	}

	while (!stk.empty())
	{
		answer += stk.top();
		stk.pop();
	}
	cout << answer;

	return 0;
}
